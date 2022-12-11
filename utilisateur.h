
#include <gtk/gtk.h>


typedef struct Date{
int jour;
char mois[20];
int annee;
} date;
//struct liste
typedef struct info{
char cin[30];
char nom[30];
char prenom[30];
date d;
char role[30];
char genre[30];
char nbvote[30];
}utilisateur;

//les fonctions
void ajouterUser(utilisateur L);
int modifierUser(utilisateur nouvL);
void supprimerUser(char cin[]);
int Chercher(char cin[]);
void afficher_user(GtkTreeView *liste);
int verifier_login(char log[]);
int verifier_PASSEWORD(char Pw[]);
int verif(char log[], char Pw[]);
float age_moy(char * filename);

