
//ON DEFINT UNE STRUCTURE LISTE DE DOSSIERS ET DE LISTE DE FICHIER
typedef struct dirent *ListeDossiers;
typedef struct FILE *ListeDeFichiers;

//ON DEFENIT UNE STRUCTURE ARBORESCENCE QUI CONTIENT UNE LISTE DE DOSSIERS ET DE FICHERS
struct Arborescence {

   ListeDossiers listeDossiers;
   ListeDeFichiers listeDeFichiers;

};

//ON EN CREE LE TYPE
typedef struct Arborescence Arborescence;


//AFFICHE UNE ARBORESCENCE DE REPERTOIRE
void affichage_recursif_dossier(char const * cheminDossier);

//charge en mémoire, dans une structure de données de notre choix, une arborescence de répertoires.
void load(Arborescence arbo);

//recherche les emplacements d’un fichier (fourni en paramètre) dans la structure de données précédemment construite.
void search(char *cheminFichier);