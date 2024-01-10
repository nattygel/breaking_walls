#include "creator.hpp"
#include <vector>
#include <memory> 



std::vector<std::shared_ptr<Brick>> Create_level::create_bricks(int step)
{
    if (step == 1) {
        return bricks_step_1();
    } else if (step == 2) {
        return bricks_step_2();
    } else if (step == 3) {
        return bricks_step_3();
    } else if (step == 4) {
        return bricks_step_4();
    // } else if (step == 5) {
    //     return bricks_step_5();
    // } else if (step == 6) {
    //     return bricks_step_6();
    // } else if (step == 7) {
    //     return bricks_step_7();
    }
    return bricks_step_1();
}

    std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_1()
{
    float rows = 5;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 150.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns; j += 1) {
            std::shared_ptr<Brick> brick;
            if((int)i % 2 != 0) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + j * (brick_width + brick_margin);
            x += ((int)i % 2 == 1) ? brick_width / 2 : 0;
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}


std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_2()
{
    float rows = 10;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns - i; j += 1) {
            std::shared_ptr<Brick> brick;
            if((int)i % 2 != 0) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + (float)(j+i/2) * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}


std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_3()
{
    float rows = 10;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < i; j += 1) {
            std::shared_ptr<Brick> brick;
            if((int)i % 2 != 0) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + j * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}

std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_4()
{
    float rows = 10;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns - i; j += 1) {
            std::shared_ptr<Brick> brick;
            if ((int)i % 2 == 0) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + (float)(columns - i) * 0.5f * (brick_width + brick_margin) + j * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}


std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_5()
{
    float rows = 10;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns; j += 1) {
            std::shared_ptr<Brick> brick;
            if (j == i) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + j * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}


std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_6()
{
    float rows = 10;
    float columns = 10;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns; j += 1) {
            std::shared_ptr<Brick> brick;
            if (std::abs(j - columns / 2) + std::abs(i - rows / 2) <= rows / 2) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + j * (brick_width + brick_margin);
            brick->setPosition(x, y);
            bricks.push_back(brick);
        }
    }
    return bricks;
}


std::vector<std::shared_ptr<Brick>> Create_level::bricks_step_7()
{
    float rows = 10;
    float columns = 7;
    float brick_width = 100.0f;
    float brick_height = 40.0f;
    float brick_margin = 8.f;
    float top_margin = 100.f;
    float start_row = ((float)x_resolution - columns * (brick_width + brick_margin))/2;

    std::vector<std::shared_ptr<Brick>> bricks;
    for (float i = 0; (int)i < rows; i += 1) {
        for (float j = 0; (int)j < columns; j += 1) {
            std::shared_ptr<Brick> brick;
            if ((int)i % 2 == 0) {
                brick = std::make_shared<Strong_brick>(brick_width, brick_height, m_colors[(int)i]);
            } else {
                brick = std::make_shared<Normal_brick>(brick_width, brick_height, m_colors[(int)i]);
            }
            float y = top_margin + i * (brick_height + brick_margin);
            float x = start_row + ((int)i % 2 == 0 ? j : columns - j - 1) * (brick_width + brick_margin);
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
