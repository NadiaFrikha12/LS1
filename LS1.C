#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LS1.h"

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

// initialisation de la liste
void init_liste(LISTE *L) {
	L->premier = NULL ;
	L->courant = NULL ;
	L->dernier = NULL ;
}

//tester si une liste est vide
int liste_vide(LISTE *L){
	return L->premier == NULL;
}

//ouvrir_liste permet de se positionner sur le premier �l�ment de la liste (courant)
void ouvrir_liste(LISTE *L){
	L->courant = L->premier;
}

//permet de savoir si on atteint la fin de la liste L ouverte pr�alablement par ouvrir_liste
int fin_liste(LISTE *L) {
	return L->courant == NULL;
}

//Affichage de la liste
void afficher_liste(LISTE L){
	if (liste_vide(&L)){
		printf("liste vide\n");
	}
	else{
		ouvrir_liste(&L);
		while (! fin_liste(&L)){
			puts(L.courant->nom);
			L.courant = L.courant->next;
		}
	}
}

void saisir_elt(ELEMENT *e){
	puts("donner le nom");
	gets(e->nom);
	e->next = NULL;
}

//fournit un pointeur sur l��l�ment courant de la liste L et se positionne sur l��l�ment suivant qui devient l��l�ment courant
ELEMENT* element_courant(LISTE*L){
	ELEMENT* p;
	p= L->courant;
	if (p->next != NULL){
		p= p->next;	
	}
	return p;
}

//ajout d�un �l�ment en t�te de liste
void inserer_tete(LISTE *L,ELEMENT *e) {
	if (liste_vide (L)){
		L->premier = e;
		L->dernier = e ; 	
	}
	else{
		ouvrir_liste(L);
		e->next = L->premier;
		L->premier = e;
	}	
	L->courant = e; // Mettre � jour le pointeur courant	
}

// remplir la liste L en ins�rant � chaque fois n �l�ment � la t�te de la liste
void remplir_liste_tete(LISTE *L, int n){
	char ch[50];
	ELEMENT *e; 
	ouvrir_liste (L);
	for(int i =0; i<n ; i++){
		e = (ELEMENT*)malloc (sizeof(ELEMENT));
		if (e == NULL){
			printf("erreur");
			exit(-1);
		}
		saisir_elt(e);
		inserer_tete(L,e);
	}
}

// ins�rer nouv � la fin de la liste L
void inserer_fin(LISTE *L,ELEMENT *nouv){
	if (L->dernier != NULL) {
		L->dernier->next = nouv ;
	}
	L->dernier = nouv ;
}

// remplir la liste L en ins�rant � chaque fois n �l�ment � la fin de la liste
void remplir_liste_fin(LISTE *L, int n){
	ELEMENT* e;
	for(int i =0; i<n ; i++){
		e= (ELEMENT*)malloc(sizeof(ELEMENT)) ;
		if (e == NULL){
			printf("erreur");
			exit(-1);
		}
		saisir_elt(e);
		if (liste_vide(L)){
			L->premier = e;
			L->dernier = e;
		}
		else {
			inserer_fin(L,e);
		}
	}
}

// ins�rer nouv apr�s preced dans la liste L
void inserer_apres(LISTE *L, ELEMENT *preced, ELEMENT *nouv){
	if (liste_vide(L)){
		L->premier = nouv;
		L->dernier = nouv;
	}
	else{
		nouv->next = preced->next;
		preced->next = nouv;
		if ( L->dernier = preced){
			L->dernier = nouv; //mettre � jour le dernier element 
		}
	}
	L->courant = nouv; // mettre � jour le pointeur courant 
}

//cette fonction fournitun pointeur sur la personne nm de la liste ou NULL si la personne n�existe pas.
ELEMENT* chercher_element(LISTE *L,char *nm) {
	if (liste_vide(L)){
		return NULL;
	}
	else {
		while (L->premier != NULL){
			if (strcmp(L->premier->nom , nm ) == 0){
				return L->premier;
			}
			else{
				L->premier = L->premier->next;
			}
		}
	}
	return NULL ; 
}

// dans cette fonction un nom sera saisi. Cette fonction ins�re l��l�ment e dans la liste L apr�s le nom d�j� saisi.
void inserer_milieu(LISTE *L,ELEMENT *e){
	ELEMENT* pred ;
	char name[50];
	printf("donner le nom du pred ");
	gets(name);
	pred = chercher_element(L,name);
	if (pred != NULL){
		inserer_apres(L,pred,e);
	}
	else {
		printf("le nom n'exite pas ");
	}
} 

//supprimer t�te de la liste
void supprimer_tete(LISTE *L){
	if (liste_vide(L)){
		printf("la liste est vide ");
	}
    ELEMENT* actuel = L->premier;
    L->premier = actuel->next;
    if (L->courant == actuel) { //mise � jour de l'ement courant  
        L->courant = L->premier;
    }
    if (L->dernier == actuel) { //mise � jour du dernier element
        L->dernier = NULL;
    }
    free(actuel);
    }

//supprimer l��l�ment de L qui se trouve apr�s preced
void supprimer_suivant(LISTE *L, ELEMENT *preced) {
	if ((preced == NULL) || (L->dernier == preced)){
		printf("il n' y a pas d'element a supprimer");
	}
	ELEMENT* actuel = preced->next; //conserver l'adresse � supprimer
	preced->next = actuel->next;
	if (L->courant == actuel ){ //mise � jour de l'ement courant 
		L->courant = preced->next;
	}
	if (L->dernier == actuel){ //mise � jour du dernier element
		L->dernier = preced;
	}
	free(actuel);
}

//cette fonction fournit un pointeur sur l��l�ment qui pr�c�de nm
ELEMENT* chercher_element_precedent(LISTE *L, char *nm){
	ELEMENT* preced = NULL;
	ELEMENT* actuel = L->premier;
	
	while (actuel != NULL){
		if (strcmp(actuel->nom, nm)==0){
			return preced;
		}
		actuel = actuel->next;
		preced = actuel ;
	}
	return NULL;
}

//Supprimer l��l�ment qui se trouve apr�s nm
void supprimer_suivant_nom(LISTE *L, char *nm){
	if (liste_vide(L)){
		printf("la liste est vide ");
	}
	ELEMENT* preced = chercher_element_precedent(L,nm);
	if (preced != NULL){
		ELEMENT* actuel_nm = preced->next;
		supprimer_suivant(L,actuel_nm);
	}
	else {
		printf("il n'y a pas d'element a supprimer");
	}
}
	
// supprimer l��l�ment de nom nm
void supprimer_valeur(LISTE *L, char *nm){
	if (liste_vide(L)){
		printf("la liste est vide ");
	}
	ELEMENT* actuel = chercher_element(L,nm);
	if (actuel != NULL){
		if (actuel->next != NULL){
			supprimer_suivant_nom(L,nm);
		}	
	}
	else{
			printf("il n'y a pas d'elemnt a supprimer");
		}
}

// supprimer le dernier �l�ment de la liste
void supprimer_queue(LISTE *L){
	if (!liste_vide(L)) {
	    ELEMENT* actuel = L->premier;
	    ELEMENT* preced = NULL;
	
	while (actuel->next != NULL) {
	    preced = actuel;
	    actuel = actuel->next;
	}
	
	if (preced != NULL) {
	    preced->next = NULL;
	    L->dernier = preced;
	} 
	else {
	    L->premier = NULL;
	    L->courant = NULL;
	    L->dernier = NULL;
	}
	free(actuel);
	}
}

// supprimer tous les �l�ments de la liste
void supprimer_liste(liste* L) {
    while (!liste_vide(L)) {
        supprimer_tete(L);
    }
}
	
