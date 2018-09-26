#include <stdio.h>
#include "treelib/treelib.h"


int main(int argc, char const *argv[])
{
    char const *chemin=argv[1]; 
    if (argc != 2)
    {
        perror("ERREUR ENTREZ UN NOM DE REPERTOIRE VALIDE");
        return 1;
    }
    printf("VOICI L'ARBORECENCE DU REPERTOIRE : \n");
    affichageArborescence(chemin);

    //ICI ON STOCKE

    // ICI ON RE AFFICHE MAIS EN AYANT CHERCHER DANS LE LOAD
 
    return 0;
}
