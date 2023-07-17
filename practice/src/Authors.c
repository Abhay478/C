
#include "my_header.h"

struct Book{
    int status;
    char * bookname;
    int book_hex_id; 
};
struct Author{
    char * p_name; 
    int no_of_works;    
    struct Book book_array[10];
} *this_lib;

void Librare(struct Author * a_in)
{
    for(int i = 0; i<a_in->no_of_works; i++){
        a_in->book_array[i].bookname = (char *)Get("book name", "string");
        a_in->book_array[i].book_hex_id = *(int *)Get("book ID", "hexadecimal");
        a_in->book_array[i].status = *(int *)Get("status of the book (1 if book is in library and 0 otherwise)", "int");
    }

    printf("Given : \n Writer\'s name : %s \n Books written : %d \n", a_in->p_name, a_in->no_of_works);
    printf("Summary of books Entered: \n");

    for(int k = 0; k < a_in->no_of_works; k++)
        printf("Book ID : %x \nBook status : %d \nName of book %d : %s \n", (a_in->book_array[k].book_hex_id), (a_in->book_array[k].status), k+1, (a_in->book_array[k].bookname));
}

int main()
{    
    int no_auth = *(int *)Get("number of authors", "int");
    this_lib =  calloc(no_auth, sizeof(struct Author)); //array of authors.

    for(int x = 0; x < no_auth; x++){        
        this_lib[x].p_name = (char *)Get("author's name", "string");
        this_lib[x].no_of_works = *(int *)Get("number of works", "int");

        Librare(this_lib + x);
    }
        
    free(this_lib);
    return 0;
   
}


    
