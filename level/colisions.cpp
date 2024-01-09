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
        std::pair<float, float> new_velocity = ball.velocity();
        float epsilon = 0.002f;

        float middle_x_paddle = paddle.getGlobalBounds().left + paddle.getGlobalBounds().width/2;
        float delta = ball.getPosition().x - ball.getGlobalBounds().width/2 -middle_x_paddle;
        new_velocity.second = -new_velocity.second;
        new_velocity.first = new_velocity.first + epsilon * delta;
        new_velocity = Physics::normalize(new_velocity);
        new_velocity = Physics::scalar_multyply(new_velocity, ball.get_magnitude());
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

    if (ballPosition.x > (float)x_resolution) {
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
            ball.stop_move();
            ball.set_srart_position(paddle.getGlobalBounds());
        }
    }
    return CONTINUE;
}


        // std::cout << "paddle.getPosition().x "<< paddle.getPosition().x << '\n';
        // std::cout << "paddle.getPosition().y " << paddle.getPosition().y << '\n';
        // std::cout << "paddle.getGlobalBounds().width " << paddle.getGlobalBounds().width <<  '\n';
        // std::cout << "paddle.getGlobalBounds().top " << paddle.getGlobalBounds().top <<  '\n';
        // std::cout << "paddle.getGlobalBounds().left " << paddle.getGlobalBounds().left <<  '\n';
        // std::cout << "paddle.getGlobalBounds().height " << paddle.getGlobalBounds().height <<  '\n';
        // std::cout << "paddle.getGlobalBounds().contains(1,1) " << paddle.getGlobalBounds().contains(1,1) <<  '\n';
        // std::cout << "paddle.getGlobalBounds()..intersects(paddle.getGlobalBounds()) " << paddle.getGlobalBounds().intersects(paddle.getGlobalBounds()) <<  '\n';
        // std::cout << "paddle.getPosition().y " << paddle.getPointCount() << '\n';
        // std::cout << "paddle.getPoint(0).x .y " << paddle.getPoint(0).x << ' ' << paddle.getPoint(0).y <<'\n';
        // std::cout << "paddle.getPoint(paddle.getPointCount()/4).x .y " << paddle.getPoint(paddle.getPointCount()/4).x << ' ' << paddle.getPoint(paddle.getPointCount()/4).y <<'\n';
        // std::cout << "paddle.getPoint(paddle.getPointCount()/2).x .y " << paddle.getPoint(paddle.getPointCount()/2).x << ' ' << paddle.getPoint(paddle.getPointCount()/2).y <<'\n';
        // std::cout << "paddle.getPoint(paddle.getPointCount()/4*3).x .y " << paddle.getPoint(paddle.getPointCount()/4*3).x << ' ' << paddle.getPoint(paddle.getPointCount()/4*3).y <<'\n';
        // std::cout << '\n';

        // std::cout << "paddle.getPosition().x "<< ball.getPosition().x << '\n';
        // std::cout << "ball.getPosition().y " << ball.getPosition().y << '\n';
        // std::cout << "ball.getGlobalBounds().width " << ball.getGlobalBounds().width <<  '\n';
        // std::cout << "ball.getGlobalBounds().top " << ball.getGlobalBounds().top <<  '\n';
        // std::cout << "ball.getGlobalBounds().left " << ball.getGlobalBounds().left <<  '\n';
        // std::cout << "ball.getGlobalBounds().height " << ball.getGlobalBounds().height <<  '\n';
        // std::cout << "ball.getGlobalBounds().contains(1,1) " << ball.getGlobalBounds().contains(1,1) <<  '\n';
        // std::cout << "ball.getGlobalBounds()..intersects(ball.getGlobalBounds()) " << ball.getGlobalBounds().intersects(paddle.getGlobalBounds()) <<  '\n';
        // std::cout << "ball.getPosition().y " << ball.getPointCount() << '\n';
        // std::cout << "ball.getPoint(0).x .y " << ball.getPoint(0).x << ' ' << ball.getPoint(0).y <<'\n';
        // std::cout << "ball.getPoint(ball.getPointCount()/4).x .y " << ball.getPoint(ball.getPointCount()/4).x << ' ' << ball.getPoint(ball.getPointCount()/4).y <<'\n';
        // std::cout << "ball.getPoint(ball.getPointCount()/2).x .y " << ball.getPoint(ball.getPointCount()/2).x << ' ' << ball.getPoint(ball.getPointCount()/2).y <<'\n';
        // std::cout << "ball.getPoint(ball.getPointCount()/4*3).x .y " << ball.getPoint(ball.getPointCount()/4*3).x << ' ' << ball.getPoint(ball.getPointCount()/4*3).y <<'\n';
