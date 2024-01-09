#pragma once

#include <SFML/Graphics.hpp>
#include <utility>


namespace Physics
{
    std::pair<float, float> calculate_rotation(sf::FloatRect ball_bound, sf::FloatRect brick_bound, std::pair<float, float> velocity);
    std::pair<float, float> normalize(std::pair<float, float> v);
    std::pair<float, float> scalar_multyply(std::pair<float, float> v, float n);
    std::pair<float, float> normalized_velocity(std::pair<float, float> v, float magnitude);

} // end namespace Physics
