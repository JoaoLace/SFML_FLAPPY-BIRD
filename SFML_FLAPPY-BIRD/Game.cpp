#include "Game.h"

Game::Game()
{
	initWindow();
	initVariables();
	
}

Game::~Game()
{
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Flappy Bird", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(144);
	window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
	spawnTimerMax = 2000;
	spawnTimer = spawnTimerMax;
}

void Game::initEnemies()
{
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}

void Game::update()
{
	pollEvents();
	updateEnemies();
	player.update();
}

void Game::render()
{
	window->clear();

	player.render(window);

	for (auto* e : enemies)
	{
		e->render(window);
	}
	for (auto* e : enemies2)
	{
		e->render(window);
	}
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
void Game::updateEnemies()
{

	spawnTimer += 5;
	if (spawnTimer >= spawnTimerMax)
	{
		enemies.push_back(new Enemy(810,0));
		enemies2.push_back(new Enemy(810, 400));
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
