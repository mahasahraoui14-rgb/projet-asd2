#maha sahraoui
#zaineb khaterchi
#projet asd2
#include <stdio.h>
#include <string.h>

#define MAX 50

/* ================= STRUCTURES ================= */

typedef struct {
    int id;
    char nom[30];
} Client;

typedef struct {
    int id;
    int idClient;
    int jours;
} Reservation;

/* ================= DONNEES ================= */

Client clients[MAX];
Reservation reservations[MAX];

int nbClients = 0;
int nbReservations = 0;

/* ================= AUTHENTIFICATION ================= */

int authentification() {
    char user[20];
    char pass[20];

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    return 1; // يقبل أي user
}

/* ================= MODULE CLIENT ================= */

void ajouterClient() {
    if(nbClients >= MAX) {
        printf("Liste clients pleine !\n");
        return;
    }

    printf("ID client: ");
    scanf("%d", &clients[nbClients].id);

    printf("Nom client: ");
    scanf("%s", clients[nbClients].nom);

    nbClients++;
}

void afficherClients() {
    int i;

    if(nbClients == 0) {
        printf("Aucun client\n");
        return;
    }

    for(i = 0; i < nbClients; i++) {
        printf("%d %s\n", clients[i].id, clients[i].nom);
    }
}

/* ================= MODULE RESERVATION ================= */

void ajouterReservation() {
    if(nbReservations >= MAX) {
        printf("Liste reservations pleine !\n");
        return;
    }

    printf("ID reservation: ");
    scanf("%d", &reservations[nbReservations].id);

    printf("ID client: ");
    scanf("%d", &reservations[nbReservations].idClient);

    printf("Nombre de jours: ");
    scanf("%d", &reservations[nbReservations].jours);

    nbReservations++;
}

/* ================= MODULE FACTURATION ================= */

void facturation() {
    int id;
    int prix = 100;
    int i;

    printf("ID reservation: ");
    scanf("%d", &id);

    for(i = 0; i < nbReservations; i++) {
        if(reservations[i].id == id) {
            int total = reservations[i].jours * prix;
            printf("Montant total: %d\n", total);
            return;
        }
    }

    printf("Reservation non trouvee\n");
}

/* ================= MODULE RAPPORT ================= */

void rapport() {
    printf("Nombre de clients: %d\n", nbClients);
    printf("Nombre de reservations: %d\n", nbReservations);
}

/* ================= MENU ================= */

int main() {
    int choix;

    if(authentification() == 0) {
        printf("Erreur login\n");
        return 0;
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1 Ajouter client\n");
        printf("2 Afficher clients\n");
        printf("3 Ajouter reservation\n");
        printf("4 Facturation\n");
        printf("5 Rapport\n");
        printf("0 Quitter\n");

        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterClient(); break;
            case 2: afficherClients(); break;
            case 3: ajouterReservation(); break;
            case 4: facturation(); break;
            case 5: rapport(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide\n");
        }

    } while(choix != 0);

    return 0;
}
