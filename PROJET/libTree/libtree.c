#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <dirent.h>
#include "libtree.h"


void affichage_recursif_dossier(char const * cheminDossier)
{
    char chemin[4096];
    struct dirent *lecture;
    DIR *rep;
       
    rep = opendir(cheminDossier);
    if (rep == NULL)
    {
       perror("DOSSIER INTROUVABLE");
       return 1;
    }
    printf("%s:\n", cheminDossier);
    while ((lecture = readdir(rep))!=NULL)
    {
        if (lecture->d_type == DT_DIR)//CHEK SI UN DOSSIER EST UN DOSSIER 
        {
          if (strcmp(lecture->d_name, ".")!=0 && strcmp(lecture->d_name, "..")!=0) //STRCMP COMPARE DEUX CHAINE DE CARACTERE
          { 
            strcpy(chemin, cheminDossier); //Copie le cheminDossier dans chemin
            strcat(chemin,"/"); //Concatene la chaine chemin et "/"
            strcat(chemin, lecture->d_name); //Concatene la chaine chemin et le nom du Dossier
            recur(chemin);
      }
        }
        else
        {          
           printf("--> %s\n", lecture->d_name);
        }
    }
    closedir(rep);
}