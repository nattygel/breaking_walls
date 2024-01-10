#pragma once

#include <SFML/Graphics.hpp>


class Brick : public sf::RectangleShape
{
public:
    virtual ~Brick() = default;
    virtual bool coliding() = 0;
};

class Normal_brick : public Brick {
public:
    Normal_brick(float x, float y, const sf::Color& color);
    bool coliding() override;

private:
    int m_life = 1;
};


class Strong_brick : public Brick {
public:
    Strong_brick(float x, float y, const sf::Color& color);
    bool coliding() override;

private:
    int m_life = 3;
};