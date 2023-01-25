#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    sleep(2);
    printf("actual : %d \t father : %d\n", getpid(), getppid());
    printf("%s\n", getenv("USER"));
    system("ls -l");
    return 0;
}