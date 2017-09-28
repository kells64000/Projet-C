#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

// Fonction lié à la connexion et au menu

int Authentification(); // Fonction d'authentification

void MenuAuthentification(int connexion); // Menu suivant le profil utilisateur

void RetourMenu(); // Fonction qui renvoie au menu d'authentification


// Fonction lié au formatage du fichier source

void TraitementFichier(); // Fonction globale du processus de formatage du fichier source

char RecuperationDonnees(char tab[54][70]); // Fonction qui récupère les données du fichier source et les enregistrent dans un tableau

void AffichageTab(char tab[][70],int i); // Permet d'afficher le tableau du fichier csv

void Majuscule(char tab[][70],int i); // Met les majuscules au nom et prenom

void RemplissageMail(char tab[][70], int i); // Remplis les champs mail

void Telephone(char tab[][70],int i,int afficherRapport); // Permet de mettre les téléphone au format demandé

void Ddn(char tab[][70],int i); // Met les dates de naissances au format demandé

void Formatage(char tab[][70]); // Menu proposant différent formatage possible

void EcritureDonnees(char tab[][70]); // Permet d'écrire le contenu du tableau formaté dans un fichier pour l'extension choisi ( .txt,.csv,.html )


// Fonction lié à l'ajout de contact

void AjouterContact(); // Fonction d'ajout de contact

char DoublonContact(char tab[][70], int j,int *doublon); // Fonction qui examine si des doublons sont créé

void EcritureDonneesAjout(char tab[][70],int i); // Fonction ecriture de fichier dédié à l'ajout (car repertoire d'écriture différent)


// Fonction lié à la suppression de contact

void SupprimerContact(); // Fonction de suppression de contact

char RepTableauAjout(char tab[][70],int *l); // Fonction qui lit un repertoire, ouvre un fichier csv et met dans un tableau les données

void EcritureDonneesSuppr(char tab[][70],int i); // Fonction ecriture de fichier dédié à l'ajout (car repertoire d'écriture différent)


// Fonction support

int DernierChiffre(int i); // Fonction qui renvoie le dernier chiffre d'un nombre


#endif // FONCTIONS_H_INCLUDED
