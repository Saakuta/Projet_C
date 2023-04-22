#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

char menu_1() { /* Menu principal*/

    char choice1;

    while (choice1 != 'F')
    {
        printf("Veuillez choisir une action :\n");
        printf("A - Ajouter une forme\n");
        printf("B - Afficher la liste de formes\n");
        printf("C - Supprimer une forme\n");
        printf("D - Tracer le dessin\n");
        printf("E - Aide\n");
        printf("F - Arrêter le programme\n");

        printf("Votre choix : ");
        scanf("%c", choice1);
        printf("%c", choice1);
    }
}

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1;
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}