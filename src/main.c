#include <stdlib.h>
#include <math.h>
#include "app.h"
#include "shape.h"
#include "render.h"

int main()
{
    App* app = malloc(sizeof(App));
    if (!init(app)) {
        return EXIT_FAILURE;
    }
    
    float radius = 450.f;
    Vec2 center = {app->screen_width/2, app->screen_height/2};
    Shape* circle = createShape(radius, center, 360);
    
    while (input(app)) {
        SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
        SDL_RenderClear(app->renderer);
        
        renderShape(app->renderer, circle, 0xffffff);
        
        SDL_RenderPresent(app->renderer);
    }
    
    destroyShape(circle);
    
    close(app);
    free(app);
    
    return EXIT_SUCCESS;
}
