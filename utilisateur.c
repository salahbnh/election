#include <stdio.h>
#include "utilisateur.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

enum {
CIN,
NOM,
PRENOM,
JOUR,
MOIS,
ANNEE,
ROLE,
GENRE,
NBVOTE,
COLUMNS
};
///////////////////////////////////////////////////////////////////////////////////////////
//function pour ajouter user
void ajouterUser(utilisateur L)
{

    FILE * f=fopen("utilisateur.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.role,L.genre,L.nbvote);
        
    }
fclose(f);
}
///////////////////////////////////////////////////////////////////////////////////////
void afficher_user(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char cin[10];
char nom[50];
char prenom[50];
int jour;
char mois[20];
int annee;
char role[50];
char genre[50];
char nbvote[50];
store=NULL;
FILE *f;
store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
if(store==NULL)
{


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbvote",renderer,"text",NBVOTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

{f=fopen("utilisateur.txt","a+");
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",cin,nom,prenom,&jour,mois,&annee,role,genre,nbvote)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,0,cin,1,nom,2,prenom,3,jour,4,mois,5,annee,6,role,7,genre,8,nbvote,-1);
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);


}
}
}
///////////////////////////////////////////////////////////////////////////////////////////
//function pour modifier user
int modifierUser(utilisateur nouvL )
{
 utilisateur L;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,&L.d.jour,L.d.mois,&L.d.annee,L.role,L.genre,L.nbvote)!=EOF)
{
if(strcmp(nouvL.cin,L.cin)==0)
        
	fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",nouvL.cin,nouvL.nom,nouvL.prenom,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.role,nouvL.genre,nouvL.nbvote);
else

  	fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.role,L.genre,L.nbvote);

}
        fclose(f);
        fclose(f2);
remove("utilisateur.txt");
rename("aux.txt", "utilisateur.txt");
        return 1;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function pour supprimer user
void supprimerUser(char cin[])
{
     utilisateur L;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2=fopen("nouv.txt", "w+");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,&L.d.jour,L.d.mois,&L.d.annee,L.role,L.genre,L.nbvote)!=EOF)
        {
            if(strcmp(cin,L.cin)!=0)
              {
                fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.role,L.genre,L.nbvote);
        }
    }
    fclose(f);
    fclose(f2);
    remove("utilisateur.txt");
    rename("nouv.txt","utilisateur.txt");
}
}
//////////////////////////////////////////////////////////////////////////////////////
//function pour chercher liste
int Chercher(char cin[])
{
utilisateur v;
 int tr=0;
    FILE * f=fopen("utilisateur.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",v.cin,v.nom,v.prenom,&v.d.jour,v.d.mois,&v.d.annee,v.role,v.genre,v.nbvote)!=EOF && tr==0)
{if(strcmp(v.cin,cin)==0)
tr=1;
return 1;
}
}
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

int verifier_login(char log[])
{
FILE*f=NULL;
char ch1[20];
char ch2[20];
utilisateur p;
f=fopen("Hama.txt","r");
while (fscanf(f,"%s %s" ,ch1,ch2)!=EOF)
        {
if((strcmp(ch1,log)==0))
return 1; //existe   
}
fclose(f);
return 0; //n'existe pas
}
////////////////////////////////////////////////////////////////////////////////////////
int verifier_PASSEWORD(char Pw[])
{
FILE*f=NULL;
char ch1[20];
char ch2[20];
utilisateur p;
f=fopen("Hama.txt","r");
while (fscanf(f,"%s %s" ,ch1,ch2)!=EOF)
        {
if((strcmp(ch2,Pw)==0))
return 1; //existe   
}
fclose(f);
return 0; //n'existe pas
}
//////////////////////////////////////////////////////////////////////////////////////////
int verif(char log[], char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("Hama.txt","r");
if(f!=NULL)
{
while (fscanf(f,"%s %s" ,ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}
////////////////////////////////////////////////////////////////////////////////////////////
float age_moy(char * filename)
{
    int nbr_uti=0;
    utilisateur L;
    int age,s=0;
    float moyage;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,&L.d.jour,L.d.mois,&L.d.annee,L.role,L.genre,L.nbvote)!=EOF)
        {
            if(strcmp("electeur",L.cin)!=0)
             {  nbr_uti++;
                age=2022-L.d.annee;
                s=s+age;
            } moyage=s/nbr_uti;

        }
    }
    fclose(f);
    return (moyage);
}
///////////////////////////////////////////////////////////////////////////////////////////
int nombreobs(char * filename)
{
    int nombre=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",L.cin,L.nom,L.prenom,&L.d.jour,L.d.mois,&L.d.annee,L.role,L.genre,L.nbvote)!=EOF)
        {
            nombre++;

        }
    }
    fclose(f);
    return (nombre);
}
