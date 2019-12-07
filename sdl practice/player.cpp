
#include "SDL.h"
#include "texturemanager.hpp"
#include "player.hpp"

player::player(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{

    renderer = ren;
    objtexture = texturemanager::LoadTexture(texturesheet, ren);
    xpos = x;
    ypos = y;
}

void player::update()
{

    srcrect.h = 32;
    srcrect.w = 32;
    srcrect.x = 0;
    srcrect.y = 0;

    destrect.x = xpos;
    destrect.y = ypos;
    destrect.w = (srcrect.w*2);
    destrect.h = (srcrect.h*2);
    

}

void player::render()
{
    SDL_RenderCopy(renderer, objtexture, NULL, &destrect);
}