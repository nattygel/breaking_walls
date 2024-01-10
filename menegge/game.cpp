#include "game.hpp"
#include "level.hpp"
#include "globals.hpp"
#include <memory>
#include <iostream>



void Game::play()
{
    sf::RenderWindow window(sf::VideoMode(x_resolution, y_resolution), "breaking_walls!");
    window.setFramerateLimit(60);
    std::shared_ptr<Screen> screen = std::make_shared<Basic_lvel>(window);

    while (window.isOpen())
    {
        State state = screen->run();

        switch (state)
        {
        case CONTINUE:
            break;
        case GAME_OVER:
            screen = std::make_shared<Game_over_screen>(window);
            break;
        case STEP_UP:
            std::cout << "step: " << m_step << '\n';
            step_up();
            screen = std::make_shared<Basic_lvel>(window, get_step());
            break;
        default:
            break;
        }
    }
}

int Game::get_step()
{
    return m_step;
}

void Game::step_up()
{
    m_step += 1;
}
