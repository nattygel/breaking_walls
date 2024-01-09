#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "brick.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "objects.hpp"
#include <memory> 
#include "globals.hpp"



class Creator
{
public:
    ~Creator() = default;
    // virtual Objects create() = 0;
};


class Create_level : public Creator 
{
public:
    void create_objects(std::shared_ptr<Game_objects>& game_objects);
    
protected:
    Ball create_ball();
    Paddle create_paddle();
    std::vector<std::shared_ptr<Brick>> create_bricks(int step = 1);
    std::vector<std::shared_ptr<Brick>> bricks_step_1();
};