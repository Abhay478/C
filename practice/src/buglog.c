
#include "my_header.h"

int buglog(char * name, char * msg, char * level)
{
    FILE * f = fopen(name, "a");

    if(!f) return -1;
    
    fprintf(f, );
    fprintf(f, "\n\n");
    fprintf(f, "%s >> %s :: ", __DATE__, __TIME__);
    fprintf(f, "[%s] %s\n", level, msg);

    fclose(f);

    return 0;
}

int main(int argc, char * argv[])
{
    

    printf("%d\n", buglog(argv[1], "Test", "Event"));
    return 0;
}