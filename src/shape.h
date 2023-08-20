#ifndef SHAPE_H
#define SHAPE_H
#include "vec2.h"

typedef struct {
    Vec2 center_pos;
    Vec2 origin_offset;
    float radius;
    float angle;
    Vec2* vertex_array;
    int vertex_count;
    int vertex_capacity;
}
Shape;

Shape* createShape(float radius, Vec2 center_pos, int vertex_count);
void destroyShape(Shape* shape);

void shapeLoadVertices(Shape* shape);

#endif