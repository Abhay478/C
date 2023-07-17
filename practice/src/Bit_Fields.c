
#include "my_header.h"

struct prog_lang{
    K : 2;
    K C : 1;
    K Java : 1;
    K Python : 1;
    K Cpp : 1;
    K Go : 1;
    K : 2;
};
struct h_lang{
    K : 2;
    K Eng : 1;
    K Hin : 1;
    K Kan : 1;
    K Frn : 1;
    K Esp : 1;
    K : 2;
};
struct Exp{
    K : 2;
    K company_id : 14;
    K yrs : 6;
    K : 2;
};
struct Name{
    char fname[10];
    char mname[10];
    char lname[10];
};
struct Fellow{
    K : 2;
    K prog : 3;
    struct Name name[32];
    struct prog_lang pl;
    K ling : 3;
    struct h_lang hl;
    K fresher : 1;
    struct Exp *arr;
    K : 2;
};
int checkProgLang(struct Fellow * f);
int checkSpokLang(struct Fellow * f);
int checkExperience(struct Fellow * f);
int put_in_file(struct Fellow Array[], FILE * fp);

struct set_args {
    K onedot : 3;
    K twodot : 1; 
} arg;

struct set_args set(char * var)
{
    printf("%s : ", var);
    char resp[4];
    scanf("%s", resp);
    int c;
    if(!strcmp(resp, "yes"))
        c = 'y';
    else   
        c = 'n';
    switch(c){
        case 'y' : 
            arg.twodot = 1;
            (arg.onedot)++;
        break;
        case 'n' :
            arg.twodot = 0;
        break;
        
    }
    return arg;
}

FILE *flp = NULL;
int main()
{
    struct Fellow list[32];
    for(int i = 0; i < 1; i++){
        printf("Enter name.\n");
        scanf("%s %s %s", list[i].name->fname, list[i].name->mname, list[i].name->lname);
        
        checkProgLang(list + i);
        checkSpokLang(list + i);
        checkExperience(list + i);
    }

    flp = fopen("Applicants.txt", "w+");
    put_in_file(list, flp);
    fclose(flp);
    return 0;
}

int checkProgLang(struct Fellow *f){
        printf("Enter yes for languages known, no for unknown.\n");

        set("C");
        f->pl.C = arg.twodot;
       
        set("Java");
        f->pl.Java = arg.twodot;
        
        set("C++");
        f->pl.Cpp = arg.twodot;
        
        set("Python");
        f->pl.Python = arg.twodot;
        
        set("Go");
        f->pl.Go = arg.twodot;

        f->prog = arg.onedot;
        arg.onedot = 0;

        return 0;
}
        
        
        
int checkSpokLang(struct Fellow * f){
    printf("Enter yes if language is known, no otherwise.\n");
    
    set("English");
    f->hl.Eng = arg.twodot;
    
    set("Hindi");
    f->hl.Hin = arg.twodot;
    
    set("Kannada");
    f->hl.Kan = arg.twodot;
    
    set("Spanish");
    f->hl.Esp = arg.twodot;
    
    set("French");
    f->hl.Frn = arg.twodot;

    return 0;
}

int checkExperience(struct Fellow * f)
{
    
    set("Prior Experience status");
    f->fresher = arg.twodot;
    arg.onedot = 0;

    if(f->fresher)
        return 1;

    int i;

    f->arr = (struct Exp *)malloc(sizeof(struct Exp));
    printf("Enter # to terminate.\n");
    for(i = 0; getchar() != '#'; i++){
        int a = *(int *)Get("Company ID", "int");
        f->arr[i].company_id = a;
        a = *(int *)Get("Years worked", "int");
        f->arr[i].yrs = a;
        f->arr = (struct Exp *)realloc(f->arr, (i+1)*sizeof(struct Exp));
    }
    
    return i;

}


int put_in_file(struct Fellow Array[], FILE * fp)
{
    for(int i = 0; i<32; i++){
        fprintf(fp, "Candidate %d : \nName : %s %s %s \n", i, Array[i].name->fname, Array[i].name->mname, Array[i].name->lname);
        fputs("Programming languages known : \n", fp);

        if(Array[i].pl.C) fputs("C\n", fp);
        if(Array[i].pl.Java) fputs("Java\n", fp);
        if(Array[i].pl.Cpp) fputs("C++\n", fp);
        if(Array[i].pl.Python) fputs("Python\n", fp);
        if(Array[i].pl.Go) fputs("Go\n", fp);

        fputs("Languages known : \n", fp);

        if(Array[i].hl.Eng) fputs("English\n", fp);
        if(Array[i].hl.Hin) fputs("Hindi\n", fp);
        if(Array[i].hl.Kan) fputs("Kannada\n", fp);
        if(Array[i].hl.Esp) fputs("Spanish\n", fp);
        if(Array[i].hl.Frn) fputs("French\n", fp);

        if(Array[i].fresher==1) 
            fputs("NO PRIOR EXPRIENCE.", fp);
        else{
            int n = sizeof(*(Array[i].arr))/sizeof(struct Exp);
            for(int j = 0; j<n; j++){
                fprintf(fp, "Years of experience : %d\n",Array[i].arr[j].yrs);
                fprintf(fp, "Company ID : %d\n", Array[i].arr[j].company_id);
            }
        }
        fprintf(fp, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    }
    return 0;
}