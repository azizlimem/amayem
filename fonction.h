//ahmed capteur
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
char reference_capteur[20];
char nom_capteur[20];
char typeCapteur[20];
}capteur;

//capteur c;

typedef struct{
char jour[20];
char heure[20];
char numT[20];
char t[20];
}temp;

//temp T1,T2;

typedef struct{
char j[20];
char h[20];
char numcapt[20];
char etat[20];
}fum;

//fum F;
int verif( char log[],char Pw[]);
void ajouter_capteur (capteur c);
void afficher_capteur (GtkWidget *liste);
void supprim_capteur(capteur c);
void vider(GtkWidget *liste);

int verifier1(char ref_capt[]);

void afficher_capteur_deff (GtkWidget *liste1);
void viderD(GtkWidget *liste1);



void afficher_liste_alarmes_mouvements(GtkWidget *liste3);

int compt();
float calcul(int c);
//emna stock
#include<gtk/gtk.h>


typedef struct date {
int jour;
char mois[40];
char annee[40];
}date;

typedef struct stock {
char nom[40];
int identifiant;
char type[40];
char quantite[40];
int quantite_restante;
date d;
}stock;
//déclaration des fonctions 

void ajouter_s(stock s);
void chercher_s (stock s);
void supprimer_s(stock s);
void modifier_s(stock s);
void affichage (GtkWidget *liste);
void afficher_s_chercher(GtkWidget *liste);
int verifier (stock s);
void alert_stock(stock s);
void afficher_alert_stock(GtkWidget *liste);

int s;
int x;
int l;
int r;
//salah reclamation
#include<gtk/gtk.h>

typedef struct
{

char msg[100];
char type[100];
char etat[100];
char id[100];

}reclamation;

void ajouter_reclamation(reclamation r);

void afficher_reclamation(GtkWidget *liste);

void supprimer_reclamation(reclamation r);

void chercher_reclamation(GtkWidget *liste);

void modifier_reclamation(reclamation r);
/*
void leplusreclamer(char type[100]);
*/
int l;
//yesmine admin
#include<gtk/gtk.h>
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct Date
{
int jour;
int mois;
int annee;
}Date;
typedef struct user {
char nom[30];
char prenom[30];
char mdp[30];
char sexe[30];
char id[30];
char poste[100];
Date date;
}user;

void ajouter_user(user u);
void supprimer_user(user u);
void modifier_user(user u);
void afficher_user(GtkWidget *liste);
void chercher_user(user u);
/*void afficher_u_chercher(GtkWidget *liste);*/
/*int verifier (user u);*/
int exist_id(char* id);
int verifier_ID_inscrit(char id[30]);
void afficher_A_rechercher(GtkWidget *liste);
int verifier_PASSWORD_inscrit(char password[30]);
int radio;

#endif // FONCTION_H_INCLUDED
//mariem gestion foyer
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct date1
{
    char jour[20];
    char mois[20];
    char annee[20];

}date1;
typedef struct etudiant
{ char nom[30];
  char prenom[30];
  char cin[30];
  char id[30];
  char sexe[30];
  char niv[30];
  date1 dte;}etudiant;
void afficher_etud(GtkWidget* treeview);
void ajouter_etud(etudiant e);
void supprimer_etud(etudiant e);
void rechercher_etud(etudiant e);
void modifier_etud(etudiant e);
int verifd(char id[]);
int veriff(char x[]);
void afficher_niveaux(char niveau[],GtkWidget* treeview);
void afficher_etud_rech(GtkWidget* liste);
//aziz menu
#include <gtk/gtk.h>
typedef struct{
	char id[20];
	char meal[20];
	char dessert[20];
	int day;
	int dechets;
	char type[20];
        char size[20] ;
        char cal[20];
}menu;

void add_menu(menu m,char *file);
void modify_menu(menu e,char *file);
void delete_menu(char id_menu[20],char *file);
void display_menu(char *file);
void search_menu(char id_menu[20],char *file);
void display_menu_ONtreeview(GtkWidget *list,char *file);
void meilleur_menu(  char *file);

