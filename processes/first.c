#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>	

int main() {
	int **var;
	var = malloc(sizeof(int*));
	*var = malloc(sizeof(int));
	**var = 0;
	pid_t son = fork();
	if(son > 0){
    	**var = 1;
    	wait(NULL);
	    printf("parent : %d\n", **var);
	    free(*var);
	    free(var);
	}if(son == 0){
	    sleep(2);
	    printf("fils : %d\n", **var);
    	**var = 3;    	
	    free(*var);
	    free(var);
    	exit(0);
   	}
    // printf("%s\n", getenv("USER"));
    return 0;
}
