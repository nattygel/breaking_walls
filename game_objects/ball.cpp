#include "ball.hpp"
#include <cmath>
#include "physics.hpp"
#include <vector>
#include <random>
#include <iostream>

Ball::Ball(float r, const sf::Color& color)
{
    setRadius(r);
    setFillColor(color);
    set_velocity(new_velocity());
}

void Ball::normal_move()
{
    if (m_movement) {
        this->move(m_velocity.first * m_speed, m_velocity.second *m_speed);
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


float Ball::get_magnitude()
{
    return m_magnitude * m_speed;
}

float Ball::get_speed()
{
    return m_speed;
}

void Ball::set_speed(float speed)
{
    m_speed = speed;
}

void Ball::start_move()
{
    m_movement = true;
    std::cout << x_velocity() << ' ' << y_velocity() << '\n';
}

void Ball::reset(sf::FloatRect paddle_rect)
{
    set_to_paddle_position(paddle_rect);
    set_velocity(new_velocity());
    m_movement = false;
}


void Ball::static_move(sf::FloatRect paddle_bounds)
{
    if (!m_movement) {
        set_to_paddle_position(paddle_bounds);
    }
}


void Ball::set_to_paddle_position(sf::FloatRect paddle_rect)
{
    float x = paddle_rect.left + paddle_rect.width/2 - getRadius();
    float y = paddle_rect.top -paddle_rect.height - getRadius() - 5;
    setPosition(x, y);
}

std::pair<float, float> Ball::new_velocity()
{
    std::vector<std::pair<float, float>> vector;
    for (float i = -5; i<10; ++i) {
        vector.push_back(std::make_pair(i, 4.f));
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, vector.size() - 1);

    return vector[dis(gen)];
}
