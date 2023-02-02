#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

char Voyelle(char *nomFlux){
    int v[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int tab[255];
    int i, c;
    FILE *flux;

    if (nomFlux == "")
        flux = stdin;
    else{
        flux = fopen(nomFlux, "r");
        if (!flux){
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
    return c;
}




int main(int argc, char **argv){
    if (argc == 2)
        return(Voyelle(argv[1]));
    else
        fprintf(stderr, "no file to explore\n");
    return 0;
}