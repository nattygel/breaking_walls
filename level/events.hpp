#pragma once

#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "globals.hpp"

class Events
{
public:
    virtual bool arrows(sf::Event event, sf::RenderWindow& window, Paddle& paddle);
    virtual bool esc(sf::Event event, sf::RenderWindow& window);
    virtual bool space(sf::Event event, sf::RenderWindow& window);
    virtual void check(sf::Event event, sf::RenderWindow& window, Paddle& paddle);

};
