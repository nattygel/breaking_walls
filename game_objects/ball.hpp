#pragma once

#include <SFML/Graphics.hpp>


class Ball : public sf::CircleShape
{
public:
    Ball(float r = 12, const sf::Color& color = sf::Color::Green);
    void move1();
    float x_velocity();
    float y_velocity();
    std::pair<float, float> velocity();
    void set_velocity(std::pair<float, float> velocity);
    void set_velocity(float x, float y);
    std::pair<float, float> normalize(std::pair<float, float> v);
    std::pair<float, float> multyply(std::pair<float, float> v, float n);
    float get_speed();

private:
    std::pair<float, float> m_velocity = std::pair<float, float>(1.3, 1.3);
    float m_speed;
};