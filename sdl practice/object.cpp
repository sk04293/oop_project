#include "object.hpp"
#include "SDL.h"
#include "texturemanager.hpp"

vehicle::vehicle(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{

    renderer = ren;
    objtexture = texturemanager::LoadTexture(texturesheet, ren);
    xpos = x;
    ypos = y;
}

void vehicle::update()
{
    xpos = xpos - 0.2;
    ypos = ypos + 0.2;

    srcrect.h = 32;
    srcrect.w = 32;
    srcrect.x = 0;
    srcrect.y = 0;

    destrect.x = xpos;
    destrect.y = ypos++;
    destrect.w = (srcrect.w*2);
    destrect.h = (srcrect.h*2);
    

}

void vehicle::render()
{
    SDL_RenderCopy(renderer, objtexture, NULL, &destrect);
}