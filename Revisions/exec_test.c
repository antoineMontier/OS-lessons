#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    printf("before exec\n");

    if(fork())
        execl("./aa", "./aa", NULL);
    if(fork())
        execl("./aa", "./aa", NULL);
    wait(NULL);
    wait(NULL);
    printf("after exec\n");
    return 0;
}