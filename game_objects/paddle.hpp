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
    float get_speed();
private:
    int m_life = 3;
    float m_speed = 35.f;
};
