#include "my_header.h"

typedef struct d{
    int n;
    struct d * next;
} dat;

typedef struct c{
    int rows;
    int columns;
    dat * next;
} cap;

cap * accept(FILE * f){
    char * line = malloc(1);

    cap * head = calloc(1, sizeof(cap));
    size_t n = 0;
    int temp = 0;
    head->rows = 0;
    head->columns = 0;
    dat * current = calloc(1, sizeof(dat));
    printf("%d\n", current->n);
    // head->next = current;

    int temp_rows = 0;

    while (getline(&line, &n, f) != -1){
        if(line[0] == '@') {
            head->columns /= head->rows;
            printf("Matrix successfully accepted. %d * %d\n", head->rows, head->columns);
            return head;
        }
        //head->columns = strlen(line) / 2;
        // printf("Columns : %d\n", head->columns);
        // temp_rows = head->rows;
        // printf("%d\n", temp_rows);
        // head->rows = temp_rows + 1;
        printf("Row : %d\n", head->rows);
        // head->rows++;
        while(sscanf(line, "%d", &temp) != -1){
            current->n = temp;
            printf("%d\n", temp);
            current->next = calloc(1, sizeof(dat));
            current = current->next;
            line += 2;
            head->columns++;
        }
        head->rows = 0;
        // printf("%d\n", head->rows);
    }
    return head;
}
void print_mat(cap *);
cap * accept_string(FILE * f){
    char * s = calloc(1, sizeof(char));
    size_t n;
    cap * head = calloc(1, sizeof(cap));
    dat * current = head->next = calloc(1, sizeof(dat));
    getdelim(&s, &n, ':', f);
    // getline(&s, &n, f);
    char * ro;
    char * ent;
    while((ro = strsep(&s, ";")) != NULL){
        head->rows++;
        while((ent = strsep(&ro, ",")) != NULL){
            if(head->rows == 1) head->columns++;
            current->n = atoi(ent);
            current->next = calloc(1, sizeof(dat));
            current = current->next;
        }
    }
    print_mat(head);
    return head;
}
int ** matrify(cap * head){
    int r = head->rows;
    int c = head->columns;
    int ** out = calloc(r, sizeof(int *));
    dat * current = head->next;
    for(int i = 0; i < r; i++){
        out[i] = calloc(r, sizeof(int));
        for(int j = 0; j < c; j++){
            out[i][j] = current->n;
            current = current->next;
        }
    }

    return out;
}

cap * capify(int ** mat, int rows, int columns){
    cap * head = calloc(1, sizeof(cap));
    head->columns = columns;
    head->rows = rows;
    dat * current = calloc(1, sizeof(dat));
    head->next = current;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            current->n = mat[i][j];
            current->next = calloc(1, sizeof(dat));
            current = current->next;
        }
    }
    return head;
}

void * transpose(cap * head, bool form){
    int ** ori = matrify(head);
    int ** tr = calloc(head->columns, sizeof(int *));
    for(int i = 0; i < head->columns; i++){
        tr[i] = calloc(head->rows, sizeof(int));
    }
    for(int i = 0; i < head->rows; i++){
        for (int j = 0; j < head->columns; j++){
            tr[j][i] = ori[i][j];
        }
    }
    if(form) return capify(tr, head->columns, head->rows);
    else return tr;
}

void add(cap * pres, cap * new, bool to_free){
    dat * current = pres->next;
    dat * inc = new->next;
    while (current != NULL){
        current->n += inc->n;
        current = current->next;
        inc = inc->next;
    }
    if(to_free){
        inc = new->next;
        dat * nex = inc->next;
        while(nex != NULL){
            free(inc);
            inc = nex;
            nex = nex->next;
        }
        free(inc);
    }
}

int dot(int * a, int * b, int n)
{
    int out = 0;
    for(int i = 0; i < n; i++){
        out += a[i] * b[i];
    }
    return out;
}

int * get_vec(dat ** begin, int n){
    int * out = calloc(n, sizeof(int));
    for(int i = 0; i < n && (*begin) != NULL; i++){
        out[i] = (*begin)->n;
        (*begin) = (*begin)->next;
    }
    return out;
}

cap * multiply(cap * pres, cap * new){
    if(pres->columns != new->rows) {
        printf("%d*%d, %d*%d", pres->rows, pres->columns, new->rows, new->columns);
        return NULL;
    }

    int ** mat = (int **)transpose(new, false);
    int * vec;
    dat * current = pres->next;
    cap * out = calloc(1, sizeof(cap));
    out->columns = new->columns;
    out->rows = pres->rows;
    out->next = calloc(1, sizeof(dat));
    dat * co = out->next;
    int dp;

    for(int i = 0; i < pres->rows; i++){
        vec = get_vec(&current, pres->columns);
        // printf("Break\n");
        for(int j = 0; j < new->columns; j++){
            dp = dot(vec, mat[j], pres->columns);
            co->n = dp;
            co->next = calloc(1, sizeof(dat));
            co = co->next;
        }
    }

    return out;
}

void print_mat(cap * head)
{
    if(head == NULL){
        printf("Not a matrix.\n");
        return;
    }
    dat * current = head->next;
    for(int i = 0; i < head->rows; i++){
        for(int j = 0; j < head->columns; j++){
            printf("%d\t", current->n);
            current = current->next;
        }
        printf("\n");
    }
}

int main(){
    cap * one = accept_string(stdin);
    // print_mat(one);
    cap * two = accept_string(stdin);
    // print_mat(two);
    // printf("And \n");
    // print_mat(multiply(one, two));
    
    return 0;
}
