#include "app.h"
#include <stdlib.h>

int init(App* app)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 0;
    }
    
    app->window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    if (!app->window) {
        return 0;
    }
    
    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer) {
        return 0;
    }
    
    SDL_DisplayMode display;
    SDL_GetCurrentDisplayMode(0, &display);
    app->screen_width = display.w;
    app->screen_height = display.h;
    
    return 1;
}

void close(App* app)
{
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    SDL_Quit();
}

int input(App* app)
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT) {
            return 0;
        }
    }
    return 1;
}

