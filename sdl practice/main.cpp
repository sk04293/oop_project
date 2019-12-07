#include "game.hpp"
#include <iostream>

game *Game = nullptr;

int main(int argc, char **argv)
{
    const int fps = 60;
    const int framedelay = 1000/ fps;

    Uint32 framestart; //to set the framerate of the game
    int frametime;

    Game = new game();

    Game->init("Crazy Taxi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (Game->running())
    {
        framestart = SDL_GetTicks();

        Game->handleevents();
        Game->update();
        Game->render();

        frametime = SDL_GetTicks() - framestart;

        if (framedelay > frametime)
        {
            SDL_Delay(framedelay-frametime);
        }
    }
    Game->clean();

    return 0;
}
