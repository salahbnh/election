
#include <gtk/gtk.h>


typedef struct Datee{
int joure;
char moise[20];
int anneee;
} datee;
//struct liste
typedef struct infoo{
char id[30];
char nom[30];
char prenom[30];
datee de;
char appartenance[30];
char genre[30];
char nbvote[30];
}observateur;

//les fonctions
void ajouterrObs(observateur O);
int modifierrObs(observateur nouvO);
void supprimerrObs(char id[]);
int Chercherr(char id[]);
void afficherr_obs(GtkTreeView *liste);

