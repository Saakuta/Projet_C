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
    shp->prtShape = NULL;
    shp->id = 1;
    shp->shape_type = shape_type;
    return shp;
}

Point *create_point(int px, int py) {
    Point *p = (Point *) malloc(sizeof(Point));
    p->x = px;
    p->y = py;
    return p;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->prtShape = p;
    return shp;
}

Line *create_line(int px1, int py1, int px2, int py2) {
    Line *l = (Line *) malloc(sizeof(Line));
    l->p1 = create_point(px1, py1);
    l->p2 = create_point(px2, py2);
    return l;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    Point * p1 = create_point(px1, py1);
    Point * p2 = create_point(px2, py2);
    Line *l = create_line(p1, p2);
    shp->prtShape = l;
    return shp;
}

Square *create_square(int px, int py, int length) {
    Square *sq = (Square *) malloc(sizeof(Square));
    sq->point = create_point(px, py);
    sq->length = length;
    return sq;
}

Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Square *sq = create_square(px, py, length);
    shp->prtShape = sq;
    return shp;
}

Rectangle *create_rectangle(int px, int py, int width, int height) {
    Rectangle *rect = (Rectangle *) malloc(sizeof(Rectangle));
    rect->point = create_point(px, py);
    rect->width = width;
    rect->height = height;
    return rect;
}

Shape *create_rectangle_shape(int px, int py, int width, int height) {
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle *rect = create_rectangle(px, py, width, height);
    shp->prtShape = rect;
    return shp;
}

Circle *create_circle(int px, int py, int radius) {
    Circle *c = (Circle *) malloc(sizeof(Circle));
    c->center = create_point(px, py);
    c->radius = radius;
    return c;
}

Shape *create_circle_shape(int px, int py, int radius) {
    Shape *shp = create_empty_shape(CIRCLE);
    Circle *c = create_circle(px, py, radius);
    shp->prtShape = c;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n) {
    if (n % 2 != 0) {
        printf("Erreur: Le nombre de points d'un polygône doit être pair.\n");
        return NULL;
    }
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *p = create_polygon(lst, n);
    shp->prtShape = p;
    return shp;
}

void delete_shape(Shape *shape) {
    if (shape->prtShape != NULL) {
        delete_shape_data(shape->prtShape);
        free(shape->prtShape);
    }
    free(shape);
}

void print_shape(Shape *shape) {
    printf("Shape ID: %d\n", shape->id);
    switch (shape->shape_type) {
        case POINT:
            printf("Shape Type: Point\n");
            print_point((Point *) shape->prtShape);
            break;
        case LINE:
            printf("Shape Type: Line\n");
            print_line((Line *) shape->prtShape);
            break;
        case SQUARE:
            printf("Shape Type: Square\n");
            print_square((Square *) shape->prtShape);
            break;
        case RECTANGLE:
            printf("Shape Type: Rectangle\n");
            print_rectangle((Rectangle *) shape->prtShape);
            break;
        case CIRCLE:
            printf("Shape Type: Circle\n");
            print_circle((Circle *) shape->prtShape);
            break;
        case POLYGON:
            printf("Shape Type: Polygon\n");
            print_polygon((Polygon *) shape->prtShape);
            break;
    }
}







