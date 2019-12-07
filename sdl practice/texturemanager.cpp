#include "texturemanager.hpp"
#include "SDL_image.h"
#include "SDL.h"

SDL_Texture* texturemanager::LoadTexture(const char* filename, SDL_Renderer* ren)
{
    SDL_Surface* tempsurface = IMG_Load(filename);
    if (!tempsurface)
    {
        std::cout << "surface cant" << std::endl;
    }
    else
    {
        std::cout << "surface loaded" << std::endl;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempsurface);
    SDL_FreeSurface(tempsurface);

    return tex;
}