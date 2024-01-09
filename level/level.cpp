#include "level.hpp"
#include "events.hpp"
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include "colisions.hpp"
#include <memory>


State Basic_lvel::handle_events(sf::Event event, sf::RenderWindow& window, Paddle& paddle)
{
    m_events.check(event, window, paddle);
    return CONTINUE;
}


Screen::Screen(sf::RenderWindow &window)
: m_window(window)
{
}


State Game_over_screen::run()
{
    return CONTINUE;
}


Level::Level(sf::RenderWindow& window)
: Screen(window)
{
}


Basic_lvel::Basic_lvel(sf::RenderWindow& window, int step)
: Level(window)
{
    paddle = create_paddle();
    ball = create_ball();
    bricks = create_bricks(step);
    // m_colisions = Colisions();
}


State Basic_lvel::run()
{

    sf::Event event;
    while (m_window.pollEvent(event)) {
        m_events.check(event, m_window, paddle);
    }

    State resolt = m_colisions.handle(ball, bricks, paddle);
    if (resolt == GAME_OVER) {
        return resolt;
    }

    ball.move(ball.x_velocity(), ball.y_velocity());    
    
    m_window.clear();

    m_window.draw(ball);
    m_window.draw(paddle);
    for (const auto& brick : bricks) {
        m_window.draw(*brick);
    }

    m_window.display();

    return CONTINUE;
}

void Basic_lvel::Process()
{}

