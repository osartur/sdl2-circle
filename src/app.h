#ifndef APP_H
#define APP_H
#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint32 screen_width;
    Uint32 screen_height;
}
App;

int init(App* app);
void close(App* app);
int input(App* app);

#endif 