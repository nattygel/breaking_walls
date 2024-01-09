#pragma once

#include <SFML/Graphics.hpp>


class Paddle : public sf::RectangleShape
{
public:
    Paddle();
    virtual ~Paddle() = default;
    bool coliding();
    void reduce_life();
    void move_right();
    void move_left();
private:
    int m_life = 3;
};
