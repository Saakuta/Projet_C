#include <stdio.h>

#ifndef VECTOR_TEXT_BASED_EDITOR_VECTOR_H
#define VECTOR_TEXT_BASED_EDITOR_VECTOR_H

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


void delete_line(Line * line);
void print_line(Line * line);

typedef struct {
    Point *point;
    int length;
} Square;


void delete_square(Square * square);
void print_square(Square * square);


typedef struct {
    Point *point;
    int width;
    int height;
} Rectangle;


void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

typedef struct {
    Point *center;
    int radius;
} Circle;


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
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int
struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape* shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
};
typedef struct area Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;
Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);

void pixel_forme(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_rectangle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_square(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_polygon(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel*** pixel, int nb_pixels);

struct command {
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
};
typedef struct command Command;

Command* create_commande();
void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);


#endif //VECTOR_TEXT_BASED_EDITOR_VECTOR_H
