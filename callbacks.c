#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "observateur.h"
#include "vote.h"
int x,x2;
int y,y1,t0;
int cp_ob=1;
int cp_ob2=1;
int test=0;
Vote te;

void
on_gestion_utilisateur_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affiche;
GtkWidget *afficher_users;
afficher_users=lookup_widget(objet_graphique,"acceuil");
gtk_widget_destroy(afficher_users);
affiche=create_ListeUsers();
gtk_widget_show (affiche);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar* cin;
gchar* nom;
gchar* prenom;
gint* jour;
gchar* mois;
gint* annee;
gchar* role;
gchar* genre;
gchar* nbvote;


utilisateur u;
GtkTreeIter iter;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,cin,1,nom,2,prenom,3,&jour,4,mois,5,&annee,6,role,7,genre,8,nbvote-1);
strcpy(u.cin,cin);
strcpy(u.nom,nom);
strcpy(u.prenom,prenom);
strcpy(u.d.mois,mois);
strcpy(u.role,role);
strcpy(u.genre,genre);
strcpy(u.nbvote,nbvote);
u.d.jour=*jour;
u.d.annee=*annee;
afficher_user(treeview);
}

}



void
on_ajouteruser_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *afficher_users;
afficher_users=lookup_widget(objet_graphique,"ListeUsers");
gtk_widget_destroy(afficher_users);
ajouter=create_ajouter_user();
gtk_widget_show (ajouter);
}


void
on_suprrimeruser_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimer_bilel");
p=lookup_widget(objet_graphique, "ListeUsers");
p=create_supprimer_user();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_modifieruser_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeUsers");
p=lookup_widget(objet_graphique, "modifier_user");
p=create_modifier_user ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}



void
on_chercheruser_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *label;
GtkWidget *e;
char ch[20];
int t0=0;
e=lookup_widget(objet_graphique, "entry3");
label=lookup_widget(objet_graphique, "label4");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(e)));
t0=Chercher(ch);
if(t0==0)
gtk_label_set_text(GTK_LABEL(label),"id non trouvé");
else
gtk_label_set_text(GTK_LABEL(label),"trouvé");
}


void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
utilisateur u;
GtkWidget *entrycin,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryrole,*entrygenre,*entrynbvote;

entrynom=lookup_widget(objet_graphique,"entry4");
entryprenom=lookup_widget(objet_graphique,"entry5");
entrycin=lookup_widget(objet_graphique,"entry6");
entryjour=lookup_widget(objet_graphique,"spinbutton1");
entrymois=lookup_widget(objet_graphique,"combobox1");
entryannee=lookup_widget(objet_graphique,"spinbutton2");
entryrole=lookup_widget(objet_graphique,"combobox2");
entrynbvote=lookup_widget(objet_graphique,"entry7");

strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

u.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(u.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
u.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(u.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));
strcpy(u.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (x==1){
strcpy(u.genre,"Homme");}
else 
if (x==2){
strcpy(u.genre,"Femme");}
ajouterUser(u);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x=2;}
}





void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x2=2;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x2=2;}
}


void
on_supuser_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*label;
GtkWidget*e;
char ch[20];
label=lookup_widget(objet_graphique, "label21");
e=lookup_widget(objet_graphique, "entry12");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(e)));
supprimerUser(ch);

}


void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimer_user");
p=lookup_widget(objet_graphique, "ListeUsers");
p=create_ListeUsers();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_Retour1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_annulerajout_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajouter_user");
p=lookup_widget(objet_graphique, "ListeUsers");
p=create_ListeUsers();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_button4_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(objet_graphique,"treeview1");
afficher_user (GTK_TREE_VIEW(treeview));
}


void
on_supprimeruser_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
p=lookup_widget(objet_graphique, "supprimer_user");
n=lookup_widget(objet_graphique, "ListeUsers");
p=create_supprimer_user();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_modifieruse_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeUsers");
p=lookup_widget(objet_graphique, "modifier_user");
p=create_modifier_user ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_Valider3_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
utilisateur L;
GtkWidget *entrycin,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryrole,*entrygenre,*entrynbvote;
int t0=0;
entrycin=lookup_widget(objet_graphique,"entry10");
entrynom=lookup_widget(objet_graphique,"entry8");
entryprenom=lookup_widget(objet_graphique,"entry9");
entryjour=lookup_widget(objet_graphique,"spinbutton3");
entrymois=lookup_widget(objet_graphique,"combobox3");
entryannee=lookup_widget(objet_graphique,"spinbutton4");
entryrole=lookup_widget(objet_graphique,"combobox4");
entrynbvote=lookup_widget(objet_graphique,"entry11");

strcpy(L.cin,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(L.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(L.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

L.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(L.d.mois, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
L.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(L.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));
strcpy(L.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (x2==1){
strcpy(L.genre,"Homme");}
else 
if (x2==2){
strcpy(L.genre,"Femme");}
t0=modifierUser(L);
}





void
on_anullermodif_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modifier_user");
p=lookup_widget(objet_graphique, "ListeUsers");
p=create_ListeUsers();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_Retouruservacceuil_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeUsers");
p=lookup_widget(objet_graphique, "acceuil");
p=create_acceuil();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_treeviewobs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar* id;
gchar* nom;
gchar* prenom;
gint* joure;
gchar* moise;
gint* anneee;
gchar* appartenance;
gchar* genre;
gchar* nbvote;

observateur O;
GtkTreeIter iter;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model,&iter,path))
	{ 
	  gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,id,1,nom,2,prenom,3,&joure,4,moise,5,&anneee,6,appartenance,7,genre,8,nbvote-1);
strcpy(O.id,id);
strcpy(O.nom,nom);
strcpy(O.prenom,prenom);
strcpy(O.de.moise,moise);
strcpy(O.appartenance,appartenance);
strcpy(O.genre,genre);
strcpy(O.nbvote,nbvote);
O.de.joure=*joure;
O.de.anneee=*anneee;
afficherr_obs(treeview);
	

}
}


void
on_chercherobss_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_ajouterobs_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeObs");
p=lookup_widget(objet_graphique, "ajouterobs");
p=create_ajouterobs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_modifierobs_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeObs");
p=lookup_widget(objet_graphique, "modifobs");
p=create_modifobs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_supprimerobs_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeObs");
p=lookup_widget(objet_graphique, "supprimerob");
p=create_supprimerob();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_afficherobs_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(objet_graphique,"treeviewobs");
afficherr_obs (GTK_TREE_VIEW(treeview));
}


void
on_obsversacc_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeObs");
p=lookup_widget(objet_graphique, "acceuil");
p=create_acceuil();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_anullersupobs_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "supprimerob");
p=lookup_widget(objet_graphique, "ListeObs");
p=create_ListeObs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_validersupobs_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*label;
GtkWidget*e;
char ch[20];
label=lookup_widget(objet_graphique, "label1");
e=lookup_widget(objet_graphique, "entry2");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(e)));
supprimerrObs(ch);
}


void
on_ValiderAjoutObs_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
observateur O;
GtkWidget *entryid,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryappartenance,*entrygenre,*entrynbvote;

entryid=lookup_widget(objet_graphique,"entryO3");
entrynom=lookup_widget(objet_graphique,"entryO4");
entryprenom=lookup_widget(objet_graphique,"entryO5");
entryjour=lookup_widget(objet_graphique,"spinbuttonO1");
entrymois=lookup_widget(objet_graphique,"comboboxO1");
entryannee=lookup_widget(objet_graphique,"spinbuttonO2");
entryappartenance=lookup_widget(objet_graphique,"comboboxO2");
entrynbvote=lookup_widget(objet_graphique,"entryO6");

strcpy(O.id,gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(O.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(O.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

O.de.joure = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(O.de.moise, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
O.de.anneee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(O.appartenance, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryappartenance)));
strcpy(O.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (y==1){
strcpy(O.genre,"Homme");}
else 
if (y==2){
strcpy(O.genre,"Femme");}
ajouterrObs(O);
}


void
on_annulerajoutobs_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajouterobs");
p=lookup_widget(objet_graphique, "ListeObs");
p=create_ListeObs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_anullermodifobs_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modifobs");
p=lookup_widget(objet_graphique, "ListeObs");
p=create_ListeObs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_validermodifobs_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
observateur O;
GtkWidget *entryid,*entrynom,*entryprenom,*entryjour,*entrymois,*entryannee,*entryappartenance,*entrygenre,*entrynbvote;

entryid=lookup_widget(objet_graphique,"entryO7");
entrynom=lookup_widget(objet_graphique,"entryO8");
entryprenom=lookup_widget(objet_graphique,"entryO9");
entryjour=lookup_widget(objet_graphique,"spinbuttonO3");
entrymois=lookup_widget(objet_graphique,"comboboxO4");
entryannee=lookup_widget(objet_graphique,"spinbuttonO4");
entryappartenance=lookup_widget(objet_graphique,"comboboxO4");
entrynbvote=lookup_widget(objet_graphique,"entryO10");

strcpy(O.id,gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(O.nom,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(O.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

O.de.joure = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
strcpy(O.de.moise, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
O.de.anneee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));
strcpy(O.appartenance, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryappartenance)));
strcpy(O.nbvote,gtk_entry_get_text(GTK_ENTRY(entrynbvote)));
if (y1==1){
strcpy(O.genre,"Homme");}
else 
if (y1==2){
strcpy(O.genre,"Femme");}
t0=modifierrObs(O);
}


void
on_Hommeobs_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
y=1;
}


void
on_Femmeobs_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
y=2;
}


void
on_radiobuttonO4_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
y1=2;
}


void
on_radiobuttonO3_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
y1=1;
}


void
on_gestion_observateur_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "acceuil");
p=lookup_widget(objet_graphique, "ListeObs");
p=create_ListeObs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_connecter_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *LOGIN,*acceuil;
GtkWidget *username, *password , *output,*label;
char user[20];
char pasw[20];
int trouve,verife,verifer;
label=lookup_widget (objet_graphique,"labellog");
username=lookup_widget (objet_graphique,"entrylog");
password=lookup_widget (objet_graphique,"entrymdp");
output= lookup_widget (objet_graphique,"label");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));

trouve=verif(user,pasw);
verife=verifier_login(user);
verifer=verifier_PASSEWORD(pasw);

if(trouve==1)
{GtkWidget *Interface_Admin,*Identification;
LOGIN=lookup_widget(objet_graphique,"LOGIN");
gtk_widget_hide(LOGIN);
acceuil=lookup_widget(objet_graphique,"acceuil");
acceuil = create_acceuil ();
gtk_widget_show (acceuil);
}
else
gtk_label_set_text(GTK_LABEL(label),"Login ou MDP incorrect");

}


void
on_age_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
float A;
char cmoyage[10];
GtkWidget *label;
A=age_moy("utilisateur.txt");
sprintf(cmoyage,"%f",A);
label=lookup_widget (objet_graphique,"label83");
gtk_label_set_text(GTK_LABEL(label),cmoyage);
}


void
on_statt_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListUsers");
p=lookup_widget(objet_graphique, "Stat");
p=create_Stat();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_annulerstat_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "Stat");
p=lookup_widget(objet_graphique, "ListeUsers");
p=create_ListeUsers();
gtk_widget_show(p);
gtk_widget_destroy(n);
}



void
on_statobss_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ListeObs");
p=lookup_widget(objet_graphique, "Statobs");
p=create_Statobs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_anullercal_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "Statobs");
p=lookup_widget(objet_graphique, "ListeObs");
p=create_ListeObs();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_calculobs_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int n;
GtkWidget *label;
n=nombreobs("utilisateur.txt");
label=lookup_widget (objet_graphique,"label86");
gtk_label_set_text(GTK_LABEL(label),n);
}


void
on_Gbv_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "acceuil");
p=lookup_widget(objet_graphique, "menubv");
p=create_menubv();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_supprimerbv_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "menubv");
p=lookup_widget(objet_graphique, "window2");
p=create_window2();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_modifierbv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "menubv");
p=lookup_widget(objet_graphique, "vaidmod");
p=create_vaidmod();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_ajouterbv_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "menubv");
p=lookup_widget(objet_graphique, "ajoutvote");
p=create_ajoutvote();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_menuvershome_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "menubv");
p=lookup_widget(objet_graphique, "acceuil");
p=create_acceuil();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_Listebv_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "menubv");
p=lookup_widget(objet_graphique, "affichervote");
p=create_affichervote();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_button9bv_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "window2");
p=lookup_widget(objet_graphique, "menubv");
p= create_menubv ();
gtk_widget_show(p);
 gtk_widget_destroy(n);
}


void
on_button7bv_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*label;
char cin[20];
int t;
id=lookup_widget(objet_graphique, "entry6bv");
label=lookup_widget(objet_graphique, "label13bv");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(id))); 
t=supprimer(cin,"vote.txt");
if(t==1)
gtk_label_set_text(GTK_LABEL(label)," valider");
else
gtk_label_set_text(GTK_LABEL(label)," error");
}


void
on_button8bv_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajoutvote");
p=lookup_widget(objet_graphique, "menubv");
p=  create_menubv ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_button2bv_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*cin;
GtkWidget*ce;
GtkWidget*s;
GtkWidget*as;
GtkWidget*id;
GtkWidget*win;
GtkWidget*label;
Vote v;
win=lookup_widget(objet_graphique, "ok_vote");
cin=lookup_widget(objet_graphique, "entry3bv");
strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(cin))); 
ce=lookup_widget(objet_graphique, "spinbutton1bv");
v.cpe=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ce));
v.cpo=cp_ob;
s=lookup_widget(objet_graphique, "comboboxentry1bv");
strcpy(v.salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(s)));
as=lookup_widget(objet_graphique, "entry4bv");
strcpy(v.ADRsalle,gtk_entry_get_text(GTK_ENTRY(as)));
id=lookup_widget(objet_graphique, "entry5bv");
strcpy(v.id_agent,gtk_entry_get_text(GTK_ENTRY(id)));
test=ajouter(v , "vote.txt");


win= create_okvote ();
gtk_widget_show(win);
}


void
on_button13bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*label;
label=lookup_widget(objet_graphique, "label17bv");
if(test==0)
gtk_label_set_text(GTK_LABEL(label),"ajout échouée");
else
gtk_label_set_text(GTK_LABEL(label),"ajout avec success");
}


void
on_button15bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "vaidmod");
p=lookup_widget(objet_graphique, "menubv");
p=  create_menubv ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_button14bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*id;
GtkWidget*label;

char ch[20];

label=lookup_widget(objet_graphique, "label19bv");
id=lookup_widget(objet_graphique, "entry8bv");

strcpy(ch,gtk_entry_get_text(GTK_ENTRY(id)));
te=chercher(ch,"vote.txt");
if(strcmp(te.id,"-1")==0)
gtk_label_set_text(GTK_LABEL(label),"id non trouvé");
else
{
gtk_label_set_text(GTK_LABEL(label),"trouvé");

}
}


void
on_button18bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "vaidmod");
p=lookup_widget(objet_graphique, "modifyvote");
p=create_modifyvote();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_button16bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*cin;
GtkWidget*ce;
GtkWidget*s;
GtkWidget*as;
GtkWidget*id;
Vote v;
int t;
cin=lookup_widget(objet_graphique, "entry11bv");
strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(cin))); 
ce=lookup_widget(objet_graphique, "spinbutton2bv");
v.cpe=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ce));
v.cpo=cp_ob;
s=lookup_widget(objet_graphique, "comboboxentry2bv");
strcpy(v.salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(s)));
as=lookup_widget(objet_graphique, "entry10bv");
strcpy(v.ADRsalle,gtk_entry_get_text(GTK_ENTRY(as)));
id=lookup_widget(objet_graphique, "entry9bv");
strcpy(v.id_agent,gtk_entry_get_text(GTK_ENTRY(id)));
t=modifier(v.id, v, "vote.txt");
}


void
on_button19bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*id;
GtkWidget*ce;
GtkWidget*r1;
GtkWidget*r2;
GtkWidget*r3;
GtkWidget*r4;
GtkWidget*r5;
GtkWidget*s;
GtkWidget*as;
GtkWidget*ida;
GtkWidget*win;
int x;
id=lookup_widget(objet_graphique, "entry11bv");
ce=lookup_widget(objet_graphique, "spinbutton2bv");
r1=lookup_widget(objet_graphique, "radiobutton6bv");
r2=lookup_widget(objet_graphique, "radiobutton7bv");
r3=lookup_widget(objet_graphique, "radiobutton8bv");
r4=lookup_widget(objet_graphique, "radiobutton9bv");
r5=lookup_widget(objet_graphique, "radiobutton10bv");
s=lookup_widget(objet_graphique, "comboboxentry2bv");
as=lookup_widget(objet_graphique, "entry10bv");
ida=lookup_widget(objet_graphique, "entry9bv");
if(te.cpo==1)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r1),TRUE);
else if(te.cpo==2)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r2),TRUE);
else if(te.cpo==3)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE);
else if(te.cpo==4)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r4),TRUE);
else 
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r5),TRUE);
x=te.cpe;
gtk_spin_button_set_value(GTK_SPIN_BUTTON(ce),x);
if((strcmp(te.salle,"A")==0))
gtk_combo_box_set_active(GTK_COMBO_BOX(s),1);
else if((strcmp(te.salle,"B")==0))
gtk_combo_box_set_active(GTK_COMBO_BOX(s),2);
else if((strcmp(te.salle,"C")==0))
gtk_combo_box_set_active(GTK_COMBO_BOX(s),3);
else if((strcmp(te.salle,"D")==0))
gtk_combo_box_set_active(GTK_COMBO_BOX(s),4);
else if((strcmp(te.salle,"E")==0))
gtk_combo_box_set_active(GTK_COMBO_BOX(s),5);
else
gtk_combo_box_set_active(GTK_COMBO_BOX(s),6);
gtk_entry_set_text(GTK_ENTRY(id),te.id);
gtk_entry_set_text(GTK_ENTRY(as),te.ADRsalle);
gtk_entry_set_text(GTK_ENTRY(ida),te.id_agent);
}


void
on_button17bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modify-vote");
p=lookup_widget(objet_graphique, "menubv");
p=  create_menubv ();
gtk_widget_show(p);
gtk_widget_destroy(n);
}


void
on_radiobutton6bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob2=1;
}


void
on_radiobutton7bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob2=2;
}


void
on_radiobutton8bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob2=3;
}


void
on_radiobutton9bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob2=4;
}


void
on_radiobutton10bv_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob2=5;
}


void
on_radiobutton2bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob=2;
}


void
on_radiobutton3bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob=3;
}


void
on_radiobutton4bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob=4;
}


void
on_radiobutton5bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob=5;
}


void
on_button11bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affichervote");
p=lookup_widget(objet_graphique, "menubv");
p= create_menubv ();
gtk_widget_show(p);
 gtk_widget_destroy(n);
}


void
on_button10bv_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;

treeview=lookup_widget(objet_graphique,"treeview1bv");
afficher_vote(GTK_TREE_VIEW(treeview));
}


void
on_treeview1bv_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id;
gchar *ADRsalle;
gchar *id_agent;
gchar *salle;
gint *cpe;
gint *cpo;
Vote v;
int t;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{ gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,&id,1,&cpe,2,&cpo,3,&salle,4,&ADRsalle,5,&id_agent,-1);
strcpy(v.id,id);
strcpy(v.salle,salle);
strcpy(v.ADRsalle,ADRsalle);
strcpy(v.id_agent,id_agent);
v.cpe=*cpe;
v.cpo=*cpo;
if(t=supprimer (v.id,"vote.txt")==1)
afficher_vote(treeview);
}
}


void
on_radiobutton1bv_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
cp_ob=1;
}

