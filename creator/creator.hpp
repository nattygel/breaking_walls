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
    std::vector<std::shared_ptr<Brick>> bricks_step_2();
    std::vector<std::shared_ptr<Brick>> bricks_step_3();
    std::vector<std::shared_ptr<Brick>> bricks_step_4();
    std::vector<std::shared_ptr<Brick>> bricks_step_5();
    std::vector<std::shared_ptr<Brick>> bricks_step_6();
    std::vector<std::shared_ptr<Brick>> bricks_step_7();

private:
    sf::Color m_colors[10] = {
        sf::Color(255, 0, 0),      // Red
        sf::Color(0, 255, 0),      // Green
        sf::Color(0, 0, 255),      // Blue
        sf::Color(255, 255, 0),    // Yellow
        sf::Color(255, 0, 255),    // Magenta
        sf::Color(0, 255, 255),    // Cyan
        sf::Color(255, 165, 0),    // Orange
        sf::Color(255, 192, 203),  // Pink
        sf::Color(128, 0, 128),    // Purple
        sf::Color(255, 215, 0)     // Gold
    };
};