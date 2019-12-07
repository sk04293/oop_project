#include "game.hpp"
#include "texturemanager.hpp"
#include "object.hpp"
#include "player.hpp"

vehicle* car;
player *taxi;

game::game()
{

}
game::~game()
{

}

void game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
    
        std::cout << "Subsystems initalised!..." <<std::endl;
        window= SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
            std::cout << "renderer created" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }  
    car = new vehicle("sprite2.png", renderer, 250, 2);
    taxi = new player("sprite2.png", renderer, 350, 500);
}

void game::handleevents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

}
void game:: render()
{
    SDL_RenderClear(renderer);

    car->render();
    taxi->render();

    SDL_RenderPresent(renderer);
}
void game:: clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
    std::cout << "Game cleaned" <<std::endl;
}

void game::update()
{
    car ->update();
    taxi->update();

}
