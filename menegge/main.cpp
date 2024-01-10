#include <SFML/Graphics.hpp>
#include "game.hpp"


int main()
{
    Game game;
    game.play();

    return 0;
}




        // while (window.pollEvent(event))
        // {
        //     step_1.handle_events();
        // }


        // {
        //     if (event.type == sf::Event::Closed)
        //         window.close();
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        //         window.close();
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        //         // shape.move(-100,-100);
        //         ball.move(-100,-100);
        // }


        // shape.move(0.1,0.1);    
        // shape.setFillColor(sf::Color(100, 250, 50));
        // ball.setFillColor(sf::Color(100, 50, 50));
        
        // ball.normal_move();    
        
        // window.clear();



        // window.draw(shape);
        // window.draw(ball);
        // for (const auto& brick : bricks) {
        //     window.draw(brick);
        // }


        // window.display();
