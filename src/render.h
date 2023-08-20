#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include "shape.h"

void renderShape(SDL_Renderer* renderer, const Shape* shape, Uint32 color);
void renderLine(SDL_Renderer* renderer, Vec2 a, Vec2 b, Uint32 color);

#endif