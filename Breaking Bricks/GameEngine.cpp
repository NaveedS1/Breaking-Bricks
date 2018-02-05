#include "GameEngine.h"

GameEngine::GameEngine()
{
	for (int i = 0; i < 10; i++)
	{
		this->highScore[i] = 0;
	}
}

GameEngine::~GameEngine()
{
	
}

void GameEngine::run()
{
	//float velocity = 0.45f;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Breaking Bricks Game");

	BrickHandler brickHandler = BrickHandler(window.getSize().x, score, sound);

	Ball ball = Ball(window.getSize().x, window.getSize().y);
	//ball.setPosition(window.getSize().x / 2 - ball.getRadius(), window.getSize().y - ball.getRadius() - 100);

	Paddle paddle = Paddle(window.getSize().x, window.getSize().y);
	//paddle.setPosition(window.getSize().x / 2 - paddle.getRectWidth() / 2, window.getSize().y - paddle.getRectHeight());

	// load highscore
	std::ifstream loadFile;
	loadFile.open("../Resource/HighScore.txt");
	if (loadFile.is_open())
	{
		std::cout << "Highscore List" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (!loadFile.eof())
			{
				loadFile >> highScore[i];
				loadFile.ignore();

				if (highScore[i] <= 0)
				{
					highScore[i] = 0;
				}
				else
				{
					std::cout << highScore[i] << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << " Error read file\n";
	}
	loadFile.close();

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

		if (!ball.update(paddle)) // player hit the ground, and not the paddle
		{
			ball.reset();
			paddle.reset();
			score.removeLife();
			
			if (score.getLives() <= 0)
			{
				// save new highscore if it is new
				for (int i = 0; i < 10; i++) {
					// loop and search if the new score is a highscore
					if (score.getScore() > highScore[i] || highScore[i] == 0) {
						std::ofstream writeFile("../Resource/HighScore.txt");
						if (writeFile.is_open())
						{
							{
								// move all scores down from the lowest position to leave place for the new score
								for (int c = 9; c >= i; c--) {
									highScore[c] = highScore[c - 1];
								}

								// set new highscore
								highScore[i] = score.getScore();

								std::cout << "New Highscore!! You got position " << i + 1 << " out of 10. ";
								
								// save highscores to file
								for (int j = 0; j < 10; j++)
								{
									if (highScore[j] == 0) break; // if highscore is zero stop printing
									writeFile << highScore[j] << std::endl;
								}
							}
						}
						writeFile.close();
						break;
					}
				}

				std::cout << "Score: " << score.getScore() << std::endl;

				brickHandler.resetGame();
				score.reset();


				// ask the play to play again, if not then exit
				std::cout << "Do you want to play again? (y/n)";
				std::string response;
				std::cin >> response;

				if (response != "y")
				{
					return;
				}
			}
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

