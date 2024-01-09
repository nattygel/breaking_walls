#include "paddle.hpp"
#include "globals.hpp"


Paddle::Paddle()
{
    float paddle_width = 150.f;
    float paddle_height = 10.f;
    setSize(sf::Vector2f(paddle_width, paddle_height));
    setFillColor(sf::Color::Blue);
    setPosition((float)x_resolution/2 - paddle_width/2 ,(float)y_resolution + 10);
}


bool Paddle::coliding()
{
    reduce_life();
    if (m_life <= 0) {
        return true;
    }
    return false;
}


void Paddle::reduce_life()
{
    m_life -= 1;
}


void Paddle::move_right()
{
    move(35.f, 0);
    if (getPosition().x > (float)x_resolution - getSize().x) {
        setPosition((float)x_resolution - getSize().x, getPosition().y);
    }
}


void Paddle::move_left()
{
    if (getPosition().x > 0) {
        move(-35.f, 0);
    }
    if (getPosition().x < 0) {
        setPosition(0, getPosition().y);
    }
}