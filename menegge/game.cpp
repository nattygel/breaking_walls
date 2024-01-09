#include "game.hpp"
#include "level.hpp"
#include "globals.hpp"
#include <memory>



void Game::paly()
{
    sf::RenderWindow window(sf::VideoMode(x_resolution, y_resolution), "breaking_walls!");
    std::shared_ptr<Screen> screen = std::make_shared<Basic_lvel>(window);
    Colisions colisions;


    while (window.isOpen())
    {
        State state = screen->run();

        switch (state)
        {
        case CONTINUE:
            break;
        case GAME_OVER:

            break;
        default:
            break;
        }
    }
}