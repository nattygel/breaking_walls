#pragma once

#include <SFML/Graphics.hpp>


class Ball : public sf::CircleShape
{
public:
    Ball(float r = 12, const sf::Color& color = sf::Color::Green);
    void moving();
    float x_velocity();
    float y_velocity();
    std::pair<float, float> velocity();
    void set_velocity(std::pair<float, float> velocity);
    void set_velocity(float x, float y);

    void static_move(sf::FloatRect paddle_move);
    float get_magnitude();
    float get_speed();
    void set_speed(float speed);
    void start_move();
    void stop_move();
    void set_strart_position(sf::FloatRect paddle_rect);

private:
    std::pair<float, float> m_velocity;
    float m_magnitude;
    float m_speed = 1;
    bool m_movement = false;

};