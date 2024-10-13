#include "Game.h"

Game::Game() {

	backTexture.loadFromFile("backgroung.png");
	backGround.setTexture(backTexture);
	backGround.setPosition(0, 0);
	logo.loadFromFile("logo.png");
	logoSprite.setTexture(logo);
	font.loadFromFile("calibri.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(20);
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	enemytexture1.loadFromFile("Enemy0.png");
	enemytexture2.loadFromFile("Enemy1.png");
	gameStart = false;
	playTexture.loadFromFile("play.png");
	playSprite.setTexture(playTexture);
	exitTexture.loadFromFile("quit.png");
	exitSprite.setTexture(exitTexture);

	

}
void Game::run() {


	sf::RenderWindow renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),"Space invader");
	backGround.setScale(static_cast<float>(renderWindow.getSize().x) / backTexture.getSize().x,
		static_cast<float>(renderWindow.getSize().y) / backTexture.getSize().y);
	renderWindow.setFramerateLimit(60);
	EnemyManager manager(enemytexture1,enemytexture2);
	while (renderWindow.isOpen())
	{
		
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				renderWindow.close();
			}
			
		}
		if (gameStart == false)
		{
			renderWindow.clear();
			
			playSprite.setPosition(SCREEN_WIDTH/2 -75, SCREEN_HEIGHT/2);
			exitSprite.setPosition(SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 + 100);
			logoSprite.setPosition(SCREEN_WIDTH /2 -200, 10);
			
			renderWindow.draw(logoSprite);
			renderWindow.draw(playSprite);
			renderWindow.draw(exitSprite);
		
			renderWindow.display();

			
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if(playSprite.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow))))
						gameStart = true;
					if (exitSprite.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))) {
						renderWindow.close();
					}
				}
			
			continue;
		}
		if (player.getDead() == true)
		{
			renderWindow.clear();
			text.setString("Game Over");
			scoreText.setString("Your Score: " + std::to_string(player.getScore()));
			scoreText.setPosition(SCREEN_WIDTH / 2 - scoreText.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - 50);
			text.setPosition(SCREEN_WIDTH / 2 - text.getGlobalBounds().width/2, SCREEN_HEIGHT / 2 - 100);
			renderWindow.draw(text);
			renderWindow.draw(scoreText);
			renderWindow.draw(playSprite);
			renderWindow.draw(exitSprite);

			renderWindow.display();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (playSprite.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))) {
					player.reset();
					manager.reset();
					

				}
					
				if (exitSprite.getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))) {
					renderWindow.close();
				}
			}
			continue;
		}
		if (manager.getEnemies().size() == 0) {
			manager.reset();
			player.reset();
			manager.raiseDifficuly();
		}
		
		renderWindow.clear();
		scoreText.setString("Level: "+std::to_string(manager.getDifficuly()));
		scoreText.setPosition(0, 0);
		scoreText.setCharacterSize(15);
		renderWindow.draw(backGround);
		player.draw(renderWindow);
		player.update();
		manager.update(renderWindow);
		
		player.checkEnemyHit(manager.getEnemies());
		player.checkPlayerHit(manager.getBullets());
		player.checkEnemyHitEnd(manager.getEnemies());
		renderWindow.draw(scoreText);
		renderWindow.display();
	}

}
