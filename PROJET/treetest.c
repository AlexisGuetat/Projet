#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <dirent.h>

#include "libTree/libtree.h"

struct dirent *ent;

int main(int argc, char const *argv[])
{
    
    DIR *dossier;

    //VERIFIE SI UN FICHIER EST BIEN SAISIE
    if(argc !=2)
    {
        perror("ERROR SELECTIONNER UN DOSSIER");
    }

    // RECUPERATION DES VALEURS DE LECTURE  
    char const*dossierLecture = argv[1];
   
    dossier = opendir(dossierLecture);
    assert(dossier!= NULL); // affiche un message d'erreur et arrete le programme

    
    // TANT QU'ON ARRRIVE PAS A LA FIN DU DOSSIER PN AFFICHE LE NOM DES FICHIERS
    while( (ent=readdir(dossier)) != NULL)
    {
        printf("%s\n",ent->d_name);
    }

    closedir(dossier); //ferme le "flux"
    return 0;
}
