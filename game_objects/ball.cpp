#include "ball.hpp"
#include <cmath>
#include "physics.hpp"

Ball::Ball(float r, const sf::Color& color)
{
    setRadius(r);
    setFillColor(color);
    m_magnitude = 0.4f;
}

void Ball::normal_move()
{
    if (m_movement) {
        this->move(m_velocity.first, m_velocity.second);
    }
}

void Ball::set_velocity(std::pair<float, float> velocity)
{
    m_velocity = Physics::normalized_velocity(velocity, get_magnitude());
}

void Ball::set_velocity(float x, float y)
{
    std::pair<float, float> velocity(x, y);
    set_velocity(velocity);
}

float Ball::x_velocity()
{
    return m_velocity.first;
}

float Ball::y_velocity()
{
    return m_velocity.second;
}

std::pair<float, float> Ball::velocity()
{
    return std::pair<float, float>(x_velocity(), y_velocity());
}



void Ball::static_move(sf::FloatRect paddle_bounds)
{
    if (!m_movement) {
        set_srart_position(paddle_bounds);
    }
}


float Ball::get_magnitude()
{
    return m_magnitude * m_speed;
}

void Ball::start_move()
{
    m_movement = true;
}

void Ball::stop_move()
{
    m_movement = false;
}

void Ball::set_srart_position(sf::FloatRect paddle_rect)
{
    float x = paddle_rect.left + paddle_rect.width/2;
    float y = paddle_rect.top -paddle_rect.height - getRadius() - 10;
    setPosition(x, y);
    set_velocity(0.3f, -0.7f);
    // set_speed
}
