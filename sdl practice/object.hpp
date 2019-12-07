#include "game.hpp"

class vehicle
{
    public:
    vehicle(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~vehicle();

    void update();
    void render();


    private:
    int xpos;
    int ypos;

    SDL_Texture* objtexture;
    SDL_Rect srcrect, destrect;
    SDL_Renderer * renderer;

};