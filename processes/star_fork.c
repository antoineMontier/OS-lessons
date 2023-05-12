// goal is to generate 4 sons with the father (star topology. each son should display their pid and the father pid) 
// the father process should end after the 4 son processes have finished

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(){
    pid_t son1, son2, son3, son4;

    son1 = fork();
    if(son1 > 0)
        printf("int the partent process, my son1 is : %d\n", son1);
    if(son1 == 0){ // to access son process, the pid_t is == 0
        printf("son1 actual : %d \t father : %d\n", getpid(), getppid());
        exit(0);
    }


    son2 = fork();
    if(son2 > 0)
        printf("int the partent process, my son2 is : %d\n", son2);
    if(son2 == 0){ 
        printf("son2 actual : %d \t father : %d\n", getpid(), getppid());
        exit(0);
    }



    son3 = fork();
    if(son3 > 0)
        printf("int the partent process, my son3 is : %d\n", son3);
    if(son3 == 0){ 
        printf("son3 actual : %d \t father : %d\n", getpid(), getppid());
        exit(0);
    }


    
    son4 = fork();
    if(son4 > 0)
        printf("int the partent process, my son4 is : %d\n", son4);
    if(son4 == 0){ 
        printf("son4 actual : %d \t father : %d\n", getpid(), getppid());
        exit(0);
    }


    return 0;
}
