#include "Game.h"

Game::Game()
{
	initWindow();
	initVariables();
	initBackground();
	initFont();
}

Game::~Game()
{
}

void Game::initFont()
{
	// "C:\Users\lacer\OneDrive\Área de Trabalho\repos\SFML_FLAPPY-BIRD\SFML_FLAPPY-BIRD\Files\font.otf"
	font.loadFromFile("Files/font.otf");
	text.setFont(font);

	gameOver.setFont(font);
	gameOver.setCharacterSize(60);
	gameOver.setFillColor(sf::Color::Red);
	gameOver.setPosition(280, 250);
}

void Game::updatePoints()
{
	std::stringstream ss, so;
	ss << "POINTS: " << Points;
	Points++;
	text.setString(ss.str());
	so << "GAME OVER!\n" << ss.str();
	gameOver.setString(so.str());
}

void Game::renderPoints()
{
	window->draw(text);
}

void Game::initBackground()
{
	//"C:\Users\lacer\OneDrive\Área de Trabalho\repos\SFML_FLAPPY-BIRD\SFML_FLAPPY-BIRD\Files\sky.jpg"
	texture.loadFromFile("Files/sky.jpg");
	sprite.setTexture(texture);
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Flappy Bird", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(144);
	window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
	Points = 0;
	spawnTimerMax = 2000;
	spawnTimer = spawnTimerMax;
	playerVivo = true;
}

void Game::initEnemies()
{
}

void Game::run()
{
	while (window->isOpen())
	{
		pollEvents();

		if (playerVivo)
		update();
		
		render();
	}
}

void Game::update()
{

	updateEnemies();
	player.update();
	updateCollision();
	updateLimits();
	updatePoints();
}

void Game::render()
{
	window->clear();

	renderBackground();
	player.render(window);

	for (auto* e : enemies)
	{
		e->render(window);
	}
	for (auto* e : enemies2)
	{
		e->render(window);
	}
	renderPoints();
	if (!playerVivo)
		window->draw(gameOver);

	window->display();
}

void Game::pollEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.Event::type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (e.Event::key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}
void Game::renderBackground()
{
	window->draw(sprite);
}
void Game::updateLimits()
{
	if (player.getBounds().top  <= 0)
	{
		player.setPos(0);
	}
}
void Game::updateCollision()
{
	int playerWidth = player.getBounds().width;
	for (int i = 0;i < enemies.size(); i++)
	{
		if (enemies[i]->getBounds().left == 10 + playerWidth * 2 - enemies[i]->getBounds().width - 20 &&
			player.getBounds().top <= enemies[i]->getBounds().height - player.getBounds().height / 2)
		{
			std::cout << "Collision with enemies 1\n";
			playerVivo = false;
		}
		if (enemies2[i]->getBounds().left == 10 + playerWidth * 2 - enemies[i]->getBounds().width - 20 &&
			player.getBounds().top >= 600 - enemies2[i]->getBounds().height + player.getBounds().height / 2)
		{
			std::cout << "Collision with enemies 2\n";
			playerVivo = false;
		}
	}
}
void Game::updateEnemies()
{

	spawnTimer += 5;
	if (spawnTimer >= spawnTimerMax)
	{
		enemies.push_back(new Enemy(810,0, static_cast<float>(rand() % 4 + 10)));
		std::cout << (rand() % 8 + 1)/10 << "\n";
		enemies2.push_back(new Enemy(810, 400, static_cast<float>((rand() % 3) + 10 )));
		spawnTimer = 0.f;
	}

	unsigned counter = 0;
	for (auto* enemy : enemies)
	{
		enemy->update();

		if (enemy->getBounds().top > window->getSize().y)
		{
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);

		}
		else if (enemy->getBounds().intersects(player.getBounds()))
		{
			//std::cout << "contato\n";
		}
		std::cout << enemy->getBounds().width << "\n";
		++counter;
	}
	for (auto* enemy : enemies2)
	{
		enemy->update();
		if (enemy->getBounds().top > window->getSize().y)
		{
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);

		}
		else if (enemy->getBounds().intersects(player.getBounds()))
		{

		}

		++counter;
	}
}
