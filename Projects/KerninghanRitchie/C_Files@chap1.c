
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void Syn_chk(FILE * f);
void Com_rmr(FILE * f);
int check_backslash(int ch);
int check_perc(int ch);

FILE * fp = NULL;

/*void Com_rmr(FILE * f)
{
    
    int c = getc(f);
    bool quote_flag = 0;
    bool deleter = 0;

    int off = 0;
    char stop_char;
    for(int i = 0; (c = getc(f)) != EOF; i++){
        //check for "//"
        
        if(c == '\"' || c == '\''){
            if(!quote_flag)
                quote_flag = 1;
            else if(quote_flag)
                quote_flag = 0;

            continue;
        }
        
        if(c == '/' && !(quote_flag)){
            off = ftell(f);
            deleter = 1;
            c = getc(f);
            switch(c){
                case '/' : stop_char = '\n';
                break;
                case '*' : stop_char = '/';
                break;
                default : printf("Lone slash at postion %d", off);
                break;
            } 

        }    

        //once checked, backspace from end to start
        if(deleter == 1 && c == stop_char){
            while(ftell(f) > off)
                fprintf(f, "%c", '\b');

            deleter = 0;
        }
    }
}*/

int check_perc(int ch)
{
    switch(ch){
        case 'a' :
        case 'c' :
        case 'd' :
        case 'e' :
        case 'f' :
        case 'g' :
        case 'i' : 
        case 'n' : 
        case 'o' :
        case 'p' :
        case 's' : 
        case 'u' :
        case 'x' : return 0;
        break;
        
        case 'l' : return 1;
        break;

        case '%' : return 0;
        break;
        default : return -1;
        break;
            
    }

}
int check_backslash(int ch)
{
    switch(ch){
        //octal
        case 0 : 
        case 1 :
        case 2 :
        case 3 :
        case 4 :
        case 5 :
        case 6 :
        case 7 : return 0;
        break;
        
        //ordinary
        case 'a':
        case 'b' :
        case 'e' :
        case 'f' :
        case 'n' : 
        case 'p' :
        case 'r' : 
        case 't' :
        case 'u' : 
        case 'v' : return 1;
        break;
        //hexadecimal
        case 'x' : return 2;
        break;

        //special
        case '\"' :
        case '\'' :
        case '\\' : return 3;
        break;

        default : return -1;
        break;
        
    }
}
void Syn_chk(FILE * f)
{
    int c = 0; //character to be checked
    bool s_quote_flag;
    bool d_quote_flag;

    int o_par_count = 0;
    int c_par_count = 0;
    int o_brc_count = 0;
    int c_brc_count = 0;
    int o_box_count = 0;
    int c_box_count = 0;

    int stop_char = 0;
    bool comment_block = 0;

    short int esc_st, hex1, hex2, oct1, oct2, fs1, r1, fs2, r2, k; //one-time variables used within a single case. In-case declaration not being accepted.
    //part that counts
    while((c = getc(f)) != EOF){
        if(stop_char != 0 && c != stop_char) //skips rest of loop when inside comment. no imbalances will be checked.
            continue;
        else if(stop_char != 0 && c == stop_char){//comment ended. counting resumes.
            stop_char = 0;
            comment_block = 0;
        }

        switch(c){
            //escapes
            case '\\' : 
                esc_st = check_backslash(getc(f));
                switch(esc_st){
                    case 0 : //octal
                    k = getc(f);
                        if(!isdigit(k)){
                            ungetc(k, f);
                            break;                      //exits case.
                        }
                        oct1 = getw(f);
                        oct2 = getw(f);
                        if(oct1 > 7 || oct2 > 7)
                            printf("Incorrect octal character.\n");
                        else{
                            ungetc(oct2, f);
                            ungetc(oct1, f);
                        }
                    break;

                    case 1 : break;
                    case 2 :
                        hex1 = getc(f);
                        hex2 = getc(f);
                        
                        if(islower(hex1))
                            hex1 = toupper(hex1);
                        if(islower(hex2))
                            hex2 = toupper(hex2);

                        if((isalpha(hex1) && hex1 > 'F') || (isalpha(hex2) && hex2 > 'F'))
                            printf("Incorrect hexadecimal character.\n");
                        else{
                            ungetc(hex2, f);
                            ungetc(hex1, f);
                        }
                    break;
                    case 3 : break;
                    case -1 : printf("Nonexistent escape character.\n");
                    break;
                }
            //format specifiers
            case '%' : 
                if(!d_quote_flag)
                    break;              //exits case. format speifier nonexistent outside strings.

                esc_st = check_perc(getc(f));
                switch(esc_st){
                    case 0 : break;
                    case -1 : 
                        printf("Nonexistent format specifier.\n");
                    break;
                    case 1 :                                                                
                        fs1 = getc(f);
                        r1 = check_perc(fs1);
                        switch(r1){
                            case 0 : break;
                            case 1 : 
                                fs2 = getc(f);
                                r2 = check_perc(fs2);
                                switch(r2){
                                    case 0 : break;
                                    case 1 : 
                                        printf("Incorrect format specifier.\n");
                                        break;
                                }
                                ungetc(fs2, f);
                            break;
                        }
                        ungetc(fs1, f);
                    break;
                }
            break;

                



            //quotes
            case '\"' : d_quote_flag = !d_quote_flag;
            break;
            case '\'' : s_quote_flag = !s_quote_flag;
            break;
            //if any quotes are left open, the quote flags will be 1.
            //comments
            case '/' : 
                switch(getc(f)){//takes next character, checks for both types of comments.
                    case '/' : stop_char = '\n';
                    break;
                    //comment ends with newline
                    case '*' : 
                        comment_block = 1;
                        stop_char = '/';
                    break;
                    //comment ends with */
                    default : break;
                }
            break;
    
            //brackets
            case '(' : o_par_count++;
            break;
            case ')' : c_par_count++;
            break;
            case '{' : o_brc_count++;
            break;
            case '}' : c_brc_count++;
            break;
            case '[' : o_box_count++;
            break;
            case ']' : c_box_count++;
            break;
            //if any brackets are left unbalanced, degree of imbalance will be printed.
        }
    }




    //part that checks
    if(d_quote_flag)
        printf("Imbalanced double quotes.\n");
    else
        printf("Double quotes balanced.\n");
    if(s_quote_flag)
        printf("Imbalanced single quotes.\n");
    else
        printf("Single quotes balanced.\n");
    
    int par_imb = o_par_count - c_par_count;
    int brc_imb = o_brc_count - c_brc_count;
    int box_imb = o_box_count - c_box_count;

    if(par_imb>0)
        printf("%d more open parentheses than closed.\n",  par_imb);
    else if(par_imb<0)
        printf("%d less open parentheses than closed.\n",  par_imb);
    else
        printf("Parentheses balanced.\n");

    if(brc_imb>0)
        printf("%d more open braces than closed.\n",  par_imb);
    else if(brc_imb<0)
        printf("%d less open braces than closed.\n",  par_imb);
    else
        printf("Braces balanced.\n");

    if(box_imb>0)
        printf("%d more open box brackets than closed.\n",  par_imb);
    else if(box_imb<0)
        printf("%d less open box brackets than closed.\n",  par_imb);
    else
        printf("Box brackets balanced.\n");

    if(comment_block)
        printf("Unclosed comment block. Portion of code may not get compiled.\n");

    
}


int main(void)
{
    //get file path
    printf("Enter file path.\n");
    char * fpath = (char *)calloc(256, sizeof(char));
    scanf("%s", fpath);
    fp = fopen(fpath, "r");

    Syn_chk(fp);
    int c = 0;
    for(int i = 0; (c = getc(fp)) != EOF; i++){
        printf("%c", c);
    }
    //close file
    fclose(fp);
    free(fpath);
    return 0;
}