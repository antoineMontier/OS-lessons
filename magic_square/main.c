#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int* allocatelinearmemory(int size);
int** allocateMemory(int size);
void freeMemory(int***m);
void freelinMemory(int**m);
void initialiselinMatrix(int*m, int size);
void printMatrix(int**m, int size);
void initialiseMatrix(int**m, int size);
void fillLaLoubere(int**m, int size);
void fillLinLaLoubere(int*m, int size);
int full(int**m, int size);
void increment(int*x, int*y, int**m, int size);
void incrementLin(int*x, int*y, int*m, int size);
void set(int*m, int x, int y, int value, int size);
int get(int*m, int x, int y, int size);
void printlin(int*m, int size);

int main() {
    //==================memory allocation
    int* matrix = allocatelinearmemory(SIZE);
    initialiselinMatrix(matrix, SIZE);
    fillLinLaLoubere(matrix, SIZE);
    printlin(matrix, SIZE);


    //====================free the memory
    freelinMemory(&matrix);
    return 0;
}

void fillLaLoubere(int**m, int size){
    //error handling
    if(*m == NULL)
        return;
    //set the middle uppper case to 1
    int x = 0, y = size/2, counter = 0;
    m[x][y] = ++counter;
    while(counter < size*size){
        increment(&x, &y, m, size);
        m[x][y] = ++counter;
    }

}

void increment(int*x, int*y, int**m, int size){
    int orx = *x;
    int ory = *y;
    (*x)--;
    (*y)++;
    if(*x == size)
        *x = 0;
    else if(*x == -1)
        *x = size - 1;
    if(*y == -1)
        *y = size - 1;
    else if(*y == size)
        *y = 0;

    if(m[*x][*y] == 0)
        return;

    *x = orx+1;
    *y = ory;
    if(*x == size)
        *x = 0;
}
void incrementLin(int*x, int*y, int*m, int size){
    int orx = *x;
    int ory = *y;
    (*x)--;
    (*y)++;
    if(*x == size)
        *x = 0;
    else if(*x == -1)
        *x = size - 1;
    if(*y == -1)
        *y = size - 1;
    else if(*y == size)
        *y = 0;

    if(get(m, *x, *y, size) == 0)
        return;

    *x = orx+1;
    *y = ory;
    if(*x == size)
        *x = 0;

}

int full(int ** m , int size){
    if(*m == NULL)
        return 0;
    for(int i = 0 ; i < size ; i++)
        for (int j = 0; j < size; j++)
            if(m[i][j] == 0)
                return 0;
    return 1;
}



void printMatrix(int**m, int size){
    if(*m == NULL)
        return;
    for(int i = 0 ; i < size ; i++) {
        printf("|");
        for (int j = 0; j < size; j++)
            printf(" %d ", m[i][j]);
        printf("|\n");
    }
}

void initialiseMatrix(int**m, int size){
    if(*m == NULL)
        return;
    for(int i = 0 ; i < size ; i++)
        for (int j = 0; j < size; j++)
            m[i][j] = 0;
}


int** allocateMemory(int size){
    int ** matrix;
    //==exceptions
    if(size < 0){
        fprintf(stderr, "wrong size");
        return matrix;
    }else if (size == 0)
        return matrix;


    matrix = malloc(size*sizeof(int*));
    for(int i = 0 ; i < size ; i++)
        matrix[i] = malloc(size*sizeof(int));
    return matrix;
}

void freeMemory(int***m){
    //==exception handling
    if(*m == NULL)
        return;
    for(int i = 0 ; i < SIZE ; i++)
        if((*m)[i] != NULL){
            free((*m)[i]);
            (*m)[i] = NULL;
        }
    if((*m) != NULL){
        free((*m));
        (*m) = NULL;
    }

}

int* allocatelinearmemory(int size){
    int*matrix;
    if(size < 0){
        fprintf(stderr, "wrong size");
        return matrix;
    }else if (size == 0)
        return matrix;
    matrix = malloc(size*size*sizeof(int));
    return matrix;
}


void freelinMemory(int**m){
    if(*m == NULL)
        return;
    free(*m);
    *m = NULL;
}

void initialiselinMatrix(int*m, int size){
    for(int i = 0 ; i < size*size ; i++)
        m[i] = 0;
}

void set(int*m, int x, int y, int value, int size){
    m[x*size + y] = value;
}
int get(int*m, int x, int y, int size){
    return m[x*size + y];
}
void printlin(int*m, int size){
    for(int i = 1 ; i <= size*size ; i++){
        if(i!= 0 && (i-1) % (size) == 0)
            printf("|");
        printf(" %d ", m[i-1]);
        if(i%(size) == 0 && i != 0)
            printf("|\n");
    }

}

int isfilled(int*m, int size){
    for(int i = 0 ; i < size*size ; i++)
        if(m[i] == 0)
            return 0;
    return 1;
}
void fillLinLaLoubere(int*m, int size){
    //error handling
    if(m == NULL)
        return;
    //set the middle uppper case to 1
    int x = 0, y = size/2, counter = 0;
    set(m, x, y, ++counter, size);
    while(counter < size*size){
        incrementLin(&x, &y, m, size);
        set(m, x, y, ++counter, size);
    }
}
