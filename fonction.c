//ahmed capteur
#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
enum
{
	REF,
	NOM,
	TYPE,
	COLUMNS
};
enum
{
J,
H,
N,
TE,
COLUMNS1

};

enum
{
JR,
HR,
NR,
TR,
COLUMNS2

};
////auth ou inscript
int verif( char log[],char Pw[])
{
FILE *f=NULL;
int trouve=-1;
char ch1[20],ch2[20];
f=fopen("user.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %s",ch1,ch2)!=EOF);
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;

}
fclose(f);

}
return (trouve);
}
///////////////////////////////////////////calcul
float calcul(int c)
{int i=0,j=0,x;
float a;
char r[100],n[100];
FILE *f;
 
if (c==1)//temperature
{f=fopen("listecapteur.txt","r"); 
	while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
	{
	j++;//total
	if(strcmp("capteurTemperature",n)==0) 
		{i++;//quantite
		
		}
	}

	a=(100*i)/j;//calcul pourcentage
	return a;
fclose(f);
}

else if(c==2)//debiteau
{f=fopen("listecapteur.txt","r"); 
	    
	while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
	{
	j++;
	if(strcmp("capteurDebitEau",n)==0) 
		{i++;}
		
	}

	a=(100*i)/j;//calcul pourcentage
	return a;
fclose(f);
}//

else if(c==3)//fumee
{f=fopen("listecapteur.txt","r"); 
	while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
	{
	j++;
	if(strcmp("capteurFumee",n)==0) 
		{i++;
		
		}
	}

	a=(100*i)/j;//calcul pourcentage  
	return a;
fclose(f);
} //

else if (c==4)//mouvement
{ f=fopen("listecapteur.txt","r"); 
	while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
	{
	j++;
	if(strcmp("capteurMouvement",n)==0) 
		{i++;
		
		}
	}

	a=(100*i)/j;//calcul pourcentage  
	return a;
fclose(f);    
}//

else if (c==5)//autre
{f=fopen("listecapteur.txt","r"); 
	while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
	{
	j++;
	if(strcmp("Autre",n)==0)
		{i++;
		
		}
	}

	a=(100*i)/j;//calcul pourcentage  
	return a;
fclose(f); 
}//
}
//////////////////////////////////////////compt
int compt()
{int j=0,x,a;
char r[100],n[100];
FILE *f;
f=fopen("listecapteur.txt","r"); 
while(fscanf(f,"%s %d %s",&r,&x,&n)!=EOF) 
	{j++;}
a=j;
return a;
fclose(f);
}
/////////////////////////////////////////////ajout

void ajouter_capteur (capteur c)
{
FILE *f;
f=fopen("listecapteur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s\n",c.reference_capteur,c.nom_capteur,c.typeCapteur); 
fclose(f);
}
}

void afficher_capteur (GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

char reference_capteur[20];
char nom_capteur[20];
char typeCapteur[20];
store=NULL;

FILE *f;
capteur c;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column= gtk_tree_view_column_new_with_attributes("reference_capteur",renderer, "text",REF,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

 renderer = gtk_cell_renderer_text_new();
 column= gtk_tree_view_column_new_with_attributes("nom_capteur",renderer, "text",NOM, NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

 renderer = gtk_cell_renderer_text_new();
 column= gtk_tree_view_column_new_with_attributes("typeCapteur",renderer, "text",TYPE,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f= fopen("listecapteur.txt","r");

if (f==NULL)//kano faragh yarja3
	{return;}
else{//sinon yi7ot
f=fopen("listecapteur.txt","a+");
	 while(fscanf(f,"%s %s %s\n",&c.reference_capteur,&c.nom_capteur,&c.typeCapteur)!=EOF)
	{
	gtk_list_store_append (store, &iter);

	gtk_list_store_set (store, &iter,REF,c.reference_capteur, NOM, c.nom_capteur, TYPE, c.typeCapteur, -1);
	}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
    }
}
}

void supprim_capteur(capteur c)
{
capteur c2;
char reference_capteur[20];
char nom_capteur[20];
char typeCapteur[20];
FILE *f,*g;
f=fopen("listecapteur.txt","r");
g=fopen ("tempo.txt","w");

if(f==NULL || g==NULL)
	{return;}
	else
	{ while(fscanf(f,"%s %s %s \n",&c2.reference_capteur,&c2.nom_capteur,&c2.typeCapteur)!=EOF)
		{ if (strcmp(c.reference_capteur,c2.reference_capteur)!=0 || strcmp(c.nom_capteur,c2.nom_capteur)!=0 || strcmp(c.typeCapteur,c2.typeCapteur)!=0 )
		fprintf(g,"%s %s %s \n",c2.reference_capteur,c2.nom_capteur,c2.typeCapteur);
		}//yio93ad yilawej lin yil9a capteur
fclose(f);
fclose(g);
remove ("listecapteur.txt");
rename("tempo.txt","listecapteur.txt");
	}
}



void vider(GtkWidget *liste){//vider liste//////////////////////////

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;

store=NULL;
char reference_capteur[20];
char nom_capteur[20];
char typeCapteur[20];

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
   renderer=gtk_cell_renderer_text_new ();
 column=gtk_tree_view_column_new_with_attributes("reference_capteur",renderer, "text",REF,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 renderer=gtk_cell_renderer_text_new ();
 column= gtk_tree_view_column_new_with_attributes("nom_capteur",renderer, "text",NOM,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 renderer=gtk_cell_renderer_text_new ();
 column=gtk_tree_view_column_new_with_attributes("typeCapteur",renderer, "text",TYPE,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}//faragh
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
}

//////////////affcaptdeff///////////////////////////////////////////////////////////////////
void afficher_capteur_deff (GtkWidget *liste1)
{

 GtkCellRenderer *renderer;

 GtkTreeViewColumn *column1;

 GtkTreeIter iter;

 GtkListStore *store;

char jour[20];
char heure[20];
char numT[20];
char t[20];
store=NULL;
FILE *f;
temp T;

store=gtk_tree_view_get_model(liste1);

if (store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column1= gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",J,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Heure",renderer, "text",H, NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Numero capteur",renderer, "text",N,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);
  renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Temperature",renderer, "text",TE,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);
}

store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



f= fopen("temperaturedeff.txt","r");

if (f==NULL)
{return;}
else {
f=fopen("temperaturedeff.txt","a+");
 while(fscanf(f,"%s %s %s %s\n",T.jour,T.heure,T.numT,T.t)!=EOF)
{ 
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,J,T.jour, H, T.heure, N, T.numT,TE,T.t, -1);
}
 fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste1), GTK_TREE_MODEL (store));
g_object_unref (store);

}


}
///////////historique////////////////
void afficher_capteur_his (GtkWidget *liste1)
{

 GtkCellRenderer *renderer;

 GtkTreeViewColumn *column1;

 GtkTreeIter iter;

 GtkListStore *store;

char jour[20];
char heure[20];
char numT[20];
char t[20];
store=NULL;
FILE *f;

temp T;
store=gtk_tree_view_get_model(liste1);

if (store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column1= gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",J,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Heure",renderer, "text",H, NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Numero capteur",renderer, "text",N,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);
  renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Temperature",renderer, "text",TE,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);
}

store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



f= fopen("temperature.txt","r");

if (f==NULL)
{return;}
else {
f=fopen("temperature.txt","a+");
 while(fscanf(f,"%s %s %s %s\n",T.jour,T.heure,T.numT,T.t)!=EOF)
{ 
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,J,T.jour, H, T.heure, N, T.numT,TE,T.t, -1);
}
 fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste1), GTK_TREE_MODEL (store));
g_object_unref (store);

}


}
////////////////////viderdeff///////////////////////////////////////////////////////////
void viderD(GtkWidget *liste1)
{
 GtkCellRenderer *renderer;
  GtkTreeViewColumn *column1;
  GtkTreeIter iter;
  GtkListStore *store;

store=NULL;
char jour[20];
char heure[20];
char numT[20];
char t[20];
store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste1);
if (store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column1= gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",J,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Heure",renderer, "text",H, NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste1),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Numero capteur",renderer, "text",N,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);
  renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Temperature",renderer, "text",TE,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste1),column1);


}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste1),GTK_TREE_MODEL(store));



}
//verifier/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int verifier1(char ref_capt[])
{
    FILE *f=NULL;
int trouve=0;
char r[100];
char n[100];
int x;
f=fopen("listecapteur.txt","r");  
if(f!=NULL){
while(fscanf(f,"%s %d %s\n",&r,&x,&n)!=EOF) 
{
if(strcmp(ref_capt,r)==0) 
trouve=1;}
fclose(f);
}

	 return (trouve);
}



void chercher_capteur_defecteux(int ch)
{
	int i=0,j,h,num,jour,numcapt,c,p1,p2;
	float T;
	FILE *f=NULL;
	
		switch (ch) {
                    case 1 : {do{
                                printf("donner le jour du mois (du 1er au 29 Novembre):\n");
                                scanf("%d",&jour);
                                }while (jour<1 || jour>29);
                                do{
                                printf("Vous souhaiter filtrer avec une plage horaire?\n");
                                printf("0 Oui \n");
                                printf("1 Non\n");
                                scanf("%d",&c);
                                }while (c!=0 && c !=1);
                                                    switch(c){
                                                       case 0 :{ do {
							   printf("donner une plage horaire alors entre 1h et 24h :\n");
                                                            printf("De :"); 
                                                            scanf("%d",&p1);
                                                            printf("Jusqu'à :");	
                                                            scanf("%d",&p2);
                                                            }while (p1<1 && p2>24);
                                                         f=fopen("temperature.txt","r");  
                                                        while(fscanf(f,"%d %d %d %f",&j,&h,&numcapt,&T)!=EOF)
                                                        { 
                                                        if( j==jour && (T<10.00 || T>30.00) && (h>=p1) && (h<=p2))  
                                                        {i++;
							printf("jour : %d lheure :%d numero capteur: %d valeur hors norme :%.2f\n",j,h,numcapt,T);
                                                        }}
                                                        fclose(f);
                                                        if(i==0)
                                                        printf("\nPas de capteur defectuex le %d \n",jour);
                                                        }
                                                        break;
                                                               
                                                        case 1 :{	
                                                        f=fopen("temperature.txt","r");  
                                                        while(fscanf(f,"%d %d %d %f",&j,&h,&numcapt,&T)!=EOF)
                                                        { 
                                                        if( j==jour && (T<10.00 || T>30.00))  
                                                        {i++;
                                                        printf("jour : %d lheure :%d numero capteur: %d valeur hors norme :%.2f\n",j,h,numcapt,T);
                                                        }}
                                                        fclose(f);
                                                        if(i==0)
                                                        printf("\nPas de capteur defectuex le %d \n",jour);
                                                        }
                                                        break;}}
                        break;
	      
	       case 2 :
			{
			do{
			printf("donner le numéro de capteur (1/2/3):\n");
			scanf("%d",&num);
			}while (num <1 || num>3);

			f=fopen("temperature.txt","r");  
			while(fscanf(f,"%d %d %d %f",&j,&h,&numcapt,&T)!=EOF)
			{ 
			if( numcapt==num && (T<10.00 || T>30.00))  
			{ i++;
			printf("jour : %d lheure :%d numero capteur: %d valeur hors norme :%.2f\n",j,h,numcapt,T);
			}
			} 
			fclose(f);
			if(i==0)
			printf("\nLe capteur numéro '%d' n'est pas defectuex.\n",num);}
			break;
		}


	}

void liste_alarmes(int ch)
{
	int i=0,etat,j,h,num,jour,numcapt;
	
	FILE *f=NULL;
	
		switch (ch) {
		case 1 : {f=fopen("mouvement.txt","r");  
			while(fscanf(f,"%d %d %d %d",&j,&h,&numcapt,&etat)!=EOF)
			{ 
			{if( etat==1 && h>=6 && h<=24)  
			{i++;
			printf("jour : %d lheure :%d numero capteur: %d \n",j,h,numcapt);
			 }}}
			fclose(f);
			if(i==0)
			printf("\nPas de mouvement detecté entre minuit et 6h.\n");
			}
			break;
	       case 2 :
			{
			f=fopen("fumee.txt","r");  
			while(fscanf(f,"%d %d %d %d",&j,&h,&numcapt,&etat)!=EOF)
			{ 
			if( etat==1)  
			{ i++;
			printf("jour : %d lheure :%d numero capteur: %d \n",j,h,numcapt);
			 }
			} 
			fclose(f);
			if(i==0)
			printf("\nPas de détection de fumée.\n");} 
			break;
		}

}


void afficher_liste_alarmes_mouvements(GtkWidget *liste3)
{

GtkCellRenderer *renderer;

 GtkTreeViewColumn *column1;

 GtkTreeIter iter;

 GtkListStore *store;

char j[20];
char h[20];
char numcapt[20];
char etat[20];
store=NULL;
FILE *f;

fum F;
store=gtk_tree_view_get_model(liste3);

if (store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column1= gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",JR,NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste3),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Heure",renderer, "text",HR, NULL);
 gtk_tree_view_append_column(GTK_TREE_VIEW (liste3),column1);

 renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Numero capteur",renderer, "text",NR,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste3),column1);
  renderer = gtk_cell_renderer_text_new();
 column1= gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",TR,NULL);
 gtk_tree_view_append_column (GTK_TREE_VIEW (liste3),column1);
}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



f= fopen("fumee.txt","r");

if (f==NULL)
{return;}
else 
{
	f=fopen("fumee.txt","a+");
	 while(fscanf(f,"%s %s %s %s\n",F.j,F.h,F.numcapt,F.etat)!=EOF) 
	{ if(strcmp(F.etat,"1")==0)
		{
		strcpy(F.etat,"Fumée détectée");
		gtk_list_store_append (store, &iter);

		gtk_list_store_set (store, &iter,JR,F.j, HR, F.h, NR, F.numcapt,TR,F.etat, -1);
		}
	}
	 fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste3), GTK_TREE_MODEL (store));
	g_object_unref (store);

}

}
///////////////emna stock
#ifdef HAVE_CONFIG.H
#include<config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stock.h"
#include<gtk/gtk.h>


enum
{
	IDENTIFIANT,
	TYPE,
	NOM,
	QUANTITE,
	JOUR,
	MOIS,
	ANNEE,
	QUANTITE_RESTANTE,
	COLUMNS,
};



//**********************************Fonction Ajouter**********************************
void ajouter_s(stock s)
{
	
	char nom[30];	
	int identifiant;
	char quantite[30];
	char type[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
FILE *f;
f=fopen("stock.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f,"%d %s %s %s %d %s %s %d\n",s.identifiant,s.type,s.nom,s.quantite,s.d.jour,s.d.mois,s.d.annee,s.quantite_restante);
	 fclose(f);
	}
}

//**********************************Fonction Afficher**********************************
void affichage(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char nom[30];
	char type[30];	
	int identifiant;
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite restante",renderer,"text",QUANTITE_RESTANTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
f=fopen("stock.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("stock.txt","a+");
		while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT, identifiant,TYPE,type,NOM, nom,QUANTITE, quantite, JOUR, jour, MOIS, mois, ANNEE, annee, QUANTITE_RESTANTE, quantite_restante, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
/////////////////////////////////////////////////////////// fonction alerte //////////////////////////
////////////////////////////////////

void alert_stock(stock s)
{
FILE* f;
FILE* f2;
	char nom[30];
	char type[30];
	int identifiant;
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
	
f=fopen("stock.txt","r");
f2=fopen("alerte.txt","w");
	while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
	{  if (quantite_restante ==0)
		{
		fprintf(f2,"%d %s %s %s %d %s %s %d\n",identifiant,type,nom,quantite,jour,mois,annee,quantite_restante);
		}
	}
	fclose(f);
	fclose(f2);
}
/*=================================fonction afficher alerte stock =================================*/
void afficher_alert_stock(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[30];
	int identifiant;
	char type[30];
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
	store=NULL;

FILE *f;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite restante",renderer,"text",QUANTITE_RESTANTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
f=fopen("alerte.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("alerte.txt","a+");
		while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT, identifiant,TYPE,type,NOM, nom,QUANTITE, quantite, JOUR, jour, MOIS, mois, ANNEE, annee, QUANTITE_RESTANTE, quantite_restante, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}










//**********************************Fonction Supprimer**********************************

void supprimer_s(stock s)

{

	char nom[30];
	char type[30];
	int identifiant;
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;

FILE *f,*g;
f=fopen("stock.txt","r");
g=fopen("temp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
	{
	if(s.identifiant!=identifiant|| strcmp(s.type,type)!=0 ||strcmp(s.nom,nom)!=0 || strcmp(s.quantite,quantite)!=0 ||
	 s.d.jour!=jour || strcmp(s.d.mois,mois)!=0 || strcmp(s.d.annee,annee)!=0|| s.quantite_restante!=quantite_restante )
	fprintf(g,"%d %s %s %s %d %s %s %d\n",identifiant,type,nom,quantite,jour,mois,annee,quantite_restante);

	}
fclose(f);
fclose(g);
remove("stock.txt");
rename("temp.txt","stock.txt");
}
}

/*=================================fonction Modifier=================================*/

void modifier_s(stock s)
{
FILE *f;
FILE *t;

	int identifiant;
	char type[30];
	char nom[30];
	char quantite[30];
	int quantite_restante;
	int jour;
	char mois[30];
	char annee[30];
f=fopen("stock.txt","r");
t=fopen("temp.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&s.d.jour,s.d.mois,s.d.annee,&quantite_restante)!=EOF)
	{
		
		if(s.identifiant==identifiant)
		{
			fprintf(t,"%d %s %s %s %d %s %s %d\n",s.identifiant,type,s.nom,s.quantite,s.d.jour,s.d.mois,s.d.annee,s.quantite_restante);
		}
		else
			fprintf(t,"%d %s %s %s %d %s %s %d\n",identifiant,type,nom,quantite,s.d.jour,s.d.mois,s.d.annee,quantite_restante);
    	}
    }
	
fclose(t);
fclose(f);
remove("stock.txt");
rename("temp.txt","stock.txt");
}



/*=================================fonction verifier ID=================================*/
int verifier(stock s)
{
FILE *f;
	char nom[30];
	char type[30];
	int identifiant1;
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
	int t,test=0;


f=fopen("stock.txt","r");

    if (f!=NULL)
    {
    while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant1,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
	{
		if(s.identifiant==identifiant1)
		{
		test++;
		}
	}
		if(test!=0)
		{
		t=1;
		}
		if(test==0)
		t=2;
    }
return t;
}


/*=================================fonction rechercher stock=================================*/
void chercher_s(stock s)  
{
FILE* f; 
FILE* f1;
	char nom[30];
	int identifiant;
	char type[30];
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;

f=fopen("stock.txt","r");
f1=fopen("stockcher.txt","w");
 	while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
	{
		if (s.identifiant==identifiant)
		{
		fprintf(f1,"%d %s %s %s %d %s %s %d\n",identifiant,type,nom,quantite,jour,mois,annee,quantite_restante);
		}
	}
	fclose(f);
	fclose(f1);
}



/*=================================fonction afficher rechercher produit=================================*/
void afficher_s_chercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[30];
	char type[30];
	int identifiant;
	char quantite[30];
	int jour;
	char mois[30];
	char annee[30];
	int quantite_restante;
	store=NULL;


FILE *f;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("quantite restante",renderer,"text",QUANTITE_RESTANTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
f=fopen("stockcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("stockcher.txt","a+");
		while(fscanf(f,"%d %s %s %s %d %s %s %d\n",&identifiant,type,nom,quantite,&jour,mois,annee,&quantite_restante)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,IDENTIFIANT, identifiant,TYPE,type,NOM, nom,QUANTITE, quantite, JOUR, jour, MOIS, mois, ANNEE, annee, QUANTITE_RESTANTE, quantite_restante, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
/////////////////salah  reclamation
#ifdef HAVE_CONFIG_H
# include<config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
#include<gtk/gtk.h>


enum
{
	EMSG,
	ETYPE,
	EETAT,
	EID,
	COLUMNS,
};



//////////////AJOUTER RECLAMATION //////////////////


void ajouter_reclamation(reclamation r)
{

FILE *f;
f=fopen("reclamation.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
fclose(f);
}
}


////////////AFFICHER RECLAMATION /////////////////


void afficher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char msg[100];
	char type[100];
	char etat[100];
	char id[100];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("msg",renderer,"text",EMSG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",msg,type,etat,id)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,EMSG,msg,ETYPE,type,EETAT,etat,EID,id,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}
}



///////////////////////SUPPRIMER RECLAMATION///////////////////


void supprimer_reclamation(reclamation r)

{
reclamation r2;
FILE *f , *g;
	
	f=fopen("reclamation.txt","r");
	g=fopen("reclamation2.txt","w");

	if(f==NULL || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s \n",r2.msg,r2.type,r2.etat,r2.id)!=EOF)
		{
		  if(strcmp(r.msg,r2.msg)!=0 || strcmp(r.type,r2.type)!=0 ||
			 strcmp(r.etat,r2.etat)!=0 || strcmp(r.id,r2.id)!=0)
		   {
		     fprintf(g,"%s %s %s %s \n",r2.msg,r2.type,r2.etat,r2.id);
		    }
		}
		fclose(f);
		fclose(g);
remove("reclamation.txt");
rename("reclamation2.txt","reclamation.txt");
	}
}

/////////////////RECHERCHER RECLAMATION////////////////////


void chercher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char msg[100];
	char type[100];
	char etat[100];
	char id[100];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("msg",renderer,"text",EMSG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("recherche.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("recherche.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",msg,type,etat,id)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,EMSG,msg,ETYPE,type,EETAT,etat,EID,id,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}
	remove("recherche.txt");
        
	
}



void ajouter_recherche(reclamation r)
{

FILE *f;
f=fopen("recherche.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
fclose(f);
}
}

///////////////MODIFIER RECLAMATION///////////////////////////

void modifier_reclamation(reclamation r)
{
int i,d=0;
char c;
reclamation rec[100];
FILE *f, *tempo;

f=fopen("recamation.txt","a+");
tempo=fopen("tempo.txt","a+");

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 	{
  	if(c=='\n')
  	d++;
 	}
fclose(f);

f=fopen("reclamation.txt","r");
tempo=fopen("tempo.txt","a+");
for (i=0;i<d;i++)
	{
	fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	if(strcmp(r.id,rec[i].id)==0)
		{
		strcpy(rec[i].msg,r.msg);
		strcpy(rec[i].type,r.type);
		strcpy(rec[i].etat,r.etat);
		strcpy(rec[i].id,r.id);
		}
	
	fprintf(tempo,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	}
fclose(f);
fclose(tempo);
remove("reclamation.txt");
rename("tempo.txt","reclamation.txt");
}

////////////////////// LE PLUS RECLAMEE//////////////////////////

void leplusreclamer(int y)
{
int i,d=0,h=0,n=0;
FILE *f;
char c;
reclamation rec[100];



f=fopen("reclamation.txt","r");
while((c=fgetc(f)) !=EOF )
 	{
  	if(c=='\n')
  	d++;
 	}


for (i=0;i<d;i++)
	{
	fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	if(strcmp(rec[i].type,"Nutrition")==0)
		n++;
	else
		h++;
	}
if (n>h)
	{
	y=1;
	
	}
	
else if(n<h)
	{
	y=2;
	
	}
else
	{
	y=3;
	
	}
fclose(f);
}
///////////////////////////////yesmine admin



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fonctionsadmin.h"
#include<gtk/gtk.h>

enum
{
	NOM,
	PRENOM,
	ID,
	SEXE,
	POSTE,
	JOUR,
	MOIS,
	ANNEE,
	MDP,
	COLUMNS
};
//////////////////////////////////////////

void ajouter_user(user u)
{
	char nom[30];
	char prenom[30];
	char id[30];
	char sexe[30];
	char poste[30];
	char mdp[30];
	int jour;
	int mois;
	int annee;

FILE *f;
f=fopen("utilisateur.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s  %d %d %d %s \n",u.nom,u.prenom,u.id,u.sexe,u.poste,u.date.jour,u.date.mois,u.date.annee,u.mdp);
fclose(f);

}



}

//////////////////////////////////////////


///////////////////////////////////////////////////

void afficher_user(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;


	char nom[100];
	char prenom[100];
	char id[100];
	char sexe[100];
	char poste[100];
	char mdp[100];
	int jour;
	int mois;
	int annee;
	
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" poste",renderer,"text",POSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,&jour,&mois,&annee,mdp)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, NOM, nom, PRENOM, prenom,ID, id, SEXE, sexe, POSTE, poste, JOUR, jour, MOIS, mois, ANNEE, annee, MDP, mdp, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
//////////////////////////////////////////////////
void modifier_user(user u)


{

FILE *f;
FILE *t;
	 char nom[30];
	char prenom[30];
	char id[30];
	char poste[30];
	char sexe[30];
	char mdp[30];
	int jour;
	int mois;
	int annee;
	//char num[30];

f=fopen("utilisateur.txt","r");
t=fopen("utilis.txt","a");

    if (f!=NULL || t!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %s %d %d %d %s \n",nom,prenom,id,sexe,poste,&jour,&mois,&annee,mdp)!=EOF)
    {

        if(strcmp(u.id,id)==0)
        {
            fprintf(t,"%s %s %s %s %s %d %d %d %s\n",u.nom,u.prenom,u.id,u.sexe,u.poste,u.date.jour,u.date.mois,u.date.annee,u.mdp);
        }
        else
            fprintf(t,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,jour,mois,annee,mdp);
        }
    }

fclose(t);
fclose(f);
remove("utilisateur.txt");
rename("utilis.txt","utilisateur.txt");
}









//////////////////////////////////////
void supprimer_user(user u)
{

	char nom[30];
	char prenom[30];
	char id[30];
	char sexe[30];
	char poste[30];
	char mdp[30];
	int jour;
	int mois;
	int annee;
	
FILE *f,*g;

f=fopen("utilisateur.txt","r");
g=fopen("dump.txt","w");


if (f==NULL || g==NULL)
{
return;
}
else
{ 


	while(fscanf(f,"%s %s %s %s %s %d %d %d %s",nom,prenom,id,sexe,poste,&jour,&mois,&annee,mdp)!=EOF)
	{
	if(strcmp(u.nom,nom)!=0 || strcmp(u.prenom,prenom)!=0 || strcmp(u.id,id)!=0 ||strcmp(u.sexe,sexe)!=0 || strcmp(u.poste,poste)!=0 || u.date.jour!=jour ||u.date.mois!=mois || u.date.annee!=annee || strcmp(u.mdp,mdp)!=0)

	fprintf(g,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,jour,mois,annee,mdp);	
	
	}
}
fclose(f);
fclose(g);

remove("utilisateur.txt");
rename("dump.txt","utilisateur.txt");

}




///////////////////////////////
void chercher_user( user u)
{
FILE* f; 
FILE* f1;
	char nom[30];
	char prenom[30];
	char id[30];
	char sexe[30];
	char poste[30];
	char mdp[30];
	int jour;
	int mois;
	int annee;
	

	//char num[30];

f=fopen("utilisateur.txt","r");
f1=fopen("utilcher.txt","w");
 	while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,&jour,&mois,&annee,mdp)!=EOF)
	{
		if (strcmp(u.id,id)==0)
		{
		fprintf(f1,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,jour,mois,annee,mdp);
		}
	}
	fclose(f);
	fclose(f1);
//remove("utilisateurchercher.txt");
//rename ("utilcher.txt","utilisateurchercher.txt");
}
//-------------------Affichage de rechercher---------------
void afficher_A_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	char nom[30];
	char prenom[30];
	char id[30];
	char sexe[30];
	char poste[30];
	char mdp[30];
	int jour;
	int mois;
	int annee;
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" poste",renderer,"text",POSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen("utilcher.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilcher.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s\n",nom,prenom,id,sexe,poste,&jour,&mois,&annee,mdp)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, NOM, nom, PRENOM, prenom,ID, id, SEXE, sexe, POSTE, poste, JOUR, jour, MOIS, mois, ANNEE, annee, MDP, mdp, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}








/*void chercher_user(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char nom[100];
	char prenom[100];
	char id[100];
	char poste[100];
	
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("poste",renderer,"text",EPOSTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("recherche.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("recherche.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",nom,prenom,id,poste)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,ENOM,nom,EPRENOM,prenom,EID,id,EPOSTE,poste,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}
	remove("recherche.txt");
        
	
}


/*=================================fonction verifier ID=================================*/
int exist_id(char* id){
FILE*f=NULL;
user u;
f=fopen("utilisateur.txt","r");// ouverture du fichier plante en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %d %d %d %s \n",u.nom,u.prenom,u.id,u.sexe,u.poste,&u.date.jour,&u.date.mois,&u.date.annee,u.mdp)!=EOF){
if(strcmp(u.id,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}
//fonction verifier ID
int verifier_ID_inscrit(char id[30])
{ 
FILE*f=NULL;
user u;
f=fopen("utilisateur.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %d %d %s \n",u.nom,u.prenom,u.id,u.sexe,u.poste,&u.date.jour,&u.date.mois,&u.date.annee,u.mdp)!=EOF){
if((strcmp(u.id,id)==0)||(strcmp(id,"admin")==0))
return 1; //existe   
}
fclose(f);
return 0; //n'existe pas
}

//fonction verifier PASSEWORD
int verifier_PASSWORD_inscrit(char password[30])
{ 
if(strcmp("admin",password)==0)
	{
	return 0; //Administrateur  
	}else
if(strcmp("stock",password)==0)
	{
	return 1; //Agent de stock 
	}else
if(strcmp("foyer",password)==0)
	{
	return 2; //Agent de Foyer  
	}else
if(strcmp("nutritioniste",password)==0)
	{
	return 3; //nutritionniste  
	}else
if(strcmp("technicien",password)==0)
	{
	return 4; //technicien  
	}else
if(strcmp("restaurant",password)==0)
	{
	return 5; //Agent de restaurant  
	}else
if(strcmp("etudiant",password)==0)
	{
	return 6; //reclamation  
	}else
  
	
{ return 7; }

}

/////////////mariem gestion foyer
#include"etudiant.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

enum{ENOM,EPRENOM,ECIN,EID,ESEXE,ENIVEAU,EDATE,COLUMNS};
enum{ENOMM,EPRENOMM,ECINN,EIDD,ESEXEE,ENIVEAUU,EDATEE,COLUMNSS};




void ajouter_etud(etudiant e)
{FILE *f;
f=fopen("etuds.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s %s %s \n",e.nom,e.prenom,e.cin,e.id,e.sexe,e.niv,e.dte.jour,e.dte.mois,e.dte.annee);}
fclose(f);
}

 int verifd(char id[])
{
   etudiant e;
   int res = 1;
   FILE *f;
   f = fopen("etuds.txt", "a+");
   if (f != NULL)
   {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",e.nom,e.prenom,e.cin,e.id,e.niv,e.sexe,e.dte.jour,e.dte.mois,e.dte.annee)!=EOF)
      {
         if (strcmp(id,e.id) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int veriff(char x[])
{
   int i;
   if (strcmp(x,"")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
return i;}

void afficher_etud(GtkWidget* liste)
{	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
etudiant e;
char Nom[30];
char Prenom[30];
char Cin[30];
char Id[30];
char Niveau[30];
char Date[100];
char Sexe[30];
char jj[20],mm[20],aa[20];

store=NULL;
FILE* f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("etuds.txt","r");
if(f==NULL)
{return;}
else
{f=fopen("etuds.txt","a+");
while(fscanf(f," %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Cin,Id,Sexe,Niveau,jj,mm,aa)!=EOF)
{

gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ENOM,Nom,EPRENOM,Prenom,ECIN,Cin,EID,Id,ESEXE,Sexe,ENIVEAU,Niveau,EDATE,strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa),-1);
}
  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
  g_object_unref(store);}}


void rechercher_etud(etudiant e)
{FILE* f;
FILE* f1;
char nom [20];
char prenom [20];
char cin[20];
char id[20];
char sexe [20];
char niveau[20];
char jj[20];
char mm[20];
char aa[20];
f=fopen("etuds.txt","r");
f1=fopen("recherche.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,id,sexe,niveau,jj,mm,aa)!=EOF)
{
if (strcmp(e.id,id)==0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,id,sexe,niveau,jj,mm,aa);
}
}
fclose(f);
fclose(f1);}
void afficher_etud_rech(GtkWidget* liste)
{	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
etudiant e;
char Nom[30];
char Prenom[30];
char Cin[30];
char Id[30];
char Niveau[30];
char Date[100];
char Sexe[30];
char jj[20],mm[20],aa[20];

store=NULL;
FILE* f1;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f1=fopen("recherche.txt","r");
if(f1==NULL)
{return;}
else
{f1=fopen("recherche.txt","a+");
while(fscanf(f1," %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Cin,Id,Sexe,Niveau,jj,mm,aa)!=EOF)
{

gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ENOM,Nom,EPRENOM,Prenom,ECIN,Cin,EID,Id,ESEXE,Sexe,ENIVEAU,Niveau,EDATE,strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa),-1);
}
  fclose(f1);
  gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
  g_object_unref(store);}}
void supprimer_etud(etudiant e)
{
char nom [20];
char prenom [20];
char cin[20];
char id[20];
char sexe [20];
char niveau[20];
char jj[20];
char mm[20];
char aa[20];
FILE* f;
FILE *f2;
f=fopen("etuds.txt","r");
f2=fopen("supp.txt","a+");
if(f2!=NULL){
  if(f!=NULL)
{while(fscanf(f," %s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,id,sexe,niveau,jj,mm,aa)!=EOF)
{
   if(strcmp(e.id,id)!=0)
fprintf(f2,"%s %s %s %s %s %s %s %s %s \n",nom,prenom,cin,id,sexe,niveau,jj,mm,aa);
}}fclose(f);
fclose(f2);
remove("etuds.txt");
rename("supp.txt","etuds.txt");
}}

void modifier_etud(etudiant e)
{  supprimer_etud(e);
   ajouter_etud(e);

}
void afficher_niveaux(char niv[30],GtkWidget* liste)
 {       GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
etudiant e;
char nom [20];
char prenom [20];
char cin[20];
char id[20];
char sexe [20];
char niveau[20];
char jj[20];
char mm[20];
char aa[20];
store=NULL;
FILE* f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOMM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOMM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",ECINN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EIDD,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",ENIVEAUU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNSS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("etuds.txt","r");
if(f==NULL)
{return;}
else
{
while(fscanf(f," %s*** %s*** %s*** %s*** %s*** %s*** %s*** %s*** %s*** \n",&nom,&prenom,&cin,&id,&sexe,&niveau,&jj,&mm,&aa)!=EOF)
{ if (strcmp(niv,niveau)==0)

{gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ENOMM,nom,EPRENOMM,prenom,ECINN,cin,EIDD,id,ESEXEE,sexe,ENIVEAUU,niv,EDATEE,strcat(strcat(strcat(strcat(jj,"/"),mm),"/"),aa),-1);
}
  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
  g_object_unref(store);}}}

//////////aziz menu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "menu.h"
enum{
	HID,
	HFN,
	HLN,
	HG,
	HRN,
	HRF,
	HRT,
        HCL,
	COLUMNS
};
void add_menu(menu e,char *file){
	FILE *f;
	f=fopen(file,"a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,e.day,e.dechets,e.size,e.type,e.cal);
	}
	fclose(f); 
}

void modify_menu(menu e,char *file)
{
menu e1;

FILE* f=fopen(file,"r+");
FILE* g=fopen("tmp.txt","w");
if(f!=NULL)
{
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",e1.id,e1.meal,e1.dessert,&e1.day,&e1.dechets,e1.size,e1.type,e1.cal)!=EOF)
	{
		
		if(strcmp(e.id,e1.id)==0)
		{
			fprintf(g,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,e.day,e.dechets,e.size,e.type,e.cal);
		}
		else
		{
			fprintf(g,"%s %s %s %d %d %s %s %s\n",e1.id,e1.meal,e1.dessert,e1.day,e1.dechets,e1.size,e1.type,e1.cal);
		}

	}
}
fclose(f);
fclose(g);
remove(file);
rename("tmp.txt",file);
}
void delete_menu(char id_menu[20],char *file){
	menu e;
	FILE *f,*ftmp;
	f=fopen(file,"r");
	ftmp=fopen("tmp.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,&e.day,&e.dechets,e.size,e.type,e.cal)!=EOF)
		{
			if(strcmp(e.id,id_menu)!=0){
				fprintf(ftmp,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,e.day,e.dechets,e.size,e.type,e.cal);
			}
		}
	fclose(ftmp);
	fclose(f);
	remove(file);
	rename("tmp.txt",file);	
}

void search_menu(char id_menu[20],char *file){
	menu e;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("search.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,&e.day,&e.dechets,e.size,e.type,e.cal)!=EOF){
		if(strcmp(e.id,id_menu)==0){
			fprintf(g,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,e.day,e.dechets,e.size,e.type,e.cal);
		}
	}
	fclose(f);
	fclose(g);
}

void display_menu_ONtreeview(GtkWidget *list,char *file){
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	menu h;
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(list);
	if(store==NULL){
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",HID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Meal",renderer,"text",HFN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",HLN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Size",renderer,"text",HG,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
 
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Day",renderer,"text",HRN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("dechets",renderer,"text",HRF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",HRT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
                 

                renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Calorie",renderer,"text",HCL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

		
		 
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen(file,"r");
	if(f==NULL){return;}
	else
	{
		 while(fscanf(f,"%s %s %s %d %d %s %s %s\n",h.id,h.meal,h.dessert,&h.day,&h.dechets,h.size,h.type,h.cal)!=EOF)
		 {
			
			gtk_list_store_append(store,&iter);
			
		  	gtk_list_store_set(store,&iter,HID,h.id,HFN,h.meal,HLN,h.dessert,HG,h.size,HRN,h.day,HRF,h.dechets,HRT,h.type,HCL,h.cal,-1);
		 }
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}

}




void meilleur_menu(  char *file)
{ 
menu e;
int dechets1=100,day1;
char dessert1[20],type1[20],meal1[20],cal1[20],size1[20],id1[20];
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("best.txt","a+");
	while(fscanf(f,"%s %s %s %d %d %s %s %s\n",e.id,e.meal,e.dessert,&e.day,&e.dechets,e.size,e.type,e.cal)!=EOF){
		if(e.dechets<dechets1){
			dechets1=e.dechets;
			strcpy(id1,e.id);
			day1=e.day;
			strcpy(dessert1,e.dessert);
			strcpy(size1,e.size);
			strcpy(type1,e.type);
			strcpy(cal1,e.cal);
			strcpy(meal1,e.meal);
		}
	}
fprintf(g,"%s %s %s %d %d %s %s %s\n",id1,meal1,dessert1,day1,dechets1,size1,type1,cal1);
	fclose(f);
	fclose(g);
}
	   
 	






