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
    m_events.check(window, paddle, ball);
    return CONTINUE;
}


Screen::Screen(sf::RenderWindow &window)
: m_window(window)
{
}


Game_over_screen::Game_over_screen(sf::RenderWindow& window)
: Screen(window)
{
    // Load font (replace "arial.ttf" with the path to your font file)
    if (!font.loadFromFile("arial.ttf"))
    {
        // Handle font loading error
        // You can print an error message or throw an exception
    }

    // Configure the "Game Over!" text
    gameOverText.setFont(font);
    gameOverText.setString("Game Over!");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Red);

    // Center the text on the screen
    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setPosition(((float)x_resolution - textBounds.width) / 2, ((float)y_resolution - textBounds.height) / 2);

}


State Game_over_screen::run()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        m_events.esc(m_window);
    }
    m_window.clear();
    m_window.draw(gameOverText);
    m_window.display();

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
    ball.set_strart_position(paddle.getGlobalBounds());
    bricks = create_bricks(step);
    // m_colisions = Colisions();
}


State Basic_lvel::run()
{

    State resolt = m_colisions.handle(ball, bricks, paddle);
    // if (resolt == GAME_OVER) {
    //     return resolt;
    // }

    sf::Event event;
    while (m_window.pollEvent(event)) {
        resolt = m_events.check(m_window, paddle, ball);
    }

    ball.normal_move();    
    
    m_window.clear();
    m_window.draw(ball);
    m_window.draw(paddle);
    for (const auto& brick : bricks) {
        m_window.draw(*brick);
    }

    m_window.display();

    if (bricks.empty()) {
        resolt = State::STEP_UP;
    }

    return resolt;
}

void Basic_lvel::Process()
{}


