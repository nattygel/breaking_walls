#include "physics.hpp"
#include <cmath>

namespace Physics
{

std::pair<float, float> calculate_rotation(sf::FloatRect ball_bound, sf::FloatRect brick_bound, std::pair<float, float> velocity)
{
    std::pair<float, float> new_velocity;

    float overlapTop = ball_bound.top + ball_bound.height - brick_bound.top;
    float overlapBottom = brick_bound.top + brick_bound.height - ball_bound.top;
    float overlapLeft = ball_bound.left + ball_bound.width - brick_bound.left;
    float overlapRight = brick_bound.left + brick_bound.width - ball_bound.left;

    if (overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight)
    {
        new_velocity = std::pair<float, float>(velocity.first, -velocity.second);
    }
    else if (overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight)
    {
        new_velocity = std::pair<float, float>(velocity.first, -velocity.second);
    }
    else if (overlapLeft < overlapTop && overlapLeft < overlapBottom && overlapLeft < overlapRight)
    {
        new_velocity = std::pair<float, float>(-velocity.first, velocity.second);
    }
    else if (overlapRight < overlapTop && overlapRight < overlapBottom && overlapRight < overlapLeft)
    {
        new_velocity = std::pair<float, float>(-velocity.first, velocity.second);
    }

    return new_velocity;
}


std::pair<float, float> normalize(std::pair<float, float> v)
{
    float length = std::sqrt(v.first * v.first + v.second * v.second);
    if (length != 0) {
        return std::pair<float, float>(v.first/length, v.second/length);
    } else {
        return v;
    }
}


std::pair<float, float> scalar_multyply(std::pair<float, float> v, float n)
{
    return std::pair<float, float>(v.first*n, v.second*n);
}


std::pair<float, float> normalized_velocity(std::pair<float, float> velocity, float magnitude)
{
    std::pair<float, float> new_velocity = Physics::normalize(velocity);
    new_velocity = Physics::scalar_multyply(new_velocity, magnitude);
    return new_velocity;
}



} // end namespace Physics
