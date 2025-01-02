/*************************
 * PROJET GESTION BANCAIRE      
 * Groupe : G5MINIPROJETL2        
 * 1. [Mamadou Maurice Coulibaly] - Gestion des clients 
 * 2. [Mouhamed Moustapha Ba] - Gestion des opérations
 * 3. [Ndeye Amy Danfa] - Gestion des fichiers et interface
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures Communes et Principales
typedef struct Operation {
    int code, numeroCompte;
    char type[10], dateop[11];
    float montant, soldeActuel;
    struct Operation *suivant;
} Operation;

typedef struct Compte {
    int numero, codeClient;
    char dateouverture[11], agence[50];
    float solde;
    struct Compte *suivant;
} Compte;

typedef struct Client {
    int codecli;
    char prenom[50], nom[50], tel[15], ville[50];
    Compte *compte;
    struct Client *suivant;
} Client;

Operation *historique = NULL;
Client *clients = NULL;

// Gestion des clients et comptes [MAMADOU MAURICE COULIBALY]        
// Code à compléter ici : Fonctions liées à la gestion des clients et comptes, telles que l'ajout et l'affichage des clients.


// Ajout de client
void ajouterClient() {
    // Implémentation à compléter par Mamadou Maurice Coulibaly
}

// Affichage des clients
void afficherClients() {
    // Implémentation à compléter par Mamadou Maurice Coulibaly
}


// Gestion des opérations bancaires [Mouhamed Moustapha Ba]
// Code à compléter ici : Fonctions liées aux opérations bancaires, telles que effectuer des dépôts, retraits et afficher l'historique des opérations.


// Fonction pour effectuer une opération bancaire (dépôt/retrait)
void effectuerOperation(const char *type) {
    // Implémentation à compléter par Mouhamed Moustapha Ba
}

// Affichage des opérations (historique)
void afficherOperations() {
    // Implémentation à compléter par Mouhamed Moustapha Ba
}


// Gestion de fichiers et Interface [Ndeye Amy Danfa]
// Sauvegarder les données
void sauvegarderFichier(const char *filename) {
    // Implémentation à compléter par Ndeye Amy Danfa
}

// Charger les fichiers
void chargerFichier(const char *filename) {
    // Implémentation à compléter par Ndeye Amy Danfa
}

// Fonction principale
int main() {
    // Implémentation à compléter par Ndeye Amy Danfa
