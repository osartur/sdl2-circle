#include "render.h"
#include "vec2.h"

#define EXTRACT_COLOR(hex) hex >> 16, hex >> 8, hex, 255

void renderShape(SDL_Renderer* renderer, const Shape* shape, Uint32 color)
{
    Vec2 a, b;
    
    for (int i = 1; i < shape->vertex_count; i++) {
        a = sumVec2(shape->vertex_array[i], shape->center_pos);
        b = sumVec2(shape->vertex_array[i - 1], shape->center_pos);
        renderLine(renderer, a, b, color);
    }
    
    a = sumVec2(shape->vertex_array[0], shape->center_pos);
    b = sumVec2(shape->vertex_array[shape->vertex_count - 1], shape->center_pos);
    renderLine(renderer, a, b, color);
}

void renderLine(SDL_Renderer* renderer, Vec2 a, Vec2 b, Uint32 color)
{
    SDL_SetRenderDrawColor(renderer, EXTRACT_COLOR(color));
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
}

