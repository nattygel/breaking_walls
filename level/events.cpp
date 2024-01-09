#include "events.hpp"
#include "globals.hpp"


void Events::check(sf::Event event, sf::RenderWindow& window, Paddle& paddle)
{
    if (esc(event, window) || arrows(event, window, paddle) || space(event, window))
        return ;
    // return CONTINUE;
}

bool Events::esc(sf::Event event, sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
        return true;
    }
    return false;
}

bool Events::arrows(sf::Event event, sf::RenderWindow& window, Paddle& paddle)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        paddle.move_left();
        return true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (paddle.getPosition().x < (float)x_resolution - paddle.getSize().x) {
            paddle.move_right();
        }
        return true;
    }
    return false;
}
bool Events::space(sf::Event event, sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
        return true;
    }
    return false;
}

