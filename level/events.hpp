#pragma once

#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "globals.hpp"
#include "ball.hpp"


class Events 
{
public:
    virtual void esc(sf::RenderWindow& window);

};

class Level_events : Events
{
public:
    virtual State check(sf::RenderWindow& window, Paddle& paddle, Ball& ball);
    virtual bool arrows(sf::RenderWindow& window, Paddle& paddle, Ball& ball);
    virtual bool space(Ball& ball);
    virtual State enter();
};
