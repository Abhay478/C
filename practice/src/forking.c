#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;

    pid = fork();
    if (pid < 0){ 
        perror("Fork Failed"); 
        return 1;
    }

    else if(pid == 0) execlp("./quake", NULL, NULL); 
    else{

        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
