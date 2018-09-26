#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "treelib.h"

#define TAILLE 100
#define BURNED "__burned__"
#define FICHIER_OU_EST_COPIE_ARBORESCENCE "../arborescence.txt"


void affichageArborescence(char const * chemin_de_arborescnce_a_afficher){
    char chemin[4096];
    struct dirent *lecture;
    DIR *rep;
       
    rep = opendir(chemin_de_arborescnce_a_afficher);
    if (rep == NULL)
    {
       perror("DOSSIER INTROUVABLE");
    }
    printf("%s:\n", chemin_de_arborescnce_a_afficher);
    while ((lecture = readdir(rep))!=NULL)
    {
        if (lecture->d_type == DT_DIR)//CHEK SI UN DOSSIER EST UN DOSSIER 
        {
          if (strcmp(lecture->d_name, ".")!=0 && strcmp(lecture->d_name, "..")!=0) //STRCMP COMPARE DEUX CHAINE DE CARACTERE
          { 
            strcpy(chemin, chemin_de_arborescnce_a_afficher); //Copie le cheminDossier dans chemin
            strcat(chemin,"/"); //Concatene la chaine chemin et "/"
            strcat(chemin, lecture->d_name); //Concatene la chaine chemin et le nom du Dossier
            affichageArborescence(chemin);
      }
        }
        else
        {          
           printf("--> %s\n", lecture->d_name);
        }
    }
    closedir(rep);
}

void copieArborescenceInFile(char const *chemin_de_arborescnce_a_copier)
{
  
}

void load(char const *cheminDossier,Arborescence *arbo){

  FILE *fichier ;
  char chaine_a_recup[TAILLE] ;
  int i, j, found ;
  int nbm = 0 ; // nombre de mots
  char **tab ;

  fichier = fopen(FICHIER_OU_EST_COPIE_ARBORESCENCE,"r") ;
  assert(fichier!=NULL) ;

  while(fgets(chaine_a_recup,TAILLE-1,fichier)!=NULL) nbm++ ;
  printf("%d mots\n",nbm) ;

  tab = malloc(nbm*sizeof(char*)) ;
  assert(tab!=NULL) ;

  rewind(fichier) ;
  i = 0 ;
  while(fgets(chaine_a_recup,TAILLE-1,fichier)!=NULL)
  {
    chaine_a_recup[strlen(chaine_a_recup)-1] = 0 ;
    tab[i] = strdup(chaine_a_recup) ; // malloc + strcpy
    i++ ;
  }

  // ici, le fichier est chargé en mémoire

  for (i=0 ; i<nbm ; i++)
  {
    if (strcmp(tab[i],BURNED)!=0)
    {
      found = 0 ;
      for (j=i+1 ; j<nbm ; j++)
        if (ana(tab[i],tab[j]))
        {
          if (!found) printf("%s ",tab[i]) ;
          printf("%s ",tab[j]) ;
          strcpy(tab[j],BURNED) ;
          found = 1 ;
        }
      if (found) printf("\n") ;
    }
  }

  fclose(fichier) ;

  for (i=0 ; i<nbm ; i++) free(tab[i]) ;
  free(tab) ;

  return 0 ;
}
