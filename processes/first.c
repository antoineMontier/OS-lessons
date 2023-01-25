#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    sleep(20);
    printf("actual : %d \t father : %d\n", getpid(), getppid());
    return 0;
}