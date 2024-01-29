#include "colisions.hpp"
#include "globals.hpp"
#include <iostream>
#include <memory>
#include "physics.hpp"

State Colisions::handle(Ball &ball, std::vector<std::shared_ptr<Brick>>& bricks, Paddle& paddle)
{
    ball_vs_brick(ball, bricks);
    ball_vs_edge(ball);
    ball_vs_puddle(ball, paddle);
    return ball_vs_floor(ball, paddle);
}

void Colisions::ball_vs_puddle(Ball &ball, Paddle &paddle)
{
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        float epsilon = 0.08f;
        float middle_x_paddle = paddle.getGlobalBounds().left + paddle.getGlobalBounds().width/2;
        float delta = ball.getPosition().x - ball.getGlobalBounds().width/2 -middle_x_paddle;

        std::pair<float, float> new_velocity = ball.velocity();
        new_velocity.second = -new_velocity.second;
        new_velocity.first = new_velocity.first/2 + epsilon * delta;
        ball.set_speed(ball.get_speed() + 0.01f);
        ball.set_velocity(new_velocity);
    }
}

void Colisions::ball_vs_brick(Ball &ball, std::vector<std::shared_ptr<Brick>>& bricks)
{
    for (auto it = bricks.begin(); it != bricks.end();) {
        if (ball.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
            std::pair<float, float> new_velocity = Physics::calculate_rotation(ball.getGlobalBounds(), (*it)->getGlobalBounds(), ball.velocity());
            ball.set_velocity(new_velocity);
            if ((*it)->coliding()) {
               it = bricks.erase(it);
            } else {
                ++it;
            }
            break;
        } else {
            ++it;
        }
    }
}

void Colisions::ball_vs_edge(Ball &ball)
{
    sf::Vector2f ballPosition = ball.getPosition();

    if (ballPosition.y < 0) {
        ball.set_velocity(ball.x_velocity(), -ball.y_velocity());
    }

    if (ballPosition.x < 0) {
        ball.set_velocity(-ball.x_velocity(), ball.y_velocity());
    }

    if (ballPosition.x + ball.getGlobalBounds().width > (float)x_resolution) {
        ball.set_velocity(-ball.x_velocity(), ball.y_velocity());
    }
}

State Colisions::ball_vs_floor(Ball &ball, Paddle& paddle)
{
    if (ball.getPosition().y > (float)y_resolution) {
        ball.set_velocity(ball.x_velocity(), -ball.y_velocity());
        if (paddle.coliding()) {
            return GAME_OVER;
        } else {
            ball.reset(paddle.getGlobalBounds());
        }
    }
    return CONTINUE;
}
