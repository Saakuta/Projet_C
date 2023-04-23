#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

char menu_1() { /* Menu principal*/

    char choice1;
    printf("Votre choix : ");
    scanf("%c", &choice1);

    do{
        if (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' && choice1 != 'F') {
            printf("Erreur: Veuillez choisir une action valide.\n");
            printf("Votre choix : ");
            scanf("%c", &choice1);
        }
    } while (choice1 != 'A' && choice1 != 'B' && choice1 != 'C' && choice1 != 'D' && choice1 != 'E' && choice1 != 'F');
    {
        printf("Veuillez choisir une action :\n");
        printf("A - Ajouter une forme\n");
        printf("B - Afficher la liste de formes\n");
        printf("C - Supprimer une forme\n");
        printf("D - Tracer le dessin\n");
        printf("E - Aide\n");
        printf("F - Arrêter le programme\n");

        printf("Votre choix : ");
        scanf("%c", &choice1);
        printf("%c", choice1);
    }
    return choice1;
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
    p->pos_x = px;
    p->pos_y = py;
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
    Line *l = create_line(px1, py1, px2, py2);
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
    Polygon *p = create_polygon(lst[],n);
    shp->prtShape = p;
    return shp;
}

void delete_point(Point *point) {
    free(point);
}

void delete_line(Line *line) {
    free(line->p1);
    free(line->p2);
    free(line);
}

void delete_square(Square *square) {
    free(square->point);
    free(square);
}

void delete_rectangle(Rectangle *rectangle) {
    free(rectangle->point);
    free(rectangle);
}

void delete_circle(Circle *circle) {
    free(circle->center);
    free(circle);
}

void delete_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->n; i++) {
        free(polygon->points);
    }
    free(polygon->points);
    free(polygon);
}

void delete_shape(Shape *shape) {
    printf("Shape ID: %d\n", shape->id);
    switch (shape->shape_type) {
        case POINT:
            delete_point((Point *) shape->prtShape);
            break;
        case LINE:
            delete_line((Line *) shape->prtShape);
            break;
        case SQUARE:
            delete_shape((Square *) shape->prtShape);
            break;
        case RECTANGLE:
            delete_rectangle((Rectangle *) shape->prtShape);
            break;
        case CIRCLE:
            delete_circle((Circle *) shape->prtShape);
            break;
        case POLYGON:
            delete_polygon((Polygon *) shape->prtShape);
            break;
    }
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
