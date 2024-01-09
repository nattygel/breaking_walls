#pragma once

#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include "objects.hpp"

class Fisics
{
public:
    std::pair<float, float> calculate_rotation(sf::FloatRect ball_bound, sf::FloatRect brick_bound, std::pair<float, float> velocity);

};

class Colisions : public Fisics
{
public:
    State handle(Ball& ball, std::vector<std::shared_ptr<Brick>>& bricks, Paddle& paddle);

private:
    void ball_vs_puddle(Ball& ball, Paddle& paddle);
    void ball_vs_brick(Ball& ball, std::vector<std::shared_ptr<Brick>>& bricks);
    void ball_vs_edge(Ball& ball);
    State ball_vs_floor(Ball& ball, Paddle& paddle);

    void destroy_brick(int index);
    void destroy_paddle();
    void update_ball_velosity(Ball ball);
protected:
};