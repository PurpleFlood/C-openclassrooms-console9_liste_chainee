//
//  main.c
//  console9_liste_chainee
//
//  Created by asap on 16/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee_int.h"

int main(int argc, const char * argv[]) {
    
    Liste *maliste=initialisation();
    
    insertion(maliste, 9);
    insertion(maliste, 10);
    insertion(maliste, 999);
    insertion(maliste, 9888);
    suppression(maliste);
    
    afficherListe(maliste);
    printf("\nNombre d'éléments présents dans la liste : %d\n", maliste->nombreElement);
    
    return 0;
}


