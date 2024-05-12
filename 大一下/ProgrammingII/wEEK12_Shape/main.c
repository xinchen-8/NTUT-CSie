#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ShapeText(TYPE) double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

//circle
typedef struct circle_s {
    ShapeText(circle_s);
    int radius;
} circle_t;

double circle_perimeter(circle_t *circle){
    return 2*3.14*circle->radius;
}
double circle_area(circle_t *circle){
    return 3.14*circle->radius*circle->radius;
}

//rectangle
typedef struct rectangle_s {
    ShapeText(rectangle_s);
    int length;
    int width;
} rectangle_t;

double rectangle_perimeter(rectangle_t *rectangle){
    return 2*(rectangle->length + rectangle->width);
}
double rectangle_area(rectangle_t *rectangle){
    return rectangle->length * rectangle->width;
}

//square
typedef struct square_s {
    ShapeText(square_s);
    int edge;
} square_t;

double square_perimeter(square_t *square){
    return 4*square->edge;
}
double square_area(square_t *square){
    return square->edge * square->edge;
}

//triangle
typedef struct triangle_s {
    ShapeText(triangle_s);
    int edge[3];
} triangle_t;

double triangle_perimeter(triangle_t *triangle){
    return triangle->edge[0] + triangle->edge[1] + triangle->edge[2];
}
double triangle_area(triangle_t *triangle){
    double p = (triangle->edge[0] + triangle->edge[1] + triangle->edge[2])/2.0;
    return sqrt(p*(p-triangle->edge[0])*(p-triangle->edge[1])*(p-triangle->edge[2]));
}


int main() {
    int NumofShape;
    char shapemode;
    double perimeter=0.0f, area=0.0f;
    scanf("%d", &NumofShape);

    for(int i=0;i<NumofShape;i++){
        scanf(" %c", &shapemode);
        
        switch (shapemode){
            
            case 'C':{
                circle_t *Circle = (circle_t *)malloc(sizeof(circle_t));
                scanf("%d", &Circle->radius);
                Circle->perimeter = circle_perimeter;
                Circle->area = circle_area;

                printf("%.2f %.2f\n", Circle->perimeter(Circle), Circle->area(Circle));
                perimeter += Circle->perimeter(Circle);
                area += Circle->area(Circle);
                free(Circle);
                break;
            }

            case 'R':{
                rectangle_t *Rec = (rectangle_t *)malloc(sizeof(rectangle_t));
                scanf("%d %d", &Rec->length, &Rec->width);
                Rec->perimeter = rectangle_perimeter;
                Rec->area = rectangle_area;

                perimeter += Rec->perimeter(Rec);
                area += Rec->area(Rec);
                printf("%.2f %.2f\n", Rec->perimeter(Rec), Rec->area(Rec));
                free(Rec);
                break;
            }

            case 'S':{
                square_t *Sqr = (square_t *)malloc(sizeof(square_t));
                scanf("%d", &Sqr->edge);
                Sqr->perimeter = square_perimeter;
                Sqr->area = square_area;

                perimeter += Sqr->perimeter(Sqr);
                area += Sqr->area(Sqr);
                printf("%.2f %.2f\n", Sqr->perimeter(Sqr), Sqr->area(Sqr));
                free(Sqr);
                break;
            }

            case 'T':{
                triangle_t *Tri = (triangle_t *)malloc(sizeof(triangle_t));
                scanf("%d %d %d", &Tri->edge[0], &Tri->edge[1], &Tri->edge[2]);
                Tri->perimeter = triangle_perimeter;
                Tri->area = triangle_area;

                perimeter += Tri->perimeter(Tri);
                area += Tri->area(Tri);
                printf("%.2f %.2f\n", Tri->perimeter(Tri), Tri->area(Tri));
                free(Tri);
                break;
            }

            default:
                NULL;
        }
    }
    printf("%.2f %.2f\n", perimeter, area);
  return 0;
}