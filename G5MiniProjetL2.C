#include <stdio.h>
#include <string.h>

// Déclaration des structures principales [RESPONSABLE : MAMADOU MAURICE COULIBALY]
typedef struct Operation {
    char type[10];  // dépôt, retrait
    float montant;
    struct Operation *suivant; // Historique des opérations
} Operation;

typedef struct Compte {
    int numero; // Numéro de compte
    float solde; // Solde du compte
    Operation *historique; // Liste des opérations
    struct Compte *suivant; // Compte suivant
} Compte;

typedef struct Client {
    int id; // ID unique du client
    char nom[50]; // Nom du client
    char prenom[50]; // Prénom du client
    Compte *comptes; // Liste des comptes du client
    struct Client *suivant; // Client suivant
} Client;

// Fonctions à développer par chaque étudiant
// Étudiant 1 : Gestion des clients
void ajouterClient(Client **listeClients) {
    // Code à développer par [MAMADOU MAURICE COULIBALY]
}

void rechercherClient(Client *listeClients) {
    // Code à développer par [MAMADOU MAURICE COULIBALY]
}

void afficherClients(Client *listeClients) {
    // Code à développer par [MAMADOU MAURICE COULIBALY]
}

// Étudiant 2 : Gestion des comptes
void ajouterCompte(Client **listeClients) {
    // Code à développer par [NDEYE AMY DANFA]
}

void rechercherCompte(Client *listeClients) {
    // Code à développer par [NDEYE AMY DANFA]
}

void afficherComptes(Client *listeClients) {
    // Code à développer par [NDEYE AMY DANFA]
}

// Étudiant 3 : Gestion des opérations bancaires et fichiers
void effectuerDepot(Client *listeClients) {
    // Code à développer par [MOHAMED MOUSTAPHA BA]
}

void effectuerRetrait(Client *listeClients) {
    // Code à développer par [MOHAMED MOUSTAPHA BA]
}

void consulterSolde(Client *listeClients) {
    // Code à développer par [MOHAMED MOUSTAPHA BA]
}

void enregistrerDansFichier(Client *listeClients) {
    // Code à développer par [MOHAMED MOUSTAPHA BA]
}

void chargerDepuisFichier(Client **listeClients) {
    // Code à développer par [MOHAMED MOUSTAPHA BA]
}
