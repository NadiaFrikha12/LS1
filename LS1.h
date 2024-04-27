#ifndef UNTITLED_FONCTIONS_H
#define UNTITLED_FONCTIONS_H 

struct ELEMENT {
	char nom[30];
	struct ELEMENT* next;
}; 
typedef struct ELEMENT ELEMENT; 

struct LISTE {
	ELEMENT* premier;
	ELEMENT* courant;
	ELEMENT* dernier; 
};
typedef struct LISTE LISTE;

void init_liste(LISTE *L); // initialisation de la liste
int liste_vide(LISTE *L); //tester si une liste est vide
void ouvrir_liste(LISTE *L); //ouvrir_liste permet de se positionner sur le premier élément de la liste (courant)
int fin_liste(LISTE *L); //permet de savoir si on atteint la fin de la liste L ouverte préalablement par ouvrir_liste
void afficher_liste(LISTE L); //Affichage de la liste
void saisr_elt(ELEMENT *e);
ELEMENT*element_courant(LISTE*L); //fournit un pointeur sur l’élément courant de la liste L et se positionne sur l’élément suivant qui devient l’élément courant
void inserer_tete(LISTE *L,ELEMENT *e); //ajout d’un élément en tête de liste
void remplir_liste_tete(LISTE *L, int n); // remplir la liste L en insérant à chaque fois n élément à la tête de la liste
void inserer_fin(LISTE *L,ELEMENT *nouv); // insérer nouv à la fin de la liste L
void remplir_liste_fin(LISTE *L, int n); // remplir la liste L en insérant à chaque fois n élément à la fin de la liste
void inserer_apres(LISTE *L, ELEMENT *preced, ELEMENT *nouv); // insérer nouv après preced dans la liste L
ELEMENT * chercher_element(LISTE *l,char *nm); //cette fonction fournit un pointeur sur la personne nm de la liste ou NULL si la personne n’existe pas.
void inserer_milieu(LISTE *l,ELEMENT *e); // dans cette fonction un nom sera saisi. Cette fonction insère l’élément e dans la liste L après le nom déjà saisi.
void supprimer_tete(LISTE *L); //supprimer tête de la liste
void supprimer_suivant(LISTE *L, ELEMENT *preced); //supprimer l’élément de L qui se trouve après preced
ELEMENT* chercher_element_precedent(LISTE *L, char *nm); //cette fonction fournit un pointeur sur l’élément qui précède nm
void supprimer_suivant_nom(LISTE *L, char *nm); //Supprimer l’élément qui se trouve après nm
ELEMENT * chercher_element(LISTE *l,char *nm); //cette fonction fournit un pointeur sur la personne nm de la liste ou NULL si la personne n’existe pas.
void supprimer_valeur(LISTE *L, char *nm); // supprimer l’élément de nom nm
void supprimer_queue(LISTE *L); // supprimer le dernier élément de la liste
void supprimer_liste(LISTE *L); //supprimer tous les éléments de la liste

#endif //UNTITLED_FONCTIONS_H
