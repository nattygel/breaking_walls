#include "menegger.hpp"
#include <vector>
#include <memory> 



std::vector<std::shared_ptr<Brick>> Create_level::create_bricks(int step)
{
    if (step == 1) {
        return bricks_step_1();
    }
    return bricks_step_1();
}

    std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_1()
{
    sf::Color colors[5] = {
        sf::Color(100, 250, 50),
        sf::Color(200, 50, 150),
        sf::Color(50, 150, 200),
        sf::Color(250, 100, 50),
        sf::Color(150, 200, 100)
    };

    float rows = 5;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 5.f;
    float top_margin = 150.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (int i = 0; (float)i < rows; ++i) {
        for (int j = 0; (float)j < columns; ++j) {
            auto brick = std::make_shared<Strong_brick>(brick_width, brick_height, colors[i]);
            float y = top_margin + (float)i * (brick_height + brick_margin);
            float x = start_row + (float)j * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}

Paddle Create_level::create_paddle()
{
    Paddle p;
    return p;
}


void Create_level::create_objects(std::shared_ptr<Game_objects>& game_objects) {
    game_objects = std::make_shared<Game_objects>();
    game_objects->ball = create_ball();
    game_objects->bricks = create_bricks();
    game_objects->paddle = create_paddle();
}

Ball Create_level::create_ball()
{
    Ball b;
    return b;
}
