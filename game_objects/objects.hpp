#pragma once

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include <memory>


class Game_objects
{
public:
    Paddle paddle;
    Ball ball;
    std::vector<std::shared_ptr<Brick>> bricks;
};