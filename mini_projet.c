#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure produit
typedef struct {
    int id; // identificateur du produit
    char nom[20]; // nom du produit
    float prix; // prix du produit
    int quantite; // quantité du produit en stock
} produit;

// Déclaration des fonctions
void ajouter_produit(produit *tab, int *n); // ajoute un produit au tableau
void modifier_produit(produit *tab, int n); // modifie la quantité ou le prix d'un produit
void rechercher_produit(produit *tab, int n); // recherche un produit par son id
void afficher_produits(produit *tab, int n); // affiche la liste des produits
void supprimer_produit(produit *tab, int *n); // supprime un produit du tableau
void vendre_produit(produit *tab, int n, float *ca); // vend un produit et met à jour le chiffre d'affaire
void afficher_ca(float ca); // affiche le chiffre d'affaire total
void afficher_stats(produit *tab, int n); // affiche les statistiques sur les produits
void quitter(); // quitte le programme

// Fonction principale
int main() {
    produit tab[100]; // tableau des produits
    int n = 0; // nombre de produits
    float ca = 0; // chiffre d'affaire
    int choix; // choix de l'utilisateur
    do {
        // Affichage du menu principal
        printf("***** Gestion des produits d'un magasin *****\n");
        printf("1-Ajouter Un Produit\n");
        printf("2-Modifier la Quantité ou bien le prix d'un produit\n");
        printf("3-Rechercher un Produit par son identificateur\n");
        printf("4-Afficher la liste Des Produits (id's, prix et quantité)\n");
        printf("5-supprimer un produit\n");
        printf("6-Vendre Un Produit\n");
        printf("7-Afficher Le Chiffre D'affaire Total\n");
        printf("8-Afficher les Staatistiques\n");
        printf("9-Quitter Le Programme\n");
        printf("**********************************************\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix); // lecture du choix
        switch (choix) {
            case 1: // ajouter un produit
                ajouter_produit(tab, &n);
                break;
            case 2: // modifier un produit
                modifier_produit(tab, n);
                break;
            case 3: // rechercher un produit
                rechercher_produit(tab, n);
                break;
            case 4: // afficher les produits
                afficher_produits(tab, n);
                break;
            case 5: // supprimer un produit
                supprimer_produit(tab, &n);
                break;
            case 6: // vendre un produit
                vendre_produit(tab, n, &ca);
                break;
            case 7: // afficher le chiffre d'affaire
                afficher_ca(ca);
                break;
            case 8: // afficher les statistiques
                afficher_stats(tab, n);
                break;
            case 9: // quitter le programme
                quitter();
                break;
            default: // choix invalide
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 9); // tant que l'utilisateur ne quitte pas le programme
    return 0;
}

// Définition des fonctions

// Ajoute un produit au tableau
void ajouter_produit(produit *tab, int *n) {
    produit p; // produit à ajouter
    printf("Entrez l'id du produit : ");
    scanf("%d", &p.id); // lecture de l'id
    printf("Entrez le nom du produit : ");
    scanf("%s", p.nom); // lecture du nom
    printf("Entrez le prix du produit : ");
    scanf("%f", &p.prix); // lecture du prix
    printf("Entrez la quantité du produit : ");
    scanf("%d", &p.quantite); // lecture de la quantité
    tab[*n] = p; // ajout du produit au tableau
    (*n)++; // incrémentation du nombre de produits
    printf("Produit ajouté avec succès.\n");
}

// Modifie la quantité ou le prix d'un produit
void modifier_produit(produit *tab, int n) {
    int id; // id du produit à modifier
    int i; // indice du produit dans le tableau
    int choix; // choix de l'utilisateur
    printf("Entrez l'id du produit à modifier : ");
    scanf("%d", &id); // lecture de l'id
    // Recherche du produit dans le tableau
    for (i = 0; i < n; i++) {
        if (tab[i].id == id) { // produit trouvé
            break;
        }
    }
    if (i == n) { // produit non trouvé
        printf("Produit introuvable.\n");
        return;
    }
    // Affichage du menu de modification
    printf("Que voulez-vous modifier ?\n");
    printf("1-La quantité\n");
    printf("2-Le prix\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix); // lecture du choix
    switch (choix) {
        case 1: // modifier la quantité
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &tab[i].quantite); // lecture de la nouvelle quantité
            printf("Quantité modifiée avec succès.\n");
            break;
        case 2: // modifier le prix
            printf("Entrez le nouveau prix : ");
            scanf("%f", &tab[i].prix); // lecture du nouveau prix
            printf("Prix modifié avec succès.\n");
            break;
        default: // choix invalide
            printf("Choix invalide, veuillez réessayer.\n");
            break;
    }
}

// Recherche un produit par son id
void rechercher_produit(produit *tab, int n) {
    int id; // id du produit à rechercher
    int i; // indice du produit dans le tableau
    printf("Entrez l'id du produit à rechercher : ");
    scanf("%d", &id); // lecture de l'id
    // Recherche du produit dans le tableau
    for (i = 0; i < n; i++) {
        if (tab[i].id == id) { // produit trouvé
            break;
        }
    }
    if (i == n) { // produit non trouvé
        printf("Produit introuvable.\n");
        return;
    }
    // Affichage du produit
    printf("Produit trouvé :\n");
    printf("Id : %d\n", tab[i].id);
    printf("Nom : %s\n", tab[i].nom);
    printf("Prix : %.2f\n", tab[i].prix);
    printf("Quantité : %d\n", tab[i].quantite);
}

// Affiche la liste des produits
void afficher_produits(produit *tab, int n) {
    int i; // indice du produit dans le tableau
    if (n == 0) { // tableau vide
        printf("Aucun produit à afficher.\n");
        return;
    }
    // Affichage du tableau
    printf("Liste des produits :\n");
    printf("Id\tNom\tPrix\tQuantité\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%d\n", tab[i].id, tab[i].nom, tab[i].prix, tab[i].quantite);
    }
}

// Supprime un produit du tableau
void supprimer_produit(produit *tab, int *n) {
    int id; // id du produit à supprimer
    int i, j; // indices du produit dans le tableau
    printf("Entrez l'id du produit à supprimer : ");
    scanf("%d", &id); // lecture de l'id
    // Recherche du produit dans le tableau
    for (i = 0; i < *n; i++) {
        if (tab[i].id == id) { // produit trouvé
            break;
        }
    }
    if (i == *n) { // produit non trouvé
        printf("Produit introuvable.\n");
        return;
    }
    // Suppression du produit du tableau
    for (j = i; j < *n - 1; j++) {
        tab[j] = tab[j + 1]; // décalage des produits
    }
    (*n)--; // décrémentation du nombre de produits
    printf("Produit supprimé avec succès.\n");
}

// Vend un produit et met à jour le chiffre d'affaire
void vendre_produit(produit *tab, int n, float *ca) {
    int id; // id du produit à vendre
    int i; // indice du produit dans le tableau
    int qte; // quantité à vendre
    float montant; // montant de la vente
    printf("Entrez l'id du produit à vendre : ");
    scanf("%d", &id); // lecture de l'id
    // Recherche du produit dans le tableau
    for (i = 0; i < n; i++) {
        if (tab[i].id == id) { // produit trouvé
            break;
        }
    }
    if (i == n) { // produit non trouvé
        printf("Produit introuvable.\n");
        return;
    }
    // Lecture de la quantité à vendre
    printf("Entrez la quantité à vendre : ");
    scanf("%d", &qte); // lecture de la quantité
    // Vérification de la disponibilité du produit
    if (qte > tab[i].quantite) { // quantité insuffisante
        printf("Quantité insuffisante en stock.\n");
        return;
    }
    // Mise à jour de la quantité du produit
    tab[i].quantite -= qte; // décrémentation de la quantité
    // Calcul du montant de la vente
    montant = qte * tab[i].prix; // multiplication de la quantité par le prix
    // Mise à jour du chiffre d'affaire
    *ca += montant; // ajout du montant au chiffre d'affaire
    printf("Vente effectuée avec succès.\n");
    printf("Montant de la vente : %.2f\n", montant);
}

// Affiche des statistiques sur les produits
void afficher_stats(produit *tab, int n) {
    int i; // indice du produit dans le tableau
    float somme_prix = 0; // somme des prix des produits
    float moyenne_prix; // moyenne des prix des produits
    float min_prix = 999999; // prix minimum des produits
    float max_prix = 0; // prix maximum des produits
    int min_qte = 999999; // quantité minimum des produits
    int max_qte = 0; // quantité maximum des produits
    if (n == 0) { // tableau vide
        printf("Aucune statistique à afficher.\n");
        return;
    }
    // Calcul des statistiques
    for (i = 0; i < n; i++) {
        somme_prix += tab[i].prix; // ajout du prix du produit à la somme
        if (tab[i].prix < min_prix) { // prix minimum
            min_prix = tab[i].prix;
        }
        if (tab[i].prix > max_prix) { // prix maximum
            max_prix = tab[i].prix;
        }
        if (tab[i].quantite < min_qte) { // quantité minimum
            min_qte = tab[i].quantite;
        }
        if (tab[i].quantite > max_qte) { // quantité maximum
            max_qte = tab[i].quantite;
        }
    }
    moyenne_prix = somme_prix / n; // calcul de la moyenne des prix
    // Affichage des statistiques
    printf("Statistiques sur les produits :\n");
    printf("Nombre de produits : %d\n", n);
    printf("Prix moyen : %.2f\n", moyenne_prix);
    printf("Prix minimum : %.2f\n", min_prix);
    printf("Prix maximum : %.2f\n", max_prix);
    printf("Quantité minimum : %d\n", min_qte);
    printf("Quantité maximum : %d\n", max_qte);
}

// Quitte le programme
void quitter() {
    printf("Merci d'avoir utilisé ce programme.\n");
    printf("Au revoir.\n");
    exit(0); // termine le programme
}

// Affiche le chiffre d'affaire total
void afficher_ca(float ca) {
    printf("Le chiffre d'affaire total est : %.2f\n", ca); // affichage du chiffre d'affaire
}
