#include "shape.h"
#include <math.h>
#include <stdlib.h>

Shape* createShape(float radius, Vec2 center_pos, int vertex_count)
{
    Shape* shape = malloc(sizeof(Shape));
    shape->radius = radius;
    shape->angle = 0.f;
    shape->center_pos = center_pos;
    shape->vertex_count = vertex_count;
    shape->vertex_capacity = vertex_count;
    shape->vertex_array = malloc(sizeof(Vec2) * shape->vertex_capacity);
    
    shapeLoadVertices(shape);
    
    return shape;
}

void destroyShape(Shape* shape)
{
    free(shape->vertex_array);
    free(shape);
}

void shapeLoadVertices(Shape* shape)
{
    float angle = shape->angle;
    float sum = 2 * M_PI / shape->vertex_count;
    
    for (int i = 0; i < shape->vertex_count; i++) {
        shape->vertex_array[i].x = cosf(angle) * shape->radius;
        shape->vertex_array[i].y = sinf(angle) * shape->radius;
        angle += sum;
    }
}

