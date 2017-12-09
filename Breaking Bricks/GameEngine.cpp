#include "GameEngine.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{
	
}

void GameEngine::run()
{
	//float velocity = 0.45f;
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
		score.update();

		// render
		ball.draw(window);
		paddle.draw(window);
		brickHandler.draw(window);
		score.draw(window);

		window.display();
	}
}

void GameEngine::canPaddleMove(float rectVelocity)
{
}

void GameEngine::upadteWindow(sf::RenderWindow &window, float rectVelocity)
{
	//BrickHandler brickHandler = BrickHandler(window.getSize().x);

	//ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y - ball.getRadius() - 100);

	//paddle.setPosition(window.getSize().x / 2 - paddle.getRectWidth() / 2, window.getSize().y - paddle.getRectHeight());
	//window.clear();
	//// update
	//paddle.update();
	//if (!ball.update(paddle)) // player did not hit the ground, and survived
	//{
	//	ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y - ball.getRadius() - 100);
	//	paddle.setPosition(window.getSize().x / 2 - paddle.getRectWidth() / 2, window.getSize().y - paddle.getRectHeight());
	//	brickHandler.resetGame();
	//	ball.setVelocityX(-(ball.getBallVelocity()));
	//	ball.setVelocityY(-(ball.getBallVelocity()));
	//}

	//brickHandler.update(ball);

	//// render
	//ball.draw(window);
	//paddle.draw(window);
	//brickHandler.draw(window);
	//window.display();

}

