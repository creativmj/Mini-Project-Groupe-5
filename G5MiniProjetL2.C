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
// Vérifier si un numéro de compte existe déjà
int compteExiste(int numeroCompte) {
    Client *client = clients;
    while (client != NULL) {
        if (client->compte && client->compte->numero == numeroCompte) {
            return 1;
        }
        client = client->suivant;
    }
    return 0;
}

// Vérifier si un code client existe déjà
int clientExiste(int codeClient) {
    Client *client = clients;
    while (client != NULL) {
        if (client->codecli == codeClient) {
            return 1;
        }
        client = client->suivant;
    }
    return 0;
}

// Ajout de client
void ajouterClient() {
    int codeClient, numeroCompte;
    
    printf("Code client : ");
    scanf("%d", &codeClient);
    
    if (clientExiste(codeClient)) {
        printf("Erreur : Ce code client existe déjà.\n");
        return;
    }

    printf("Numero de compte : ");
    scanf("%d", &numeroCompte);
    
    if (compteExiste(numeroCompte)) {
        printf("Erreur : Ce numéro de compte existe déjà.\n");
        return;
    }

    Client *client = (Client *)malloc(sizeof(Client));
    if (!client) {
        printf("Erreur d'allocation mémoire pour le client\n");
        return;
    }
    
    client->codecli = codeClient;
    printf("Prenom : ");
    scanf("%s", client->prenom);
    printf("Nom : ");
    scanf("%s", client->nom);
    printf("Telephone : ");
    scanf("%s", client->tel);
    printf("Ville : ");
    scanf("%s", client->ville);

    Compte *compte = (Compte *)malloc(sizeof(Compte));
    if (!compte) {
        printf("Erreur d'allocation mémoire pour le compte\n");
        free(client);
        return;
    }

    compte->numero = numeroCompte;
    printf("Date d'ouverture (DD-MM-YYYY) : ");
    scanf("%s", compte->dateouverture);
    printf("Agence : ");
    scanf("%s", compte->agence);
    printf("Solde initial : ");
    scanf("%f", &compte->solde);

    compte->codeClient = client->codecli;
    compte->suivant = NULL;
    client->compte = compte;
    
    // Ajout à la fin de la liste
    if (clients == NULL) {
        clients = client;
        client->suivant = NULL;
    } else {
        Client *temp = clients;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = client;
        client->suivant = NULL;
    }

    printf("Client et compte ajoutés avec succès!\n");
    // sauvegarderFichier sera appelé plus tard
}

// Affichage des clients
void afficherClients() {
    if (clients == NULL) {
        printf("Aucun client enregistré.\n");
        return;
    }

    Client *tmp = clients;
    while (tmp != NULL) {
        if (tmp->compte != NULL) {
            printf("Code : %d | %s %s | Téléphone : %s | Ville : %s | Compte : %d | Solde : %.2f\n",
                   tmp->codecli, tmp->prenom, tmp->nom, tmp->tel, tmp->ville,
                   tmp->compte->numero, tmp->compte->solde);
        }
        tmp = tmp->suivant;
    }
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
