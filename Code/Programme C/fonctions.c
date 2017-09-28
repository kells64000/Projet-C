#include "fonctions.h"
#include <windows.h> // Fonction sleep
#include <dirent.h> // Lister le contenu d'un dossier
#include <ctype.h> // Fonction toupper
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000


int connexion=NULL; // Variable globale permettant de definir les droits d'un profil utilisateur
int majuscule=0; // Variable globale permettant de ne pas refaire les majuscules si elles ont été faites au moins une fois
int tel=0; // Variable globale permettant de ne pas reformater un telephone si il a été formaté au moins une fois

int Authentification()
{
    connexion=0; // Change d'état suivant le statut de connexion

    char user[]="user";
    char admin[]="admin";
    char mdpUser[]="resu";
    char mdpAdmin[]="root";

    char identifiant[6]=""; // identifiant rentré par l'utilisateur
    char mdp[5]=""; // mdp rentré par l'utilisateur


    while(!((strcmp(identifiant,user)==0 && strcmp(mdp,mdpUser)==0) || (strcmp(identifiant,admin)==0 && strcmp(mdp,mdpAdmin)==0))) // Tant que les identifiants sont correct
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("*************************************\n"); // Présentation
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("*  Projet Algorithmique – Langage C *\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("*************************************\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("Veuillez entrer votre nom d'utilisateur :\n");
        gets(identifiant);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("Veuillez entrer votre mot de passe :\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gets(mdp);
        printf("\n");

        if(!((strcmp(identifiant,user)==0 && strcmp(mdp,mdpUser)==0) || (strcmp(identifiant,admin)==0 && strcmp(mdp,mdpAdmin)==0))) // Si identifiant non correct
        {
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("Identifiant et mot de passe incorrect\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        printf("Veuillez resaisir des identifiants valides !!\n\n");

        identifiant[0]='\0';
        mdp[0]='\0';
        Sleep(1000);
        system("cls");
        }
    }

    if(strcmp(identifiant,user)==0) // Si connexion utilisateur
    {
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("Bienvenue Utilisateur !\n");
    connexion=1;
    }

    if(strcmp(identifiant,admin)==0) // Si connexion administrateur
    {
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("Bienvenue Administrateur !\n");
    connexion=2;
    }

    Sleep(2500);

    return connexion;
}

void MenuAuthentification(int connexion)
{
  int choix=NULL;

  system("cls"); // clean le terminal

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t");

  printf("0) Traitement du fichier\n\n"); // Menu commun au deux profils
  printf("\t\t\t\t\t\t\t\t\t\t\t");
  printf("1) Ajouter un contact\n\n");

  if (connexion==1)
  {
   printf("\t\t\t\t\t\t\t\t\t\t\t");
   printf("2) Quitter le programme\n\n");
  }

  else
  {
   printf("\t\t\t\t\t\t\t\t\t\t\t");
   printf("2) Supprimer un contact\n\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t");
   printf("3) Quitter le programme\n\n");
  }

  printf("\t\t\t\t\t\t\t\t\t\t\t");
  printf("****************************\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t");
  printf("* Que désirez-vous faire ? *\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t");
  printf("****************************\n");
  printf("\n\t\t\t\t\t\t\t\t\t\t\t\t   ");
  scanf("%d",&choix);
  printf("\n");

  switch(choix)
  {
   case 0:
    system("cls");
    TraitementFichier();
    break;

   case 1:
    system("cls");
    AjouterContact();
    break;

   case 2: // si profil utilisateur sortir du programme
    if(connexion==1)
    {
     exit(0);
    }

    else // sinon supprimer un contact
    {
     system("cls");
     SupprimerContact();
    }
    break;

   case 3: // la ligne de sortie du programme en mode administrateur correspond au choix 3
    if(connexion==2)
    {
     exit(0);
    }
    break;

   default:
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("Veuillez rentrer une valeur correcte !!\n");
    system("pause"); // met le terminal en pause
    MenuAuthentification(connexion);
    break;
  }
}

void RetourMenu()
{
    Sleep(1500); // Met le système en pause durant 1.5 seconde

    MenuAuthentification(connexion);
}

void TraitementFichier()
{
    char choix=' ';
    char confirmation=' ';
    char conversionFichier=' ';
    char tab[55][70]; // tableau permettant de récupérer le tableau renvoyé par la fonction RecuperationDonnees

    tab[55][70]=RecuperationDonnees(tab); // tab reçois tableau renvoyé

    printf("\n\nVoici le tableau avant modification: \n\n");

    AffichageTab(tab,55);

    while(choix!='n' && choix!='N')
    {
        Formatage(tab);
        printf("\n\nVoulez-vous appliquer d'autres modifications ? O/N\n");
        scanf("%s",&choix);
    }

    printf("\n\nVoulez-vous que les données soit écrites dans un fichier ? O/N\n");
    scanf("%s",&confirmation);
    printf("\n");

    if(confirmation=='o' || confirmation=='O')
    {
        do
        {
         EcritureDonnees(tab);
         printf("Voulez-vous convertir dans un autre format ? O/N\n");
         scanf("%s",&conversionFichier);
         printf("\n\n");
        }while(conversionFichier=='o' || conversionFichier=='O');
    }

    RetourMenu();
}

char RecuperationDonnees(char tab[54][70])
{
    FILE* fichier;

    char chaine[TAILLE_MAX] = "";
    int i=0;
    char *ptr;
    char *begin;

    fichier=fopen("donnees_ap.csv","r");

    if (fichier!= NULL)
    {
        while(fgets(chaine,TAILLE_MAX,fichier)!= NULL) // Récupère la premiere ligne fichier dans la variable chaine
        {
         begin=chaine;
         ptr=strchr(begin,';');

           while(ptr!=NULL)
            {
            *ptr='\0'; // change le délimiteur trouvé par un retour
            strcpy(tab[i],begin); // copie dans tab[i] ce qui reste de la chaine begin

            begin=ptr+1; // begin reprend apres le delimiteur
            ptr=strchr(begin,';'); // recherche le nouveau délimiteur
            i++;

                if(strchr(begin,';')==NULL) // si la recherche d'un caractère ';' renvoie null
                {
                ptr=strchr(begin,'\n'); // ptr recherche fin de ligne
                *ptr='\0';
                strcpy(tab[i],begin);
                i++; // réincrémentation pour que la prochaine copie n'efface pas celle-ci
                ptr=NULL; // sortir de la boucle
                }
            }
        }
    }

    fclose(fichier);
    return tab[54][70];
}

void AffichageTab(char tab[][70],int i)
{
int j, k;

    for(j=0;j<i;j++)
    {
        switch(j%5)
        {
        case 0:
         printf("%-10s ",tab[j]);
         break;

        case 1:
         printf("%-20s ",tab[j]);
         break;

        case 2:
         printf("%-65s ",tab[j]);
         break;

        case 3:
         printf("%-20s ",tab[j]);
         break;

        case 4:
         printf("%20s ",tab[j]);
         break;
        }

    k=DernierChiffre(j);

        if(k==4 || k==9)
        {
            printf("\n\n");
        }
    }
}

void Majuscule(char tab[][70],int i)
{
    int j, k;
    char *ptr;
    char *t;

    for(j=5;j<i;j++)
    {

        k=DernierChiffre(j);

        if(k==0 || k==1 || k==5 || k==6)
        {
//        *ptr=tab[j][0];
//
//        if (*ptr >= 'a' && *ptr <= 'z')
//        {
//         tab[j][0]=toupper(*ptr);
//        }

            if(majuscule==0) // Permet de ne passer qu'une fois sur cette case
            {
                tab[j][0]= tab[j][0]-32; // le caractère pointé devient une majuscule
            }

            if(strchr(tab[j],'-')!=NULL)
            {
             ptr=strchr(tab[j],'-');
             t=ptr+1; // le pointeur se positionne après le caractère recherché
             *t=toupper(*t); // remplacement du caractère pointé par une majuscule
            }
        }
    }
    majuscule=1;
}

void RemplissageMail(char tab[][70],int i)
{
    char gabarit[]=".viacesi@viacesifr.onmicrosoft.com";
    char temp[400]="";
    char nom[50];
    char separation[]=".";
    int j=5, k=0;

    while(j<i)
    {
    k=DernierChiffre(j);

        if(k==0 || k==5)
        {
        strcpy(nom,tab[j]); // copie du nom dans une chaine temporaire
        }

        if(k==1 || k==6)
        {
        strcat(temp,tab[j]); // met prenom dans le receptacle final
        strcat(temp,separation); // ajoute la séparation
        strcat(temp,nom); // ajoute le nom
        strcat(temp,gabarit); // ajoute le gabarit

        memset(nom,0,sizeof (nom)); // vide la chaine
        }

        if(k==2 || k==7)
        {
        strcpy(tab[j],temp); // inscrit la chaine compléte au bon endroit du tableau
        memset(temp,0,sizeof (temp)); // vide la chaine
        }
    j++;
    }
}

void Telephone(char tab[][70],int i,int afficherRapport)
{
    FILE* FichierIncident=NULL;

    char *ptr;
    char numero[11]="";
    char telephone[11]="";
    char telephoneErrone[20]="";
    int j, k=8,  l;
    int rapportIncident=0;


    while(k<i)
    {
        l=DernierChiffre(k);

        if(l==3 || l==8)
        {
            if(strchr(tab[k],'.'))
            {
                while(strchr(tab[k],'.')!=NULL)
                {
                ptr=strchr(tab[k],'.');
                *ptr=' ';
                }
            }

            if(strchr(tab[k],'/'))
            {
                while(strchr(tab[k],'/')!=NULL)
                {
                ptr=strchr(tab[k],'/');
                *ptr=' ';
                }
            }

            if(tel==0) // permet de ne passer qu'une fois sur cette case
            {
                if(k==48)
                {
                  sprintf(telephone,"%c%c%c%c%c%c%c%c%c%c",(char)tab[k][4],(char)tab[k][5],(char)tab[k][7],(char)tab[k][8],(char)tab[k][10],(char)tab[k][11],(char)tab[k][13],(char)tab[k][14],tab[k][16],tab[k][17]);
                  strcpy(tab[k],telephone);
                }
            }

            if(strchr(tab[k],' '))
           {
             sprintf(numero,"%c%c%c%c%c%c%c%c%c%c",(char)tab[k][0],(char)tab[k][1],(char)tab[k][3],(char)tab[k][4],(char)tab[k][6],(char)tab[k][7],(char)tab[k][9],(char)tab[k][10],tab[k][12],tab[k][13]);
             strcpy(tab[k],numero);
           }
       }
    k++;
    }

    tel=1;

    if (opendir("./incident")==NULL) // Si le dossier incident n'existe pas
    {
     system("md incident"); // Créer le dossier incident
    }

    FichierIncident=fopen("incident/rapport.txt","w");

    for(j=8;j<i;j++)
    {
        l=DernierChiffre(j);

        if(l==3 || l==8)
        {
            if(strlen(tab[j])<10 || strlen(tab[j])>10)
            {
              rapportIncident++;
              strcpy(telephoneErrone,tab[j]);
              fprintf(FichierIncident,"tab[%d] le numero %s n'est pas au bon format\n",j,telephoneErrone);
              tab[j][0]='\0';
              if(rapportIncident==1) // si je trouve un numéro j'affiche la ligne
              {
                  if(afficherRapport==1) // si je désire afficher le rapport dans une autre fonction
                  {
                   printf("Un numéro n'est pas au bon format ! Un rapport d'incident a été créé dans un dossier incident\n");
                  }
              }

            }
        }
    }
    fclose(FichierIncident);
}

void Ddn(char tab[][70],int i)
{
    char convertDate[20];
    int j=9, k;

    while(j<i)
    {
    k=DernierChiffre(j);

        if(k==4 || k==9)
        {
        strcpy(convertDate,tab[j]);
        sprintf(convertDate,"%c%c/%c%c/%c%c%c%c",(char)tab[j][8],(char)tab[j][9],(char)tab[j][5],(char)tab[j][6],(char)tab[j][0],(char)tab[j][1],(char)tab[j][2],(char)tab[j][3]);
        // Vu que le format date ne change pas sprintf comme proposé ici permet de réorganiser au format date demandé
        strcpy(tab[j],convertDate);
        memset(convertDate,0,sizeof (convertDate)); // vide la variable convertDate
        }
    j++;
    }
}

void Formatage(char tab[][70])
{
    int selection=NULL;

    printf("\nListe des différents formatage possible :\n\n");
    printf("0) Majuscule Nom/Prenom \n1) Ajout de mail\n2) Téléphone\n3) Dates de naissance\n4) Ensemble des choix précédent\n\n");
    scanf("%d",&selection);
    printf("\n\n");

    switch(selection)
    {
     case 0:
       Majuscule(tab,55);
       printf("\nVoici le tableau après modification :\n\n");
       AffichageTab(tab,55);
       break;

     case 1:
       RemplissageMail(tab,55);
       printf("\nVoici le tableau après modification :\n\n");
       AffichageTab(tab,55);
       break;

     case 2:
       Telephone(tab,55,1);
       printf("\nVoici le tableau après modification :\n\n");
       AffichageTab(tab,55);
       break;

     case 3:
       Ddn(tab,55);
       printf("\nVoici le tableau après modification :\n\n");
       AffichageTab(tab,55);
       break;

     case 4:
       RemplissageMail(tab,55);
       Majuscule(tab,55);
       Telephone(tab,55,1);
       Ddn(tab,55);
       printf("\nVoici le tableau après modification :\n\n");
       AffichageTab(tab,55);
       break;
    }
}

void EcritureDonnees(char tab[][70])
{
    FILE* fichierTxt=NULL;
    FILE* fichierCsv=NULL;
    FILE* fichierHtml=NULL;

    char nomFichier[20]="";
    char cheminNomExtensionfichier[30]="fichier/";
    char extensionFichier[6]="";
    int choixExtensionFichier=NULL;
    int i, k=0;

    if (opendir("./fichier")==NULL) // Si le dossier fichier n'existe pas
    {
     system("md fichier"); // Créer le dossier fichier
    }

    printf("Veuillez choisir un nom pour le fichier qui va être créé :\n");
    scanf("%s",nomFichier);

    printf("\nListe des formats de fichier possible :\n\n");
    printf("0) Txt\n1) Csv\n2) Html\n\n");
    scanf("%d",&choixExtensionFichier);
    printf("\n\n");

    switch(choixExtensionFichier)
    {
    case 0:
      strcpy(extensionFichier,".txt");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierTxt=fopen(cheminNomExtensionfichier,"w");

      for(i=0;i<55;i++)
      {
        fprintf(fichierTxt,"%s ",tab[i]);
        k=DernierChiffre(i);

        if(k!=4 && k!=9)
        {
        fprintf(fichierTxt,"- ");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierTxt,"\n");
        }
      }
      fclose(fichierTxt);
      break;

    case 1:
      strcpy(extensionFichier,".csv");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierCsv=fopen(cheminNomExtensionfichier,"w");

      for(i=0;i<55;i++)
      {
        fprintf(fichierCsv,"%s",tab[i]);
        k=DernierChiffre(i);

        if(!(k==4 || k==9))
        {
        fprintf(fichierCsv,";");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierCsv,"\n");
        }
      }
      fclose(fichierCsv);
      break;

    case 2:
      strcpy(extensionFichier,".html");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierHtml=fopen(cheminNomExtensionfichier,"w");

      for(i=0;i<55;i++)
      {
        k=DernierChiffre(i);

        if(i==0)
        {
            fprintf(fichierHtml,"<!DOCTYPE html><head><style>table{margin: -25em 20em ; padding: 0 0;}</style></head><html><body><header><table border='1' cellpadding='15'><caption><h2>Fichier contact</h2></caption>");
        }

        if(k==0 || k==5)
        {
            fprintf(fichierHtml," <tr>");
        }

        if(i<5)
        {
        fprintf(fichierHtml,"<th>%s</th>",tab[i]);
        }
        else
        {
            if(i!=42)
            {
             fprintf(fichierHtml,"<td>%s</td>",tab[i]);
            }

            if(i==42)
            {
             fprintf(fichierHtml,"<td style=\"padding: 0.8px 0.8px;\">%s</td>",tab[i]);
            }
        }

        if(k==4 || k==9)
        {
        fprintf(fichierHtml,"</tr><br></br>");
        }

        if(i==54)
        {
           fprintf(fichierHtml,"</table></header></body></html>");
        }
      }
      fclose(fichierHtml);

      break;
    }
}

void AjouterContact()
{
    char tab[104][70]; // Possibilité de rajouter 10 contact
    int j=0, i;
    int doublon=NULL;

    char confirmation=' ';
    char conversionFichier=' ';

    tab[104][70]=RecuperationDonnees(tab);

    printf("Combien voulez-vous rajouter de contact ?\n");
    scanf("%d",&j);

    j=j*5+55;
    i=j;

    Telephone(tab,j,0);
    Ddn(tab,j);

    do
    {
    tab[104][70]=DoublonContact(tab,j,&doublon); // doublon recupère la valeur modifier par le pointeur
        if(doublon==1)
        {
            printf("Vous avez rentré un contact qui existe déja !\n\n");
        }
    }while(doublon==1);

    Telephone(tab,j,1);
    RemplissageMail(tab,j);
    Majuscule(tab,j);

    printf("\n\n");
    AffichageTab(tab,j);
    printf("\n\nVoici le tableau après modifications");

    printf("\n\nVoulez-vous que les données soit écrites dans un fichier ? O/N\n");
    scanf("%s",&confirmation);
    printf("\n");
    j=i; // j récupère la valeur qu'il n'est pas censé perdre ...

    if(confirmation=='o' || confirmation=='O')
    {
        do
        {
         EcritureDonneesAjout(tab,j);
         printf("Voulez-vous convertir dans un autre format ? O/N\n");
         scanf("%s",&conversionFichier);
         printf("\n");
        }while(conversionFichier=='o' || conversionFichier=='O');
    }

    RetourMenu();
}

char DoublonContact(char tab[][70], int j,int *doublon)
{
    int strcmpNom=NULL, strcmpPrenom=NULL, strcmpTel=NULL, strcmpDate=NULL;
    int i, k=0, l;

    char nom[20]="";
    char prenom[20]="";
    char telephone[11]="";
    char dateNaiss[11]="";

     for(i=55;i<j;i++)
    {
        k=DernierChiffre(i);

        if(k==0 || k==5)
        {
         printf("\nVeuillez renseigner un nom au format suivant (fillion) :\n");
         scanf("%s",nom);
         printf("\n");

             for(l=0;l<j;l++)
             {
                 k=DernierChiffre(l);

                 if(k==0 || k==5)
                 {
                     if(strcmp(tab[l],nom)==0)
                     {
                         printf("Attention ce nom est déja utilisé !\n\n");
                         strcmpNom=1;
                     }
                 }
             }
         strcpy(tab[i],nom);
         k=DernierChiffre(i);
        }

        if(k==1 || k==6)
        {
         printf("Veuillez renseigner un prenom au format suivant (bertrand) :\n");
         scanf("%s",prenom);
         printf("\n");

             for(l=0;l<j;l++)
             {
                 k=DernierChiffre(l);

                 if(k==1 || k==6)
                 {
                     if(strcmp(tab[l],prenom)==0)
                     {
                         printf("Attention ce prénom est déja utilisé !\n\n");
                         strcmpPrenom=1;
                     }
                 }
             }
         strcpy(tab[i],prenom);
         k=DernierChiffre(i);
        }

        if(k==3 || k==8)
        {
         printf("Veuillez renseigner un telephone au format suivant (0102030405) :\n");
         scanf("%s",telephone);
         printf("\n");

             for(l=0;l<j;l++)
             {
                 k=DernierChiffre(l);

                 if(k==3 || k==8)
                 {
                     if(strcmp(tab[l],telephone)==0)
                     {
                         printf("Attention ce telephone est déja utilisé !\n\n");
                         strcmpTel=1;
                     }
                 }
             }
         strcpy(tab[i],telephone);
         k=DernierChiffre(i);
        }

        if(k==4 || k==9)
        {
            do
            {
             printf("Veuillez renseigner une date de naissance au format suivant (JJ/MM/AAAA) :\n");
            scanf("%s",dateNaiss);
            printf("\n");
            }while(strlen(dateNaiss)!=10);

             for(l=0;l<j;l++)
             {
                 k=DernierChiffre(l);

                 if(k==4 || k==9)
                 {
                     if(strcmp(tab[l],dateNaiss)==0)
                     {
                         printf("Attention cette date est déja utilisé !\n\n");
                         strcmpDate=1;
                     }
                 }
             }
         strcpy(tab[i],dateNaiss);
         k=DernierChiffre(i);
         printf("\n");
        }
    }

    if((strcmpNom==1 && strcmpPrenom==1) && (strcmpTel==1 || strcmpDate==1))
    {
     *doublon=1; // le pointeur doublon prend la valeur 1
    }
    else
    {
     *doublon=0;
    }
    return tab[j][70];
}

void EcritureDonneesAjout(char tab[][70],int i)
{
    FILE* fichierTxt=NULL;
    FILE* fichierCsv=NULL;
    FILE* fichierHtml=NULL;

    char nomFichier[20]="";
    char cheminNomExtensionfichier[30]="fichierAjout/";
    char extensionFichier[6]="";
    int choixExtensionFichier=NULL;
    int j, k=0;

    if (opendir("./fichierAjout")==NULL)
    {
     system("md fichierAjout");
    }

    printf("Veuillez choisir un nom pour le fichier qui va être créé :\n");
    scanf("%s",nomFichier);

    printf("\nListe des formats de fichier possible :\n\n");
    printf("0) Txt\n1) Csv\n2) Html\n\n");
    scanf("%d",&choixExtensionFichier);
    printf("\n");

    switch(choixExtensionFichier)
    {
    case 0:

      strcpy(extensionFichier,".txt");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierTxt=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        fprintf(fichierTxt,"%s ",tab[j]);
        k=DernierChiffre(j);

        if(k!=4 && k!=9)
        {
        fprintf(fichierTxt,"- ");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierTxt,"\n");
        }
      }
      fclose(fichierTxt);
      break;

    case 1:

      strcpy(extensionFichier,".csv");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierCsv=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        fprintf(fichierCsv,"%s",tab[j]);
        k=DernierChiffre(j);

        if(!(k==4 || k==9))
        {
        fprintf(fichierCsv,";");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierCsv,"\n");
        }
      }
      fclose(fichierCsv);
      break;

    case 2:

      strcpy(extensionFichier,".html");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierHtml=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        k=DernierChiffre(j);

        if(j==0)
        {
            fprintf(fichierHtml,"<!DOCTYPE html><head><style>table{margin: -25em 20em ; padding: 0 0;}</style></head><html><body><header><table border='1' cellpadding='15'><caption><h2>Fichier Ajout contact</h2></caption>");
        }

        if(k==0 || k==5)
        {
            fprintf(fichierHtml," <tr>");
        }

        if(j<5)
        {
        fprintf(fichierHtml,"<th>%s</th>",tab[j]);
        }
        else
        {
            if(j!=42)
            {
             fprintf(fichierHtml,"<td>%s</td>",tab[j]);
            }

            if(j==42)
            {
             fprintf(fichierHtml,"<td style=\"padding: 0.8px 0.8px;\">%s</td>",tab[j]);
            }
        }

        if(k==4 || k==9)
        {
        fprintf(fichierHtml,"</tr><br></br>");
        }

        if(j==i-1)
        {
           fprintf(fichierHtml,"</table></header></body></html>");
        }
      }
      fclose(fichierHtml);
      break;
    }
}

void SupprimerContact()
{
    char tab[104][70];
    char confirmation=' ';
    char validation=' ';
    char conversionFichier=' ';
    int i=0;
    int choix=0, ligneSuivante=0;
    int affichageligne=5;

    tab[i+1][70]=RepTableauAjout(tab,&i);

    do
    {
    printf("Parmis ces contact lequel voulez-vous supprimer ?\n\n");
    printf("Ligne 1 à 11 : ");
    scanf("%d",&choix);
    printf("\n\n");

    choix=choix*5;
    for(choix=choix;choix<i-5;choix++)
    {
        ligneSuivante=choix+5;
        if(ligneSuivante<i)
        {
         strcpy(tab[choix],tab[ligneSuivante]);
        }
    }
    printf("Voulez-vous supprimer d'autre ligne ? O/N\n");
    scanf("%s",&confirmation);
    if(confirmation=='o' || confirmation=='O')
    {
        affichageligne=affichageligne+5;
    }
    }while(confirmation=='o' || confirmation=='O');

    printf("\n\n");
    printf("Voici le tableau après modification :\n\n");

    AffichageTab(tab,i-affichageligne);

    printf("\n\nVoulez-vous que les données soit écrites dans un fichier ? O/N\n");
    scanf("%s",&validation);
    printf("\n");

    if(validation=='o' || validation=='O')
    {
        do
        {
         EcritureDonneesSuppr(tab,i-affichageligne);
         printf("Voulez-vous convertir dans un autre format ? O/N\n");
         scanf("%s",&conversionFichier);
         printf("\n");
        }while(conversionFichier=='o' || conversionFichier=='O');
    }

    RetourMenu();
}

char RepTableauAjout(char tab[][70],int *l)
{
    int i=0,j=0;
    char csv[5]=".csv";
    char nomFichier[50]="";
    char dossier[20]="./fichierAjout/";


    char chaine[TAILLE_MAX] = "";
    char *ptr;
    char *begin;


    DIR * rep = opendir("./fichierAjout");
    FILE* FichierCsv=NULL;

    if (rep != NULL)
    {
     struct dirent * ent;

     seekdir(rep, 2); // permet d'éviter l'affichage de la racine de repertoire('.') && ('..')

     printf("Contenu du dossier fichierAjout trié par fichier csv :\n\n");

        while ((ent = readdir(rep)) != NULL)
        {
            if(strstr(ent->d_name,csv)!=NULL) // si le nom du fichier ne contient pas la chaine '.csv' alors il n'est pas affiché
             {
              printf("%d) %s\n\n",i, ent->d_name);
              strcat(nomFichier,dossier);
              strcat(nomFichier,ent->d_name);
             }
         i++;
        }
    }

    FichierCsv=fopen(nomFichier,"r");

     if (FichierCsv!= NULL)
    {
        while(fgets(chaine,TAILLE_MAX,FichierCsv)!= NULL) // Récupère la premiere ligne fichier dans la variable chaine
        {
         begin=chaine;
         ptr=strchr(begin,';');

           while(ptr!=NULL)
            {
            *ptr='\0'; // change le délimiteur trouvé par un retour
            strcpy(tab[j],begin); // copie dans tab[i] ce qui reste de la chaine begin

            begin=ptr+1; // begin reprend apres le delimiteur
            ptr=strchr(begin,';'); // recherche le nouveau délimiteur
            j++;

                if(strchr(begin,';')==NULL) // si la recherche d'un caractère ';' renvoie null
                {
                ptr=strchr(begin,'\n'); // ptr recherche fin de ligne
                *ptr='\0';
                strcpy(tab[j],begin);
                j++; // réincrémentation pour que la prochaine copie n'efface pas celle-ci
                ptr=NULL; // sortir de la boucle
                }
            }
        }
    }
    *l=j;

    fclose(FichierCsv);

    closedir(rep);

    printf("Voici le tableau avant modification :\n\n");

    AffichageTab(tab,j);

    printf("\n\n");

    return tab[j][70];
}

void EcritureDonneesSuppr(char tab[][70],int i)
{
    FILE* fichierTxt=NULL;
    FILE* fichierCsv=NULL;
    FILE* fichierHtml=NULL;

    char nomFichier[20]="";
    char cheminNomExtensionfichier[30]="fichierSuppr/";
    char extensionFichier[6]="";
    int choixExtensionFichier=NULL;
    int j, k=0;

    if (opendir("./fichierSuppr")==NULL)
    {
     system("md fichierSuppr");
    }

    printf("Veuillez choisir un nom pour le fichier qui va être créé :\n");
    scanf("%s",nomFichier);

    printf("\nListe des formats de fichier possible :\n\n");
    printf("0) Txt\n1) Csv\n2) Html\n\n");
    scanf("%d",&choixExtensionFichier);
    printf("\n");

    switch(choixExtensionFichier)
    {
    case 0:

      strcpy(extensionFichier,".txt");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierTxt=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        fprintf(fichierTxt,"%s ",tab[j]);
        k=DernierChiffre(j);

        if(k!=4 && k!=9)
        {
        fprintf(fichierTxt,"- ");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierTxt,"\n");
        }
      }
      fclose(fichierTxt);
      break;

    case 1:

      strcpy(extensionFichier,".csv");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierCsv=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        fprintf(fichierCsv,"%s",tab[j]);
        k=DernierChiffre(j);

        if(!(k==4 || k==9))
        {
        fprintf(fichierCsv,";");
        }

        if(k==4 || k==9)
        {
        fprintf(fichierCsv,"\n");
        }
      }
      fclose(fichierCsv);
      break;

    case 2:

      strcpy(extensionFichier,".html");
      strcat(nomFichier,extensionFichier);
      strcat(cheminNomExtensionfichier,nomFichier);
      fichierHtml=fopen(cheminNomExtensionfichier,"w");

      for(j=0;j<i;j++)
      {
        k=DernierChiffre(j);

        if(j==0)
        {
            fprintf(fichierHtml,"<!DOCTYPE html><head><style>table{margin: -25em 20em ; padding: 0 0;}</style></head><html><body><header><table border='1' cellpadding='15'><caption><h2>Fichier Supprimer contact</h2></caption>");
        }

        if(k==0 || k==5)
        {
            fprintf(fichierHtml," <tr>");
        }

        if(j<5)
        {
        fprintf(fichierHtml,"<th>%s</th>",tab[j]);
        }
        else
        {
            if(j!=42)
            {
             fprintf(fichierHtml,"<td>%s</td>",tab[j]);
            }

            if(j==42)
            {
             fprintf(fichierHtml,"<td style=\"padding: 0.8px 0.8px;\">%s</td>",tab[j]);
            }
        }

        if(k==4 || k==9)
        {
        fprintf(fichierHtml,"</tr><br></br>");
        }

        if(j==i-1)
        {
           fprintf(fichierHtml,"</table></header></body></html>");
        }
      }
      fclose(fichierHtml);
      break;
    }
}

int DernierChiffre(int i)
{
    i=i%10;

    return i;
}



