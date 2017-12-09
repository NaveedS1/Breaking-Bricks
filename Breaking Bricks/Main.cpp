#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "BrickHandler.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Breaking Bricks Game");

	BrickHandler brickHandler = BrickHandler(window.getSize().x);
	
	Ball ball;
	ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y - ball.getRadius() - 100);
	
	Paddle paddle = Paddle();
	paddle.setPosition(window.getSize().x / 2 - paddle.getRectWidth() / 2, window.getSize().y - paddle.getRectHeight());
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		
		// update
		paddle.update();
		if (!ball.update(paddle)) // player did not hit the ground, and survived
		{
			ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y - ball.getRadius() - 100);
			paddle.setPosition(window.getSize().x / 2 - paddle.getRectWidth() / 2, window.getSize().y - paddle.getRectHeight());
			brickHandler.resetGame();
			ball.setVelocityX(-(ball.getBallVelocity()));
			ball.setVelocityY(-(ball.getBallVelocity()));
		}

		brickHandler.update(ball);

		// render
		ball.draw(window);
		paddle.draw(window);
		brickHandler.draw(window);

		window.display();
    }
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
*/
	return 0;
}