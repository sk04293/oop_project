#include "game.hpp"

class texturemanager
{

    public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};