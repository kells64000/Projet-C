#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fonctions.h"

int main()
{
    setlocale(LC_ALL,"");  // affiche les accents dans la console

    int connexion=0;

    connexion=Authentification(); // Connexion prend pour valeur (1) si profil utilisateur (2) si profil administrateur

    MenuAuthentification(connexion); // Le menu renvoyé dépend du type de profil

    return 0;
}
