#include <stdio.h>
#include "observateur.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

enum {
ID,
NOM,
PRENOM,
JOURE,
MOISE,
ANNEEE,
APPARTENANCE,
GENRE,
NBVOTE,
COLUMNS
};
///////////////////////////////////////////////////////////////////////////////////////////
//function pour ajouter user
void ajouterrObs(observateur O)
{

    FILE * f=fopen("observateur.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %s %d %s %s %s\n",O.id,O.nom,O.prenom,O.de.joure,O.de.moise,O.de.anneee,O.appartenance,O.genre,O.nbvote);
        
    }
fclose(f);
}
///////////////////////////////////////////////////////////////////////////////////////
void afficherr_obs(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[10];
char nom[50];
char prenom[50];
int joure;
char moise[20];
int anneee;
char appartenance[50];
char genre[50];
char nbvote[50];
store=NULL;
FILE *f;
store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
if(store==NULL)
{


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("joure",renderer,"text",JOURE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("moise",renderer,"text",MOISE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("anneee",renderer,"text",ANNEEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("appartenance",renderer,"text",APPARTENANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbvote",renderer,"text",NBVOTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

{f=fopen("observateur.txt","a+");
	while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",id,nom,prenom,&joure,moise,&anneee,appartenance,genre,nbvote)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,0,id,1,nom,2,prenom,3,joure,4,moise,5,anneee,6,appartenance,7,genre,8,nbvote,-1);
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);


}
}
}
///////////////////////////////////////////////////////////////////////////////////////////
//function pour modifier user
int modifierrObs(observateur nouvO )
{
 observateur O;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2 =fopen("ax.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",O.id,O.nom,O.prenom,&O.de.joure,O.de.moise,&O.de.anneee,O.appartenance,O.genre,O.nbvote)!=EOF)
{
if(strcmp(nouvO.id,O.id)==0)
        
	fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",nouvO.id,nouvO.nom,nouvO.prenom,nouvO.de.joure,nouvO.de.moise,nouvO.de.anneee,nouvO.appartenance,nouvO.genre,nouvO.nbvote);
else

  	fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",O.id,O.nom,O.prenom,&O.de.joure,O.de.moise,&O.de.anneee,O.appartenance,O.genre,O.nbvote);

}
        fclose(f);
        fclose(f2);
remove("observateur.txt");
rename("ax.txt", "observateur.txt");
        return 1;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function pour supprimer user
void supprimerrObs(char id[])
{
     observateur O;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2=fopen("nouvv.txt", "w+");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",O.id,O.nom,O.prenom,&O.de.joure,O.de.moise,&O.de.anneee,O.appartenance,O.genre,O.nbvote)!=EOF)
        {
            if(strcmp(id,O.id)!=0)
              {
                fprintf(f2,"%s %s %s %d %s %d %s %s %s\n",O.id,O.nom,O.prenom,O.de.joure,O.de.moise,O.de.anneee,O.appartenance,O.genre,O.nbvote);
        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouvv.txt","observateur.txt");
}
}
//////////////////////////////////////////////////////////////////////////////////////
//function pour chercher liste
int Chercherr(char id[])
{
observateur H;
 int tr=0;
    FILE * f=fopen("utilisateur.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %d %s %d %s %s %s\n",H.id,H.nom,H.prenom,&H.de.joure,H.de.moise,&H.de.anneee,H.appartenance,H.genre,H.nbvote)!=EOF && tr==0)
{if(strcmp(H.id,id)==0)
tr=1;
return 1;
}
}
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
