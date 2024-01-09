#pragma once

#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include "events.hpp"
#include "colisions.hpp"
#include "menegger.hpp"
#include "globals.hpp"


// enum state{ CONTINUE, STEP_UP };


class Screen
{
public:
    Screen(sf::RenderWindow& window);
    virtual ~Screen() = default;
    virtual State run() = 0;

protected:
    sf::RenderWindow& m_window;
};


class Game_over_screen : public Screen
{
    State run();
};

class Level : public Screen
{
public:
    Level(sf::RenderWindow& window);
    virtual ~Level() = default;
    virtual State run() = 0;

protected:
    Events m_events;
    Colisions m_colisions;
};


class Basic_lvel : public Level, public Create_level
{
public:
    Basic_lvel(sf::RenderWindow& window, int step = 1);
    virtual ~Basic_lvel() = default;
    virtual State run();
    virtual State handle_events(sf::Event event, sf::RenderWindow& window, Paddle& paddle);
    virtual void Process();

private:
    virtual void pause(){};
    virtual void continued(){};

protected:
    Paddle paddle;
    Ball ball;
    std::vector<std::shared_ptr<Brick>> bricks;
};

