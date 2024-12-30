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
    void ajouter_compte(int numero, const char* date_ouverture, const char* agence, float solde, int code_client) {
    Compte* nouveau_compte = (Compte*) malloc(sizeof(Compte));
    nouveau_compte->numero = numero;
    strcpy(nouveau_compte->date_ouverture, date_ouverture);
    strcpy(nouveau_compte->agence, agence);
    nouveau_compte->solde = solde;
    nouveau_compte->code_client = code_client;
    nouveau_compte->suivant = liste_comptes;
    liste_comptes = nouveau_compte;

    // Enregistrer dans le fichier
    FILE* fichier = fopen("comptes.dat", "a");
    if (fichier != NULL) {
        fprintf(fichier, "%d;%s;%s;%.2f;%d\n", numero, date_ouverture, agence, solde, code_client);
        fclose(fichier);
    } else {
        printf("Erreur d'ouverture du fichier comptes.dat\n");
    }
}


    // Enregistrer dans le fichier
    FILE* fichier = fopen("comptes.dat", "a");
    if (fichier != NULL) {
        fprintf(fichier, "%d;%s;%s;%.2f;%d\n", numero, date_ouverture, agence, solde, code_client);
        fclose(fichier);
    } else {
        printf("Erreur d'ouverture du fichier comptes.dat\n");
    }
}



void rechercherCompte(Client *listeClients) {
    // Code à développer par [NDEYE AMY DANFA]
    Compte* rechercher_compte(int numero) {
    Compte* compte = liste_comptes;
    while (compte != NULL) {
        if (compte->numero == numero) {
            return compte;  // Compte trouvé
        }
        compte = compte->suivant;
    }
    return NULL;  // Compte non trouvé
}

}

void afficherComptes(Client *listeClients) {
    // Code à développer par [NDEYE AMY DANFA]
    void afficher_comptes() {
    Compte* compte = liste_comptes;
    while (compte != NULL) {
        printf("Compte N°%d | Solde: %.2f\n", compte->numero, compte->solde);
        compte = compte->suivant;
    }
}

}

// Étudiant 3 : Gestion des opérations bancaires et fichiers
void effectuerDepot(Client *listeClients) {
    int idClient;
    float montant;
    printf("Entrez l'ID du client : ");
    scanf("%d", &idClient);
    printf("Entrez le montant à déposer : ");
    scanf("%f", &montant);

    for (int i = 0; i < NOMBRE_DE_CLIENTS; i++) { // Remplacez par la taille réelle de listeClients
        if (listeClients[i].id == idClient) {
            listeClients[i].solde += montant;
            printf("Dépôt effectué. Nouveau solde : %.2f\n", listeClients[i].solde);
            return;
        }
    }
    printf("Client introuvable.\n");
}



void effectuerRetrait(Client *listeClients) {
    int idClient;
    float montant;
    printf("Entrez l'ID du client : ");
    scanf("%d", &idClient);
    printf("Entrez le montant à retirer : ");
    scanf("%f", &montant);

    for (int i = 0; i < NOMBRE_DE_CLIENTS; i++) {
        if (listeClients[i].id == idClient) {
            if (listeClients[i].solde >= montant) {
                listeClients[i].solde -= montant;
                printf("Retrait effectué. Nouveau solde : %.2f\n", listeClients[i].solde);
            } else {
                printf("Solde insuffisant.\n");
            }
            return;
        }
    }
    printf("Client introuvable.\n");
}


void consulterSolde(Client *listeClients) {
    int idClient;
    printf("Entrez l'ID du client : ");
    scanf("%d", &idClient);

    for (int i = 0; i < NOMBRE_DE_CLIENTS; i++) {
        if (listeClients[i].id == idClient) {
            printf("Solde actuel de %s %s : %.2f\n", listeClients[i].nom, listeClients[i].prenom, listeClients[i].solde);
            return;
        }
    }
    printf("Client introuvable.\n");
}


void enregistrerDansFichier(Client *listeClients) {
    FILE *fichier = fopen("clients.txt", "w");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < NOMBRE_DE_CLIENTS; i++) {
        fprintf(fichier, "%d %s %s %.2f\n", listeClients[i].id, listeClients[i].nom, listeClients[i].prenom, listeClients[i].solde);
    }

    fclose(fichier);
    printf("Données enregistrées dans le fichier.\n");
}


void chargerDepuisFichier(Client **listeClients) {
    FILE *fichier = fopen("clients.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    int i = 0;
    while (fscanf(fichier, "%d %s %s %f", &(*listeClients)[i].id, (*listeClients)[i].nom, (*listeClients)[i].prenom, &(*listeClients)[i].solde) != EOF) {
        i++;
    }

    fclose(fichier);
    printf("Données chargées depuis le fichier.\n");
}

