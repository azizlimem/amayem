#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "stock.h"
#include "support.h"
#include "fonctionsadmin.h"
#include "fonction.h"
#include "menu.h"
#include "etudiant.h"
#include "reclamation.h"

///////////////////////:tache yasmine
void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{//ajouter un produit
GtkWidget *mois;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *sortie;
GtkWidget *prenom;
GtkWidget *nom;
GtkWidget *homme;
GtkWidget *femme;
GtkWidget *poste;
GtkWidget *mdp;
GtkWidget *id;

user u;
id=lookup_widget(objet,"entryid");
sortie=lookup_widget(objet,"label26");
mois=lookup_widget(objet,"spinbutton7");
jour=lookup_widget(objet,"spinbutton5");
annee=lookup_widget(objet,"spinbutton6");
prenom=lookup_widget(objet,"entry4");
nom=lookup_widget(objet,"entry3");
mdp=lookup_widget(objet,"mdp");
poste=lookup_widget(objet,"comboboxPoste");
femme=lookup_widget(objet,"femme");

homme=lookup_widget(objet,"homme");

strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
u.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
u.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
u.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));

strcpy(u.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));

if(radio==2){
strcpy(u.sexe,"femme");
}
if(radio==1){
strcpy(u.sexe,"homme");
}

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Ajout réuissie");

ajouter_user(u);

}


//////////////////////////////////////////////////////////////////////////////////
//ajouter_un_utilisteur ======>> gerer_users

void
on_button13_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_un_utilisateur;
GtkWidget *gerer_user;
GtkWidget *treeview1;

ajouter_un_utilisateur=lookup_widget(objet,"ajouter_un_utilisateur");

gtk_widget_destroy(ajouter_un_utilisateur);
gerer_user=create_gerer_user();

gtk_widget_show(gerer_user);
treeview1=lookup_widget(gerer_user,"treeview1");

afficher_user(treeview1);
}


//Modifier un utilisateur
void
on_button8_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *sortie;
GtkWidget *identifiant1;
GtkWidget *nom;
GtkWidget *prenom;
user u;
identifiant1=lookup_widget(objet,"spinbutton2");
//u.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant1));
sortie=lookup_widget(objet,"label25");
nom=lookup_widget(objet,"entry1_nom");
prenom=lookup_widget(objet,"entry2_quantite");

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));


GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissie");

modifier_user( u);
}
//////////////////////////////////////////////////////////////////////////////////
//modifier_un_utilisateur ======>> gerer_user
void
on_button9_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_un_utilisateur;
GtkWidget *gerer_user;
GtkWidget *treeview1;

modifier_un_utilisateur=lookup_widget(objet,"modifier_un_utilisateur");

gtk_widget_destroy(modifier_un_utilisateur);
gerer_user=create_gerer_user();

gtk_widget_show(gerer_user);
treeview1=lookup_widget(gerer_user,"treeview1");

afficher_user(treeview1);
}

//////////////////////////////////////////////////////////////////////////////////
//gerer_le_stock ======>> modifier_un_produit
void
on_button4_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *gerer_user;
GtkWidget *modifier_un_utilisateur;

GtkWidget *treeview;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;

	gchar* id;
	gchar* nom;
	gchar* prenom;
	gint* jour;
	gint* mois;
	gint* annee;
	gchar* poste;
	gchar* mdp;
	gchar* sexe;
	
user u;
GtkWidget *id1,*nom1,*prenom1,*sexe1,*poste1,*jour1,*mois1,*annee1,*mdp1;

gerer_user=lookup_widget(objet,"gerer_user");

   treeview=lookup_widget(gerer_user,"treeview1");
   selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&poste,5,&jour,6,&mois,7,&annee,8,&mdp,-1);

	strcpy(u.id,id);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	strcpy(u.sexe,sexe);
	strcpy(u.poste,poste);
	/*u.date.jour=jour;
	u.date.mois=mois;
	u.date.annee=annee;
*/
	strcpy(u.mdp,mdp);

}

gtk_widget_destroy(gerer_user);

modifier_un_utilisateur=create_modifier_un_utilisateur();
gtk_widget_show(modifier_un_utilisateur);
id1=lookup_widget(modifier_un_utilisateur,"entryidM");
nom1=lookup_widget(modifier_un_utilisateur,"entry1_nom");
prenom1=lookup_widget(modifier_un_utilisateur,"entry2_quantite");
sexe1=lookup_widget(modifier_un_utilisateur,"entrySexe");
poste1=lookup_widget(modifier_un_utilisateur,"entryPoste");
jour1=lookup_widget(modifier_un_utilisateur,"entryJour");
mois1=lookup_widget(modifier_un_utilisateur,"entryMois");
annee1=lookup_widget(modifier_un_utilisateur,"entry10");
mdp1=lookup_widget(modifier_un_utilisateur,"entry11");
gtk_entry_set_text(GTK_ENTRY(nom1),u.id);
gtk_entry_set_text(GTK_ENTRY(prenom1),u.nom);
gtk_entry_set_text(GTK_ENTRY(id1),u.prenom);
gtk_entry_set_text(GTK_ENTRY(sexe1),u.sexe);
gtk_entry_set_text(GTK_ENTRY(poste1),u.poste);
/*gtk_entry_set_text(GTK_ENTRY(jour1),u.date.jour);
gtk_entry_set_text(GTK_ENTRY(mois1),u.date.mois);
gtk_entry_set_text(GTK_ENTRY(annee1),u.date.annee);
*/gtk_entry_set_text(GTK_ENTRY(mdp1),u.mdp);




}
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
//gerer_user ======>> ajouter_un_utilisateur 
void
on_button3_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_un_utilisateur;
GtkWidget *gerer_user;

gerer_user=lookup_widget(objet,"gerer_user");

gtk_widget_destroy(gerer_user);
ajouter_un_utilisateur=create_ajouter_un_utilisateur();

gtk_widget_show(ajouter_un_utilisateur);
}


//////////////////////////////////////////////////////////////////////////////////
//Treeview users
void
on_treeview1_row_activated       (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gint* jour;
	gint* mois;
	gint* annee;
	gchar* poste;
	gchar* mdp;
	gchar* sexe;
	
	user u;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview1);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&poste,5,&jour,6,&mois,7,&annee,8,&mdp,-1);
	strcpy(u.id,id);
	strcpy(u.nom,nom);
	strcpy(u.prenom,prenom);
	u.date.jour=jour;
	u.date.mois=mois;
	u.date.annee=annee;
	strcpy(u.poste,poste);
	strcpy(u.mdp,mdp);
	strcpy(u.sexe,sexe);
	
	afficher_user(treeview1);
supprimer_user(u);
	
	}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_button1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{//chercher user
GtkWidget *identifiant;
GtkWidget *sortie;
user u;


identifiant=lookup_widget(objet,"chercheridentifiant");
sortie=lookup_widget(objet,"label23");





strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
int y;
y=exist_id(identifiant);

if (y!=1)
{

chercher_user(u);
GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1");
gtk_label_set_text(GTK_LABEL(sortie),"");

afficher_A_rechercher(treeview1);
}
else
{

GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1");
afficher_user(treeview1);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}

 




}


//////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////
//Reload tableau users
void
on_button5_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;

treeview1=lookup_widget(objet,"treeview1");

afficher_user(treeview1);
}





void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=2;
}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=1;
}




void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *modifier_un_utilisateur;
user u;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9;
GtkWidget *sortie22;

modifier_un_utilisateur=lookup_widget(objet,"modifier_un_utilisateur");
input1=lookup_widget(objet,"entry1_nom");
input2=lookup_widget(objet,"entry2_quantite");
input3=lookup_widget(objet,"entryidM");
input4=lookup_widget(objet,"entrySexe");
input5=lookup_widget(objet,"entryPoste");
input6=lookup_widget(objet,"entry11");
input7=lookup_widget(objet,"entryJour");
input8=lookup_widget(objet,"entryMois");
input9=lookup_widget(objet,"entry10");
sortie22=lookup_widget(objet,"label25");

strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(u.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(u.poste,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(u.mdp,gtk_entry_get_text(GTK_ENTRY(input6)));
u.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input7));
u.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input9));
u.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input8));



GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie22),"client modifié avec succés");

modifier_user(u);


}





void
on_button_se_connecter_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *identifiant,*mdp,*resultat;

user u;

char mdp1[30];
char id[30];


int verif_id_inscrit,verif_password_inscrit,verif_accee_inscrit;

resultat=lookup_widget(objet,"label566");
identifiant= lookup_widget(objet,"entry12");
mdp = lookup_widget(objet,"entry13");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(mdp1,gtk_entry_get_text(GTK_ENTRY(mdp)));


verif_id_inscrit=verifier_ID_inscrit(id);
verif_password_inscrit=verifier_PASSWORD_inscrit(mdp1);
//verif_accee_inscrit=verifier_ACCEE_inscrit(id);
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(resultat,GTK_STATE_NORMAL,&color);
if(verif_password_inscrit==7)
gtk_label_set_text(GTK_LABEL(resultat),"Mot de passe incorrecte");
if(verif_id_inscrit==0)
gtk_label_set_text(GTK_LABEL(resultat),"ID n'éxiste pas");
if(verif_id_inscrit==1)
{
	if(verif_password_inscrit==0)
	{
	GtkWidget *fenetre_menu;
	GtkWidget *fenetre_login;
	fenetre_login=lookup_widget(objet,"Login");
	gtk_widget_destroy(fenetre_login);
	fenetre_menu=create_Menu();
	gtk_widget_show(fenetre_menu);
	}
else
		gtk_label_set_text(GTK_LABEL(resultat),"Accèe interdit");
	}

}



void
on_button_tech_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *DashboardCapteur;


Menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(Menu);
DashboardCapteur=create_DashboardCapteur();

gtk_widget_show(DashboardCapteur);
}




void
on_button_restau_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *windowdisplay;


Menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(Menu);
windowdisplay=create_windowdisplay();

gtk_widget_show(windowdisplay);
}


void
on_button_stock_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *gerer_le_stock;


Menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(Menu);
gerer_le_stock=create_gerer_le_stock();

gtk_widget_show(gerer_le_stock);
}


void
on_button_retour_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gerer_user;
GtkWidget *Login;


gerer_user=lookup_widget(objet,"gerer_user");

gtk_widget_destroy(gerer_user);
Login=create_Login();

gtk_widget_show(Login);

}


void
on_button_reclamation_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *fenetre_menu_reclam;


Menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(Menu);
fenetre_menu_reclam=create_fenetre_menu_reclam();

gtk_widget_show(fenetre_menu_reclam);
}


void
on_button_etudiants_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Menu;
GtkWidget *gestiondesetudiants;


Menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(Menu);
gestiondesetudiants=create_gestiondesetudiants();

gtk_widget_show(gestiondesetudiants);
}





void
on_button16_deconx_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu;
GtkWidget *Login;


menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(menu);
Login=create_Login();

gtk_widget_show(Login);

}



void
on_button14_liste_users_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu;
GtkWidget *gerer_user;
GtkWidget *treeview1;

menu=lookup_widget(objet,"Menu");

gtk_widget_destroy(menu);
gerer_user=create_gerer_user();

gtk_widget_show(gerer_user);
treeview1=lookup_widget(gerer_user,"treeview1");

afficher_user(treeview1);
}
///////////////////////////////////// tache emna

//////////////////////////////////////////////////////////////////////////////////
//Treeview stock

void
on_treeview_stock_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint* identifiant;
	gchar* type;
	gchar* nom;
	gchar* quantite;
	gint* jour;
	gchar* mois;
	gchar* annee;
	gint* quantite_restante;
	stock s;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&identifiant,1,&type,2,&nom,3,&quantite,4,&jour,5,&mois,6,&annee,7,&quantite_restante,-1);
	s.identifiant=identifiant;
	strcpy(s.type,type);
	strcpy(s.nom,nom);
	strcpy(s.quantite,quantite);
	s.d.jour=jour;
	strcpy(s.d.mois,mois);
	strcpy(s.d.annee,annee);
	s.quantite_restante=quantite_restante;
	supprimer_s( s);
	affichage(treeview);
	}
}

//////////////////////////////////////////////////////////////////////////////////
//Reload tableau stock
void
on_button_refresh_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_stock;

treeview_stock=lookup_widget(objet,"treeview_stock");

affichage(treeview_stock);
}

///////////////////////////////////////////Modifier un produit
void
on_button_modifier_produit_clicked	(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *sortie;
GtkWidget *identifiant1;
GtkWidget *nom;
GtkWidget *quantite;
GtkWidget *quantite_restante; 
GtkWidget *type;
stock s;

identifiant1=lookup_widget(objet,"spinbutton4");
sortie=lookup_widget(objet,"label_s25");
nom=lookup_widget(objet,"entry_nompr");
quantite=lookup_widget(objet,"entry_quantitepr");
quantite_restante=lookup_widget(objet,"spinbutton_restante_mod");
type=lookup_widget(objet,"combobox_type_mod");


s.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant1));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(s.quantite,gtk_entry_get_text (GTK_ENTRY (quantite)));
s.quantite_restante=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (quantite_restante));
strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissie");


modifier_s( s);

}

//////////////////////////////////////ajouter un produit

void
on_button_ajouter_produit_clicked	(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *nom;
GtkWidget *quantite;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *quantite_restante;
GtkWidget *type;
GtkWidget *sortie;

stock s;

identifiant=lookup_widget(objet,"spinbutton_s3");
nom=lookup_widget(objet,"entry_nom");
quantite=lookup_widget(objet,"entry_quantite");
jour=lookup_widget(objet,"spinbutton_jour");
mois=lookup_widget(objet,"combobox_mois");
annee=lookup_widget(objet,"combobox_annee");
type=lookup_widget(objet,"combobox_type_aj");
quantite_restante=lookup_widget(objet,"spinbutton_restante_aj");
sortie=lookup_widget(objet,"label_s17");

if (l==1) {
s.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON( identifiant));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)));
s.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
strcpy(s.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(s.d.annee,gtk_combo_box_get_active_text (GTK_COMBO_BOX(annee)));
s.quantite_restante=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON( quantite_restante));
strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Ajout réuissie");

ajouter_s( s);
}
}

/////////////////////////verifier id produit
void
on_button_verifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *sortie;
GtkWidget *identifiant1;
GtkWidget *nom;
GtkWidget *quantite;
GtkWidget *type;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *quantite_restante;
stock s;

identifiant1=lookup_widget(objet,"spinbutton_s3");
s.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant1));
sortie=lookup_widget(objet,"label_s11");


nom=lookup_widget(objet,"entry_nom");
quantite=lookup_widget(objet,"entry_quantite");
jour=lookup_widget(objet,"spinbutton_jour");
mois=lookup_widget(objet,"combobox_mois");
annee=lookup_widget(objet,"combobox_annee");
type=lookup_widget(objet,"combobox_type_aj");
quantite_restante=lookup_widget(objet,"spinbutton_restante_aj");


int y;
y=verifier( s);
if(y==1)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Existe");

}
if(y==2)
{
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}


/////////////////////////////////gerer le stock ====> ajouter un produit
void
on_button_ajouter_s_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_un_produit;
GtkWidget *gerer_le_stock;

gerer_le_stock=lookup_widget(objet,"gerer_le_stock");

gtk_widget_destroy(gerer_le_stock);
ajouter_un_produit=create_ajouter_un_produit();

gtk_widget_show(ajouter_un_produit);
}

/////////////////////ajouter un pr ====> gerer le stock
void
on_button_retour_aj_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_un_produit;
GtkWidget *gerer_le_stock;
GtkWidget *treeview_stock;

ajouter_un_produit=lookup_widget(objet,"ajouter_un_produit");

gtk_widget_destroy(ajouter_un_produit);
gerer_le_stock=create_gerer_le_stock();

gtk_widget_show(gerer_le_stock);
treeview_stock=lookup_widget(gerer_le_stock,"treeview_stock");

affichage(treeview_stock);
}
//////////////////////modifier un produit===>gerer le stock

void
on_button_retour_mod_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier_un_produit;
GtkWidget *gerer_le_stock;
GtkWidget *treeview_stock;

modifier_un_produit=lookup_widget(objet,"modifier_un_produit");

gtk_widget_destroy(modifier_un_produit);
gerer_le_stock=create_gerer_le_stock();

gtk_widget_show(gerer_le_stock);
treeview_stock=lookup_widget(gerer_le_stock,"treeview_stock");

affichage(treeview_stock);
}
//////////////////gerer le stock ====>modifier un produit

void
on_button_modifier_s_clicked	(GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gerer_le_stock;
GtkWidget *modifier_un_produit;

gerer_le_stock=lookup_widget(objet,"gerer_le_stock");

gtk_widget_destroy(gerer_le_stock);
modifier_un_produit=create_modifier_un_produit();

gtk_widget_show(modifier_un_produit);
}
////////////////////////////////
void
on_button_alerte_stock_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
stock s;


alert_stock( s);
GtkWidget *treeview_stock;
treeview_stock=lookup_widget(objet,"treeview_stock");
afficher_alert_stock(treeview_stock);

}
/////////////////////////////////////////////chercher

void
on_button_chercher_id_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *identifiant;
GtkWidget *sortie;
stock s;

identifiant=lookup_widget(objet,"spinbutton_s1");
s.identifiant=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));
sortie=lookup_widget(objet,"label_s26");

int y;
y=verifier( s);
if(y==1)
{
chercher_s( s);
GtkWidget *treeview_stock;
treeview_stock=lookup_widget(objet,"treeview_stock");
afficher_s_chercher(treeview_stock);
}
if(y==2)
{
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"N'existe pas");
}
}


void
on_checkbutton_stock_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{l=1;}

}

////////////////////////////////////////////////////////////////////////////ahmed

int y,x,p,a,f,d;
//button pour entrer
/*void
on_button1_insc_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*inscript;
inscript=lookup_widget(button,"inscription");
gtk_widget_destroy(inscript);
DashboardCapteur=create_DashboardCapteur();
gtk_widget_show (DashboardCapteur);
}

/*
void
on_button2_auth_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username,*password,*DashboardCapteur, *windowAuth, *inscript;
char user[20];
char pasw[20];
int trouve;
username=lookup_widget (button, "entry3_log");
password=lookup_widget (button, "entry4_Pw");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if(trouve==1)
{
windowAuth=lookup_widget(button,"authen");
gtk_widget_destroy(windowAuth);
DashboardCapteur=create_DashboardCapteur();
gtk_widget_show (DashboardCapteur);

}

}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///AJOUT//////////////////////////////////////////////
void
on_buttonAjouter_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
capteur c;
FILE *f=NULL;
GtkWidget *ref, *nom, *output;
GtkWidget *combobox1;
char ref1[100];
char nom1[100];
char msg[100];
char T[100];
char R[100];
int trouve=0;


ref = lookup_widget (objet, "entry1Capteur");
nom = lookup_widget (objet, "entry2Capteur");
combobox1=lookup_widget (objet, "combobox1Capteur");

strcpy(c.reference_capteur, gtk_entry_get_text(GTK_ENTRY(ref)));

trouve=verifier1(c.reference_capteur);

if (trouve==0)
{

if(strcmp("Temperature",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox1)))==0)
strcpy(T,"capteurTemperature");
else if (strcmp("Debit Eau",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox1)))==0)
strcpy(T,"capteurDebitEau");
else if (strcmp("Fumee",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox1)))==0)
strcpy(T,"capteurFumee");
else if (strcmp("Mouvement",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox1)))==0)
strcpy(T,"capteurMouvement");
else if (strcmp("Autre",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox1)))==0)
strcpy(T,"Autre");


strcpy(c.typeCapteur, T);
strcpy(c.nom_capteur, gtk_entry_get_text(GTK_ENTRY(nom)));

ajouter_capteur (c);

output = lookup_widget(objet, "label93msgajout");
strcpy (msg,"Parfait ! le capteur est bien ajouté");
gtk_label_set_text(GTK_LABEL(output),msg);
}

	else 
	{
	output = lookup_widget(objet, "label93msgajout");
	strcpy (msg,"Erreur ! le capteur existe déjà.");
	gtk_label_set_text(GTK_LABEL(output),msg);
	}

}


void
on_button11_Retour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}

///MODIFIER///////////////////////////////



void
on_radiobutton2Capteur_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x=2;
}


void
on_radiobutton1Capteur_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x=1;
}




void
on_checkbutton1_Type_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
y=3;
}


void
on_button15_modifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
int y=0;
int x=0;
FILE *f,*E;
GtkWidget *ref, *nom, *output,*R;
GtkWidget *combobox2;
GtkWidget * togglebutton1, * togglebutton2,* togglebutton3;
char ref1[100];
char ref2[100];
char nom1[100];
char r[100];
char n[100];
char msg[100];
char T[100];
char T1[100];
int trouve=0,test=0;
R = lookup_widget(button, "entry13Modif");
output = lookup_widget(button, "labelmsgmodification");
ref = lookup_widget (button, "entry14modifier");
nom = lookup_widget (button, "entry15modifier");
combobox2=lookup_widget (button, "combobox2Capteur");
togglebutton1=lookup_widget(button, "radiobutton1Capteur");
togglebutton2=lookup_widget(button, "radiobutton2Capteur");
togglebutton3=lookup_widget(button, "checkbutton1_Type_modif");
strcpy(ref2, gtk_entry_get_text(GTK_ENTRY(R)));
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton1)))
x=1;
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton2)))
x=2;
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton3)))
y=1;
//kan radio1 yi5dem
if ((x==1)&&(y!=1))
{
strcpy(ref1, gtk_entry_get_text(GTK_ENTRY(ref)));

trouve=verifier1(ref2);

test=verifier1(ref1);


if ((test==0) && (trouve==1))
{

f=fopen("listecapteur.txt","r+"); 
E=fopen("temporaire.txt","w+"); 
while(fscanf(f,"%s %s %s\n",r,n,T)!=EOF)
       { if(strcmp(r,ref2)==0)
fprintf(E,"%s %s %s\n",ref1,n,T);
else fprintf(E,"%s %s %s\n",r,n,T);
	 }
fclose(E);
fclose(f);

E=fopen("temporaire.txt","r"); 
f=fopen("listecapteur.txt","w+");
while(fscanf(E,"%s %s %s\n",r,n,T)!=EOF)
      { 
fprintf(f,"%s %s %s\n",r,n,T);
	 }
	fclose(f);
   fclose(E);

strcpy (msg,"Parfait ! la reference est modifié");
}

else 
{
strcpy (msg,"Erreur ! ");
}

gtk_label_set_text(GTK_LABEL(output),msg);


}
//kan radio2 yi5dim
if ((x==2)&&(y!=1))
{strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));//yi7adhar mel entry yi7oto nom1

trouve=0;
trouve=verifier1(ref2);

if (trouve==1)//kan l9ah
{

f=fopen("listecapteur.txt","r+"); 
E=fopen("temporaire.txt","w+"); 
while(fscanf(f,"%s %s %s\n",r,n,T)!=EOF)
       { if(strcmp(r,ref2)==0) 
	fprintf(E,"%s %s %s\n",r,nom1,T);
	else fprintf(E,"%s %s %s\n",r,n,T);
	 }
fclose(E);
fclose(f);//c bon tiktib fi E


E=fopen("temporaire.txt","r+"); 
f=fopen("listecapteur.txt","w+");
while(fscanf(E,"%s %s %s\n",r,n,T)!=EOF)
	{ 
	fprintf(f,"%s %s %s\n",r,n,T);//badalna
	}
fclose(f);
fclose(E);

strcpy (msg,"Parfait ! le nom est modifié");
}

else 
{
strcpy (msg,"Erreur ! ");
}

gtk_label_set_text(GTK_LABEL(output),msg);//message
}



//kan radiocheck yi5dem
if ((y==1)&&((x==1)||(x==2)))
{//yi7adher les valeur fi T1
if(strcmp("Temperature",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox2)))==0)
strcpy(T1,"capteurTemperature");
else if (strcmp("Debit Eau",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox2)))==0)
strcpy(T1,"capteurDebitEau");
else if (strcmp("Fumee",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox2)))==0)
strcpy(T1,"capteurFumee");
else if (strcmp("Mouvement",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox2)))==0)
strcpy(T1,"capteurMouvement");
else if (strcmp("Autre",gtk_combo_box_get_active_text (GTK_COMBO_BOX (combobox2)))==0)
strcpy(T1,"Autre");

trouve=0;
trouve=verifier1(ref2);
//kan l9ah ***********
	if (trouve==1)
	{

	f=fopen("listecapteur.txt","r+"); 
	E=fopen("temporaire.txt","w+"); 
	while(fscanf(f,"%s %s %s\n",r,n,T)!=EOF)
	       { 
		if(strcmp(r,ref2)==0) //yo93ad yilawej
		fprintf(E,"%s %s %s\n",r,n,T1);//l9ah yibadel valeur
			else fprintf(E,"%s %s %s\n",r,n,T);//yiktbo hoa bido
		 }
	fclose(E);
	fclose(f);

	E=fopen("temporaire.txt","r+"); 
	f=fopen("listecapteur.txt","w+");
	while(fscanf(E,"%s %s %s\n",r,n,T)!=EOF)
		{ 
		fprintf(f,"%s %s %s\n",r,n,T);
		}
	fclose(f);
	fclose(E);

	strcpy (msg,"Parfait ! le type du capteur modifié");
	}

		else 
		{
		strcpy (msg,"Erreur ! ");
		}

gtk_label_set_text(GTK_LABEL(output),msg);

}
}


void
on_button4_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}

//////////CHERCHER///////////////////////////////////////////////////////////////
void
on_button16_chercher_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref, *output;
FILE *f=NULL;
char ref1[100];
char r[100];
char n[100];
char msg[100];
char T[100];
int trouve=0;
ref = lookup_widget (button, "entry16Cherchercap");
strcpy(ref1, gtk_entry_get_text(GTK_ENTRY(ref)));
output = lookup_widget(button, "label94msgchercher");

trouve=verifier1(ref1);

if (trouve==0)
{
strcpy (msg,"Erreur ! le capteur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),msg);
}

	else
	{
	f=fopen("listecapteur.txt","r");  
		if(f!=NULL){
		while(fscanf(f,"%s %s %s\n",&r,&n,&T)!=EOF) 
		{
			if(strcmp(ref1,r)==0) 
			sprintf(msg,"La référence du capteur : %s \n \nLe numéro : %s \n \nLe type : %s\n",r,n,T);}
	fclose(f);}
	gtk_label_set_text(GTK_LABEL(output),msg);
	}
}


void
on_button17_verifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
int trouve=0;
GtkWidget *ref, *output;
char ref1[100];
char msg[100];
ref = lookup_widget (button, "entry16Cherchercap");
strcpy(ref1, gtk_entry_get_text(GTK_ENTRY(ref)));
output = lookup_widget(button, "label49Verif");

trouve=verifier1(ref1);

if(trouve==1)
{strcpy (msg,"Le capteur existe, vous pouvez continuer.");
gtk_label_set_text(GTK_LABEL(output),msg);
}
	else if(trouve==0)
	{
	strcpy (msg,"le capteur n'existe pas, veuillez vérifier.");
	gtk_label_set_text(GTK_LABEL(output),msg);
	}
}


void
on_button5_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}

//////////////SUPPRIMER//////////////////////////////////////////////////////////
void
on_button18_supprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref, *output;
char ref1[100];
char msg[200];
char r[100];
char n[100];
char T[100];
FILE *f,*E;
int trouve=0;

ref = lookup_widget (button, "entry7Capteur");
strcpy(ref1, gtk_entry_get_text(GTK_ENTRY(ref)));
output = lookup_widget(button, "labelmsgsuppression");
trouve=verifier1(ref1);

if (trouve==0)
{
strcpy (msg,"Erreur ! le capteur n'existe pas");
gtk_label_set_text(GTK_LABEL(output),msg);
}

else {

f=fopen("listecapteur.txt","r"); 
E=fopen("temporaire.txt","w+"); 
while(fscanf(f,"%s %s %s\n",r,n,T)!=EOF)
       { if (strcmp(ref1,r)!=0)
fprintf(E,"%s %s %s\n",r,n,T);
	 }fclose(f);
	fclose(E);

E=fopen("temporaire.txt","r");
f=fopen("listecapteur.txt","w"); 
while(fscanf(E,"%s %s %s\n",r,n,T)!=EOF)
      { 
fprintf(f,"%s %s %s\n",r,n,T);
	 }
	fclose(f);
   fclose(E);


strcpy (msg,"Parfait ! le capteur est bien supprimé");
gtk_label_set_text(GTK_LABEL(output),msg);

}
}


void
on_button6_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}

/////////////LISTE/////////////////////////////////
void
on_button7_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}


void
on_button12_affListe_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*Liste,*treeview;

Liste = create_Liste();
gtk_widget_show (Liste) ;
DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

treeview=lookup_widget(Liste,"treeview1_Liste");
afficher_capteur (treeview);
}

////////////HISTORIQUE////////////////////////////////
void
on_button8_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}


void
on_button13_Histo_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*Historique,*treeview;

Historique = create_Historique();
gtk_widget_show (Historique) ;
DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

treeview=lookup_widget(Historique,"treeview2_Histo");
afficher_capteur_his(treeview);
}

//////////CAPTDEFFECTUEUX////////////////////////////////
void
on_button14_affdeff_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*capteurDeffectueux,*treeview;

capteurDeffectueux = create_capteurDeffectueux();
gtk_widget_show (capteurDeffectueux) ;
DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

treeview=lookup_widget(capteurDeffectueux,"treeview3_captDeff");
afficher_capteur_deff(treeview);
}


void
on_button9_Retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur;

DashboardCapteur=lookup_widget(button,"DashboardCapteur");
gtk_widget_destroy(DashboardCapteur);

DashboardCapteur = create_DashboardCapteur ();
gtk_widget_show (DashboardCapteur) ;
}
///////////////LISTE TREE////////////////////////

void
on_treeview1_Liste_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* ref;
gchar* nom;
gchar* type;
capteur c;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path)) {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &ref,1,&nom,2,&type,-1);

strcpy(c.reference_capteur,ref);
strcpy(c.nom_capteur,nom);
strcpy(c.typeCapteur,type);
//supprim_capteur(c);
afficher_capteur (treeview);
}
}


void
on_button19_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*Liste;

DashboardCapteur = create_DashboardCapteur();
gtk_widget_show (DashboardCapteur) ;
Liste=lookup_widget(button,"Liste");
gtk_widget_destroy(Liste);
}

///////////HISTORIQUE TREE//////////////////////////////
void
on_treeview2_Histo_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jr;
gchar* hr;
gchar* num;
gchar* val;
temp T2;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path)) {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &jr,1,&hr,2,&num,3,&val,-1);

strcpy(T2.jour,jr);
strcpy(T2.heure,num);
strcpy(T2.numT,num);
strcpy(T2.t,val);

afficher_capteur_his(treeview);
}
}


void
on_button20_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*Historique;

DashboardCapteur = create_DashboardCapteur();
gtk_widget_show (DashboardCapteur) ;
Historique=lookup_widget(button,"Historique");
gtk_widget_destroy(Historique);
}

///////////////////CAPTDEFF TREE///////////////////////////////
void
on_treeview3_captDeff_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jr;
gchar* hr;
gchar* num;
gchar* val;
temp T1;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path)) {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &jr,1,&hr,2,&num,3,&val,-1);

strcpy(T1.jour,jr);
strcpy(T1.heure,hr);
strcpy(T1.numT,num);
strcpy(T1.t,val);

afficher_capteur_deff(treeview);
}
}


void
on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DashboardCapteur,*capteurDeffectueux;

DashboardCapteur = create_DashboardCapteur();
gtk_widget_show (DashboardCapteur) ;
capteurDeffectueux=lookup_widget(button,"capteurDeffectueux");
gtk_widget_destroy(capteurDeffectueux);
}

/////////bouton quitter////////////


/////////////////ACTUALISER/////////////////////////////////////////////////////////
void
on_button23_actualiser_Liste_clicked   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Liste;
GtkWidget *treeview6;


Liste=lookup_widget(objet,"Liste");

treeview6=lookup_widget(Liste,"treeview1_Liste");

afficher_liste_alarmes_mouvements(treeview6);
}


void
on_button22_actualiser_Histo_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button24_act_captdeff_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}

////////////////////////calcul
void
on_button22_calcul_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int b,c,h;
float a;
char ch[100];
char msg[100];
FILE *f;
GtkWidget *choix,*output1,*output2,*output3,*output4,*output5,*output6,*output7;

//outputs
output1=lookup_widget(button,"temperatureCapteur");
output2=lookup_widget(button,"debiteauCapteur");
output3=lookup_widget(button,"fumeeCapteur");
output4=lookup_widget(button,"mouvementCapteur");
output5=lookup_widget(button,"autreCapteur");
output6=lookup_widget(button,"totalCapteur");
output7=lookup_widget(button,"choixCapteur");

{
choix=lookup_widget(button,"spinbutton1Capteur");
c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(choix));
//outputs
strcpy (ch,"saisir choix avec spinbutton");
strcpy (msg,ch);
gtk_label_set_text(GTK_LABEL(output7),msg);

if (c==1)//temperature
	{a=calcul(c);
	sprintf(ch,"%\t%.2f",a);
	strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output1),msg);}

else if(c==2)//debiteau
	{a=calcul(c);
	sprintf(ch,"%\t%.2f",a);
	strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output2),msg);}
else if(c==3)//fumee
	{a=calcul(c);
	sprintf(ch,"%\t%.2f",a);
	strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output3),msg);}
else if (c==4)//mouvement
	{ a=calcul(c);
	sprintf(ch,"%\t%.2f",a);
	     strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output4),msg);}
else if (c==5)//autre
	{ a=calcul(c);
	sprintf(ch,"%\t%.2f",a);
	strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output5),msg);}
else if (c==6)//total
	{b=compt();
	sprintf(ch,"%d",b);
	strcpy (msg,ch);
	gtk_label_set_text(GTK_LABEL(output6),msg);}

};
}
//////////////////////////////////////////////////////////////////////////////////aziz

int x,y;

void
on_buttonadd_clicked(GtkWidget *objet,gpointer user_data)
{
	

	GtkWidget *id,*meal,*dessert,*day,*dechets,*type,*sortie;
	menu h;
	id=lookup_widget(objet,"entryid1");
	meal=lookup_widget(objet,"entryrepas");
	dessert=lookup_widget(objet,"entrydessert");
	day=lookup_widget(objet,"spinbuttonjour");
	dechets=lookup_widget(objet,"spinbuttondechets");
	type=lookup_widget(objet,"comboboxtype");
	sortie=lookup_widget(objet,"label20");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.meal,gtk_entry_get_text(GTK_ENTRY(meal)));
	strcpy(h.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
	h.day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	h.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dechets));
	strcpy(h.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

	if (x==0)
        strcpy(h.size,"Maxi");
        else
        strcpy(h.size,"Mini");
        if (y==0)
        strcpy(h.cal,"Hyper");
        else
        strcpy(h.cal,"hypo");
	add_menu(h,"menu.txt");

	
	GdkColor color ;
	gdk_color_parse("green",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"Ajout Réussi");
	
	
	


}


void
on_buttondisplay_clicked               (GtkWidget 	*objet,
                                        gpointer         user_data)
{
	GtkWidget *windowdisplay,*windowadd,*treeview;
	windowadd=lookup_widget(objet,"windowadd");
	windowdisplay=lookup_widget(objet,"windowdisplay");
	gtk_widget_destroy(windowadd);
	windowdisplay=create_windowdisplay();
	gtk_widget_show(windowdisplay);
	treeview=lookup_widget(windowdisplay,"treeview");
	display_menu_ONtreeview(treeview,"menu.txt");



}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
		delete_menu(id,"menu.txt");
		display_menu_ONtreeview(treeview,"menu.txt");
	}

}



void
on_buttonreturn_clicked                (GtkWidget 	*objet,
                                        gpointer         user_data)
{
	GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(objet,"windowadd");
	windowdisplay=lookup_widget(objet,"windowdisplay");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_windowadd();
	gtk_widget_show(windowadd);

}


void
on_buttonsearch_clicked                (GtkWidget 	*objet,
                                        gpointer         user_data)
{
	GtkWidget *id;
	char id1[30];
	id=lookup_widget (objet,"entryidsearch");
	strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
	GtkWidget *windowdisplay;
	GtkWidget *treeview;
	windowdisplay=lookup_widget(objet,"windowdisplay");	
	treeview=lookup_widget(windowdisplay,"treeview");
	if(strcmp(id1,"")!=0)
	{
		search_menu(id1,"menu.txt");
		display_menu_ONtreeview(treeview,"search.txt");
		remove("search.txt");
	}
	else
		display_menu_ONtreeview(treeview,"menu.txt");
}




void
on_checkbutton_highc_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=0;
}


void
on_checkbutton_lowc_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=1;
}


void
on_button_update_clicked               (GtkWidget 	*objet,
                                        gpointer         user_data)
{GtkWidget *dis,*w1,*treeview;

w1=lookup_widget(objet,"windowdisplay");
dis=create_windowdisplay();
gtk_widget_show(dis);
gtk_widget_hide(w1);
treeview=lookup_widget(dis,"treeview");
//vider(treeview,"hostel.txt");
display_menu_ONtreeview(treeview,"menu.txt");
}


void
on_button_delete_clicked               (GtkWidget 	*objet,
                                        gpointer         user_data)
{
GtkWidget *id;
char id_menu[20];
id=lookup_widget(objet,"entryid1");
strcpy(id_menu,gtk_entry_get_text(GTK_ENTRY(id)));
delete_menu(id_menu,"menu.txt");

}


void
on_button_modify_clicked               (GtkWidget 	*objet,
                                        gpointer         user_data)
{
	GtkWidget *id,*meal,*dessert,*day,*dechets,*type;
	menu h;
	id=lookup_widget(objet,"entryid1");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	if(strcmp(h.id,"")!=0)
	{
	meal=lookup_widget(objet,"entryrepas");
	dessert=lookup_widget(objet,"entrydessert");
	day=lookup_widget(objet,"spinbuttonjour");
	dechets=lookup_widget(objet,"spinbuttondechets");
	type=lookup_widget(objet,"comboboxtype");
	strcpy(h.meal,gtk_entry_get_text(GTK_ENTRY(meal)));
	strcpy(h.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
	h.day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	h.dechets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dechets));
	strcpy(h.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

	if (x==0)
        strcpy(h.size,"Maxi");
        else
        strcpy(h.size,"Mini");

        if (y==0)
        strcpy(h.cal,"Hyper");
        else
        strcpy(h.cal,"Hypo");
	
	modify_menu(h,"menu.txt");}

}


void
on_radiobuttonbig_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=1;

}


void
on_radiobuttonsmall_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=0;

}




void
on_buttonbestmenu_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *windowdisplay;
	GtkWidget *treeview;
	windowdisplay=lookup_widget(objet,"windowdisplay");	
	treeview=lookup_widget(windowdisplay,"treeview");
	
	meilleur_menu("menu.txt");
	display_menu_ONtreeview(treeview,"best.txt");
	remove("best.txt");

	
	
}

//////////////////////////////////////////////mariem
int j;
int l=0;
int m;
void
on_buttona_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *ajoutet;

ajoutet = create_ajoutet ();
gtk_widget_show (ajoutet);


}


void
on_buttonm_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifieret;
modifieret=create_modifieret ();
gtk_widget_show (modifieret);
}


void
on_buttonaf_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageet;

affichageet = create_affichageet ();
gtk_widget_show (affichageet);

}


void
on_buttons_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_buttonr_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_buttonaffniveau_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageniveaux;
affichageniveaux=create_affichageniveaux ();
gtk_widget_show (affichageniveaux);

}


void
on_radiobutton1_etud_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{j=1;}
}


void
on_radiobutton2_etud_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{j=2;}
}


void
on_checkbutton1_etud_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{l=1;}
}


void
on_buttona1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{int j,m,a; 
char chj[6],chm[15],cha[6];
char x[30];
char Niveau[30];
char s1[20];
etudiant e;
GtkWidget *entryn;
GtkWidget *entryp;
GtkWidget *entryc;
GtkWidget *entryd;
GtkWidget *comboboxniv1;
GtkWidget *spinbuttonj1;
GtkWidget *spinbuttonm2;
GtkWidget *spinbuttona3;
GtkWidget *sortie1;
GtkWidget *sortie2;
GtkWidget *sortie3;
entryn=lookup_widget(button, "entry1_etud");
entryp=lookup_widget(button, "entry2_etud");
entryc=lookup_widget(button, "entry3_etud");
entryd=lookup_widget(button,"entry4_etud");
spinbuttonj1=lookup_widget(button, "spinbutton1_etud");
spinbuttonm2=lookup_widget(button, "spinbutton2_etud");
spinbuttona3=lookup_widget(button, "spinbutton3_etud");
comboboxniv1=lookup_widget(button, "combobox1_etud");
sortie1=lookup_widget(button, "label20_etud");
sortie2=lookup_widget(button, "label44_etud");
sortie3=lookup_widget(button, "label45_etud");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryd)));
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortie2),"champs obligaroire!");}
else if (veriff(x)==1)
{
   if(verifd(x)==0)
       gtk_label_set_text(GTK_LABEL(sortie3),"L'identifiant ne convient pas !");

else if((verifd(x)==1)&&(l==1)){
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(entryd)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(entryn)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(entryp)));
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(entryc)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonj1)); 
sprintf(chj,"%d",j);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonm2)); 
sprintf(chm,"%d",m);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttona3)); 
sprintf(cha,"%d",a);
strcpy(e.dte.jour,gtk_entry_get_text(GTK_ENTRY(spinbuttonj1)));
strcpy(e.dte.mois,gtk_entry_get_text(GTK_ENTRY(spinbuttonm2)));
strcpy(e.dte.annee,gtk_entry_get_text(GTK_ENTRY(spinbuttona3)));
if(j==1)
strcpy(s1,"Homme");
else 
{strcpy(s1,"Femme");}
strcpy(e.sexe,s1);
strcpy(Niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxniv1)));
strcpy(e.niv,Niveau);



ajouter_etud(e);

gtk_label_set_text(GTK_LABEL(sortie1),"Ajout effectué avec succès!");

}
}

}


void
on_buttonsuiv1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1_etud_row_activated             (GtkTreeView     *treeview1_etud,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                         gpointer         user_data)
{	etudiant e;
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* id;
	gchar* sexe;
	gchar* niveau;
	gchar* jj1;
	gchar* mm1;
	gchar* aa1;
	
		
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview1_etud);
		if (gtk_tree_model_get_iter(model, &iter, path))
			{gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0 , &nom , 1 , &prenom, 2 , &cin, 3, &id, 4 , &sexe, 5 , &niveau, 6 , &jj1, 7 , &mm1, 8 , &aa1, -1);
		strcpy(e.nom,nom);
		strcpy(e.prenom,prenom);
		strcpy(e.cin,cin);
		strcpy(e.id,id);
		strcpy(e.sexe,sexe);
		strcpy(e.niv,niveau);
		strcpy(e.dte.jour,jj1);
		strcpy(e.dte.mois,mm1);
		strcpy(e.dte.annee,aa1);
		}

}

void
on_buttonr1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *treeview;
GtkWidget *affichageet;
affichageet=lookup_widget(objet_graphique,"affichageet");
treeview=lookup_widget(affichageet,"treeview1_etud");
afficher_etud(treeview);

}


void
on_buttonsuiv2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttons1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonm1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
int j,m,a; 
char chj[6],chm[15],cha[6];
char Niveau[30];
etudiant e;
char s[20];
GtkWidget *entryn;
GtkWidget *entryp;
GtkWidget *entryc;
GtkWidget *entryd;
GtkWidget *comboboxniv1;
GtkWidget *spinbuttonj1;
GtkWidget *spinbuttonm2;
GtkWidget *spinbuttona3;
GtkWidget *sortie1;
entryn=lookup_widget(button, "entry6_etud");
entryp=lookup_widget(button, "entry7_etud");
entryc=lookup_widget(button, "entry8_etud");
entryd=lookup_widget(button,"entry9_etud");
spinbuttonj1=lookup_widget(button, "spinbutton4_etud");
spinbuttonm2=lookup_widget(button, "spinbutton5_etud");
spinbuttona3=lookup_widget(button, "spinbutton6_etud");
comboboxniv1=lookup_widget(button, "combobox2_etud");
sortie1=lookup_widget(button, "label38_etud");
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(entryd)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(entryn)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(entryp)));
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(entryc)));
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonj1)); 
sprintf(chj,"%d",j);
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonm2)); 
sprintf(chm,"%d",m);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttona3)); 
sprintf(cha,"%d",a);
strcpy(e.dte.jour,gtk_entry_get_text(GTK_ENTRY(spinbuttonj1)));
strcpy(e.dte.mois,gtk_entry_get_text(GTK_ENTRY(spinbuttonm2)));
strcpy(e.dte.annee,gtk_entry_get_text(GTK_ENTRY(spinbuttona3)));
if(m==1)
strcpy(s,"femme");
else
{strcpy(s,"homme");}
strcpy(e.sexe,s);
strcpy(Niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxniv1)));
strcpy(e.niv,Niveau);
{modifier_etud(e);
gtk_label_set_text(GTK_LABEL(sortie1),"modification effectuée avec succès!");}
}





void
on_radiobutton3_etud_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{m=1;}

}


void
on_radiobutton4_etud_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{m=2;}
}


void
on_treeview2_etud_row_activated             (GtkTreeView     *treeview2_etud,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{ etudiant e;
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* id;
	gchar* sexe;
	gchar* niveau;
	gchar* jj1;
	gchar* mm1;
	gchar* aa1;
	
		
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview2_etud);
		if (gtk_tree_model_get_iter(model, &iter, path))
			{gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0 , &nom , 1 , &prenom, 2 , &cin, 3, &id, 4 , &sexe, 5 , &niveau, 6 , &jj1, 7 , &mm1, 8 , &aa1, -1);
		strcpy(e.nom,nom);
		strcpy(e.prenom,prenom);
		strcpy(e.cin,cin);
		strcpy(e.id,id);
		strcpy(e.sexe,sexe);
		strcpy(e.niv,niveau);
		strcpy(e.dte.jour,jj1);
		strcpy(e.dte.mois,mm1);
		strcpy(e.dte.annee,aa1);
		}


}


void
on_buttonaf2_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
char nive[20];
GtkWidget *treeview;
GtkWidget *affichage;
GtkWidget *comboboxniv;
comboboxniv=lookup_widget(objet_graphique,"combobox3_etud");
affichage=lookup_widget(objet_graphique,"affichageniveaux");
treeview=lookup_widget(affichage,"treeview2_etud");
strcpy(nive,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxniv)));
afficher_niveaux(nive,treeview);
}


void
on_buttonrch1_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
etudiant e;
GtkWidget *rech;
GtkWidget *alert;
GtkWidget *treeview;
GtkWidget *alert1;
rech=lookup_widget(objet_graphique,"entry11_etud");
alert=lookup_widget(objet_graphique,"label48_etud");
alert1=lookup_widget(objet_graphique,"label49_etud");


strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(rech)));
if ((verifd(e.id)==1))
gtk_label_set_text(GTK_LABEL(alert1),"l'etudiant n'existe pas,réessayez");
if ((veriff(e.id)==0)) 
{gtk_label_set_text(GTK_LABEL(alert),"champs obligatoire!");}
else
{gtk_label_set_text(GTK_LABEL(alert1),"l'etudiant existe ");
rechercher_etud(e);
gtk_entry_set_text(GTK_ENTRY(rech),"");
treeview=lookup_widget(objet_graphique,"treeview1_etud");
afficher_etud_rech(treeview);
}
}
void
on_buttonsupp2_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ 
etudiant e;
GtkWidget *treeview;
GtkWidget *windowsu;
GtkWidget *idsupp;
GtkWidget *alert;
GtkWidget *alert1;
windowsu=lookup_widget(objet_graphique,"affichageet");
treeview=lookup_widget(windowsu,"treeview1_etud");
idsupp=lookup_widget(objet_graphique,"entry11_etud");
alert=lookup_widget(objet_graphique,"label48_etud");
alert1=lookup_widget(objet_graphique,"label49_etud");

strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idsupp)));
if ((verifd(e.id)==1))
{ gtk_label_set_text(GTK_LABEL(alert1),"l'etudiant n'existe pas,réessayez");}

if ((veriff(e.id)==0)) 
{gtk_label_set_text(GTK_LABEL(alert),"champs obligatoire!");}

else 
{gtk_label_set_text(GTK_LABEL(alert1),"l'etudiant est supprimé avec succès ");
supprimer_etud(e);
gtk_entry_set_text(GTK_ENTRY(idsupp),"");
afficher_etud(treeview);}
}




void
on_buttonrr2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageet;
GtkWidget *ajoutet;
affichageet=lookup_widget(button,"affichageet");
gtk_widget_destroy(affichageet);
ajoutet= create_ajoutet();
gtk_widget_show (ajoutet);

}


void
on_buttonrr3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageet;
GtkWidget *modifieret;
modifieret=lookup_widget(button,"modifieret");
gtk_widget_destroy(modifieret);
affichageet= create_affichageet();
gtk_widget_show (affichageet);

}


void
on_buttonrr1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageniveaux;
GtkWidget *modifieret;
affichageniveaux=lookup_widget(button,"affichageniveaux");
gtk_widget_destroy(affichageniveaux);
modifieret= create_modifieret();
gtk_widget_show (modifieret);

}


void
on_button4qq_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageniveaux;
GtkWidget *gestiondesetudiants;
affichageniveaux=lookup_widget(button,"affichageniveaux");
gtk_widget_destroy(affichageniveaux);
gestiondesetudiants= create_gestiondesetudiants();
gtk_widget_show (gestiondesetudiants);


}


void
on_buttonss1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *affichageet;
GtkWidget *ajoutet;
ajoutet=lookup_widget(button,"ajoutet");
gtk_widget_destroy(ajoutet);
affichageet= create_affichageet();
gtk_widget_show (affichageet);
}
///////////////////////////////////////////::slah


int x1;
int x2;




///////////////////////////////////////////////////////
void
on_button_ajouter_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowAjout ;
windowAjout=create_fenetre_ajouter_reclam();
gtk_widget_show(windowAjout);


}

////////////////////////////////////////

void
on_button_add_reclam_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *fenetre_ajouter_reclam;


GtkWidget *input1,*input2;
char texte1[100];
char texte2[100];





input1=lookup_widget(button,"entry_msg_reclam");
input2=lookup_widget(button,"entry_id_reclam");
if(x1==1)
strcpy(texte1,"Nutrition");
else 
strcpy(texte1,"Hebergement");

if(x2==1)
strcpy(texte2,"Validé");
else
strcpy(texte2,"non_validé");

if(l==1)
{
strcpy(r.msg,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.type,texte1);
strcpy(r.etat,texte2);
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input2)));


ajouter_reclamation( r);
}
fenetre_ajouter_reclam=lookup_widget(button,"fenetre_ajouter_reclam");
gtk_widget_destroy(fenetre_ajouter_reclam);
}


void
on_radiobutton3_valide_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=1;}
}


void
on_radiobutton2_heb_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=2;}
}


void
on_radiobutton1_nut_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=1;}
}


void
on_radiobutton4_n_valide_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=2;}
}

///////////////////////AFFICHER////////////////////////////////////////



void
on_button_afficher_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAfficher;
GtkWidget *treeview1;

windowAfficher=lookup_widget(button,"fenetre_afficher_reclam");
windowAfficher=create_fenetre_afficher_reclam();

gtk_widget_show(windowAfficher);

treeview1=lookup_widget(windowAfficher,"treeview1_reclam");

afficher_reclamation(treeview1);
}





void
on_treeview1_reclam_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		afficher_reclamation(treeview);
	}
}

////////////////////////////////////////////////////////
void
on_button1_retour_menu_reclam_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher_reclam;
fenetre_afficher_reclam=lookup_widget(button,"fenetre_afficher_reclam");
gtk_widget_destroy(fenetre_afficher_reclam);
}

///////////////////////////////SUPPRIMER/////////////////////////////////

void
on_button_supprimer_reclam_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAfficher;
GtkWidget *treeview1_reclam;

windowAfficher=lookup_widget(button,"fenetre_afficher_reclam");
windowAfficher=create_fenetre_afficher_reclam();

gtk_widget_show(windowAfficher);

treeview1_reclam=lookup_widget(windowAfficher,"treeview1_reclam");

afficher_reclamation(treeview1_reclam);
}



//////////////////////////RECHERCHER//////////////////////////////////

void
on_button_recherche_reclam_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowRecherche;
windowRecherche=create_fenetre_rechercher1_reclam ();
gtk_widget_show(windowRecherche);

}


void
on_button_recherche_id_reclam_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher1_reclam;
GtkWidget *windowRechercher2_reclam;
GtkWidget *treeview2_reclam;
GtkWidget *input1;
reclamation r;
FILE *f1;
FILE *f2;

int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100];
reclamation rec[100];


input1=lookup_widget(button,"entry_recherche_id");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

// rechercher
f1=fopen("reclamation.txt","r+");
while((c=fgetc(f1)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f1);

f1=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f1,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
strcpy(msg,rec[i].msg);
strcpy(type,rec[i].type);
strcpy(etat,rec[i].etat);
}
}
if (strcmp(id,ident)==0)
	{
	strcpy(r.id,id);
	strcpy(r.msg,msg);
	strcpy(r.type,type);
	strcpy(r.etat,etat);

	ajouter_recherche(r);
	}
else
	{
	strcpy(r.id,"introuvable!");
	strcpy(r.msg,"introuvable!");
	strcpy(r.type,"introuvable!");
	strcpy(r.etat,"introuvable!");
	
	ajouter_recherche(r);

	
	}
	

windowRechercher2_reclam=lookup_widget(button,"fenetre_rechercher2_reclam");
windowRechercher2_reclam=create_fenetre_rechercher2_reclam();

gtk_widget_show(windowRechercher2_reclam);

treeview2_reclam=lookup_widget(windowRechercher2_reclam,"treeview2_reclam");

chercher_reclamation(treeview2_reclam);


fenetre_rechercher1_reclam=lookup_widget(button,"fenetre_rechercher1_reclam");
gtk_widget_destroy(fenetre_rechercher1_reclam);
}






void
on_treeview2_reclam_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		chercher_reclamation(treeview);

	}
}


void
on_button2_retour_menu_reclam_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher2;
fenetre_rechercher2=lookup_widget(button,"fenetre_rechercher2_reclam");
gtk_widget_destroy(fenetre_rechercher2);
}



///////////////////////MODIFIER /////////////////////////////////





void
on_button_modifier_msg_reclam_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data)


{

GtkWidget *output;
GtkWidget *input1,*input2,*combobox1,*combobox2;
FILE *f;

reclamation r;
int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100],message[100];
char text1[100],text2[100];
reclamation rec[100];

/// collect donné ////

input1=lookup_widget(objet_graphique,"entry_id_modifier_reclam");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(objet_graphique,"entry_msg_modifier_reclam");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input2)));

combobox1=lookup_widget(objet_graphique,"combobox1_reclam");
if(strcmp("Nutrition",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))))

	strcpy(text1,"Nutrition");
else
	strcpy(text1,"Hebergement");


combobox2=lookup_widget(objet_graphique,"combobox2_reclam");

if(strcmp("Validé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))))

	strcpy(text2,"Validé");
else
	strcpy(text2,"non_Validé");

strcpy(r.msg,message);
strcpy(r.type,text1);
strcpy(r.etat,text2);
strcpy(r.id,ident);



output=lookup_widget(objet_graphique,"label26");

/// rechercher////

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f);

f=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
}
}

if  (strcmp(id,ident)==0)
	{
	modifier_reclamation(r) ;// modifier 
	gtk_label_set_text(GTK_LABEL(output),"Modification terminer !");
	}





else
	
	gtk_label_set_text(GTK_LABEL(output),"Identifiant introuvable !");
	

}









void
on_button_modifier_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
windowModifier=create_fenetre_modifier_reclam ();
gtk_widget_show(windowModifier);
}


////////////////////////////PLUS RECLAMEE//////////////////////////

void
on_button5_plus_reclamee_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


char type[100];
char text[100];
;

GtkWidget *output;
GtkWidget *fenetre_plusreclame;

output=lookup_widget(objet_graphique,"message_reclam");

int y;
leplusreclamer(y);
if(y==1)
{



fenetre_plusreclame=create_fenetre_plusreclame ();
gtk_widget_show(fenetre_plusreclame);

gtk_label_set_text(GTK_LABEL(output),"hebergement");}
else if(y==2)
{



fenetre_plusreclame=create_fenetre_plusreclame ();
gtk_widget_show(fenetre_plusreclame);

gtk_label_set_text(GTK_LABEL(output),"Nutrition");

}
else
{



fenetre_plusreclame=create_fenetre_plusreclame ();
gtk_widget_show(fenetre_plusreclame);

gtk_label_set_text(GTK_LABEL(output),"Hebergement|Nutrition");

}
}
void
on_button3_retour_menu_reclam_clicked  (GtkButton       *button,
                                        gpointer         user_data)


{
GtkWidget *fenetre_modifier_reclam;
fenetre_modifier_reclam=lookup_widget(button,"fenetre_modifier_reclam");
gtk_widget_destroy(fenetre_modifier_reclam);
}




void
on_checkbutton1_reclam_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}
}


void
on_buttonretourmenu_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_menu_reclam;
fenetre_menu_reclam=lookup_widget(button,"fenetre_menu_reclam");
gtk_widget_destroy(fenetre_menu_reclam);
}


void
on_button5_retour_menu_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_reclam;
fenetre_ajouter_reclam=lookup_widget(button,"fenetre_ajouter_reclam");
gtk_widget_destroy(fenetre_ajouter_reclam);
}


void
on_button6_retour_menu_reclam_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher1_reclam;
fenetre_rechercher1_reclam=lookup_widget(button,"fenetre_rechercher1_reclam");
gtk_widget_destroy(fenetre_rechercher1_reclam);
}


