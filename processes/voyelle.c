#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

void Voyelle(char *nomFlux);

int main(int argc, char **argv)
{ // argc stands for arg count   and argv stands for arg vector

    // int a = atoi(argv[1]);

    pid_t parent = getpid();

    for (int i = 1; i < argc; i++)
        if (getpid() == parent && fork() == 0)
                Voyelle(argv[i]);

    if(getpid() == parent)
        for(int i = 1 ; i < argc ; i++){
            int n = 0;
            wait(&n);
            n = WEXITSTATUS(n);
            printf("most used voyelle in %s is %c\n", argv[i], n);
        }

}









void Voyelle(char *nomFlux)
{
    int v[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int tab[255];
    int i, c;
    FILE *flux;

    if (nomFlux == "")
        flux = stdin;
    else
    {
        flux = fopen(nomFlux, "r");
        if (!flux)
        {
            perror("probleme de flux");
            abort();
        }
    }
    for (i = 0; i < 6; i++)
        tab[v[i]] = 0; // initialisation

    while ((c = fgetc(flux)) != EOF) // lecture du fichier caractere par caractere
        tab[tolower(c)]++;
    fclose(flux);

    c = 'a';
    for (i = 1; i < 6; i++)
        c = (tab[v[i]] > tab[c] ? v[i] : c); // recherche du max
    exit(c);
}
