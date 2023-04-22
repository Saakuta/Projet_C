#include <stdio.h>

#ifndef VECTOR_TEXT_BASED_EDITOR_VECTOR_H
#define VECTOR_TEXT_BASED_EDITOR_VECTOR_H

char menu_1();

typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

typedef struct {
    Point *point;
    int length;
} Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


typedef struct {
    Point *point;
    int width;
    int height;
} Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

typedef struct {
    Point *center;
    int radius;
} Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

typedef struct {
    int *points;
    int n;
} Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct shape {
    int id;
    SHAPE_TYPE  shape_type;
    void *prtShape;
}Shape;

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif //VECTOR_TEXT_BASED_EDITOR_VECTOR_H
