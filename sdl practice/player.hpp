#include "game.hpp"

class player
{
    public:
    player(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~player();

    void update();
    void render();


    private:
    int xpos;
    int ypos;

    SDL_Texture* objtexture;
    SDL_Rect srcrect, destrect;
    SDL_Renderer * renderer;

};