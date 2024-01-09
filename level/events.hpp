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
    virtual bool arrows(Paddle& paddle, Ball& ball);
    virtual bool space(Ball& ball);
    virtual void check(sf::Event event, sf::RenderWindow& window, Paddle& paddle, Ball& ball);

};
