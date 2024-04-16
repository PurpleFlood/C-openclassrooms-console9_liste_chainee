//
//  liste_chainee_int.h
//  console9_liste_chainee
//
//  Created by asap on 16/04/2024.
//

#ifndef liste_chainee_int_h
#define liste_chainee_int_h

typedef struct Element Element;
struct Element {
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
    int nombreElement;
};

void *malloc(size_t size);
void free(void* pointeur);
Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

Liste *initialisation(){
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    
    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->nombre=0;
    element->suivant=NULL;
    liste->premier=element;
    
    return liste;
}

void insertion(Liste *liste, int nvNombre){
    Element *nouveau=malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->nombre=nvNombre;
    
    nouveau->suivant=liste->premier;
    liste->premier=nouveau;
    liste->nombreElement++;
}

void suppression(Liste *liste){
    if(liste==NULL){
        exit(EXIT_FAILURE);
    }
    if(liste->premier!=NULL){
        Element *aSupprimer=liste->premier;
        liste->premier=liste->premier->suivant;
        liste->nombreElement--;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste) {
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
    Element *actuel = liste->premier;
    
    while(actuel != NULL){
        printf("%d -> ", actuel->nombre);
        actuel=actuel->suivant;
    }
    printf("NULL\n");
}


#endif /* liste_chainee_int_h */
