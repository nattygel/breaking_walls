#include "ball.hpp"
#include <cmath>


Ball::Ball(float r, const sf::Color& color)
{
    setRadius(r);
    setFillColor(color);
    m_speed = std::sqrt(m_velocity.first * m_velocity.first + m_velocity.second * m_velocity.second);
}

void Ball::move1()
{
    this->move(m_velocity.first, m_velocity.second);
}

void Ball::set_velocity(std::pair<float, float> velocity)
{
    m_velocity = velocity;
}

void Ball::set_velocity(float x, float y)
{
    std::pair<float, float> velocity(x, y);
    m_velocity = velocity;
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

std::pair<float, float> Ball::normalize(std::pair<float, float> v)
{
    float length = std::sqrt(v.first * v.first + v.second * v.second);
    if (length != 0) {
        return std::pair<float, float>(v.first/length, v.second/length);
    } else {
        return v;
    }
}

std::pair<float, float> Ball::multyply(std::pair<float, float> v, float n)
{
    return std::pair<float, float>(v.first*n, v.second*n);
}

float Ball::get_speed()
{
    return m_speed;
}
