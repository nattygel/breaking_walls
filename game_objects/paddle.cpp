#include "paddle.hpp"
#include "globals.hpp"


Paddle::Paddle()
{
    float paddle_width = 150.f;
    float paddle_height = 10.f;
    setSize(sf::Vector2f(paddle_width, paddle_height));
    setFillColor(sf::Color::Blue);
    setPosition((float)x_resolution/2 - paddle_width/2 ,(float)y_resolution - 40);
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
    if (getPosition().x + getSize().x + m_speed > (float)x_resolution) {
        setPosition((float)x_resolution - getSize().x, getPosition().y);
    } else {
        move(m_speed, 0);
    }
}


void Paddle::move_left()
{
    if (getPosition().x -m_speed > 0) {
        move(-m_speed, 0);
    } else {
        setPosition(0, getPosition().y);
    }
}

float Paddle::get_speed()
{
    return m_speed;
}

