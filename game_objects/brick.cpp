#include "brick.hpp"

Normal_brick::Normal_brick(float x, float y, const sf::Color& color)
{
    setSize(sf::Vector2f(x, y));
    setFillColor(color);
}

bool Normal_brick::coliding()
{
    m_life -= 1;
    if (m_life <= 0) {
        return true;
    }
    return false;
}


Strong_brick::Strong_brick(float x, float y, const sf::Color& color)
{
    setSize(sf::Vector2f(x, y));
    setFillColor(color);
}

bool Strong_brick::coliding()
{
    m_life -= 1;
    if (m_life <= 0) {
        return true;
    } else if (m_life == 2) {
        // setFillColor(sf::Color::Transparent);
        setFillColor(sf::Color(128, 128, 128, 200));
        // setOutlineThickness(2.0f);
        // setFillColor(sf::Color::White);
    } else if (m_life == 1) {
        setFillColor(sf::Color(255, 255, 255, 200));
        sf::Vector2f size = getSize();
        sf::Vector2f position = getPosition();
        setSize(sf::Vector2f(size.x - 20, size.y - 10));
        setPosition(position.x + 10, position.y + 5);
    }
    // setFillColor(sf::Color::White);
    // setOutlineThickness(20.0f);
    return false;
}



sf::Color rowColors[] = {
    sf::Color(100, 250, 50),
    sf::Color(200, 50, 150),
    sf::Color(50, 150, 200),
    sf::Color(250, 100, 50),
    sf::Color(150, 200, 100)
};