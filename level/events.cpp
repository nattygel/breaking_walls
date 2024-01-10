#include "events.hpp"
#include "globals.hpp"
#include "ball.hpp"


void Level_events::check(sf::RenderWindow& window, Paddle& paddle, Ball& ball)
{
    esc(window);
    if (arrows(paddle, ball) || space(ball))
        return ;
    // return CONTINUE;
}

void Events::esc(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
        // return true;
    }
    // return false;
}

bool Level_events::arrows(Paddle& paddle, Ball& ball)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        paddle.move_left();
        ball.static_move(paddle.getGlobalBounds());
        return true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (paddle.getPosition().x < (float)x_resolution - paddle.getSize().x) {
            paddle.move_right();
            ball.static_move(paddle.getGlobalBounds());
        }
        return true;
    }
    return false;
}
bool Level_events::space(Ball& ball)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        ball.start_move();
    }
    return false;
}

