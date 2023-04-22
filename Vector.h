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
