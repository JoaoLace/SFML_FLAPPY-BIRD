#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <time.h>
class Game
{
private:
	Player player;
	Enemy* control;
	std::vector<Enemy*> enemies;
	std::vector<Enemy*> enemies2;
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text text;
	sf::Text gameOver;
	void initFont();

	int Points;
	void updatePoints();
	void renderPoints();

	int	spawnTimer;
	int spawnTimerMax;
	int sizeOfEnemy;

	bool playerVivo;

	// background
	sf::Texture texture;
	sf::Sprite sprite;

	void initBackground();
	void initWindow();
	void initVariables();
	void initPlayer();
	void initEnemies();
public:
	Game();
	virtual ~Game();
	void updateEnemies();
	void run();
	void update();
	void render();
	void pollEvents();
	void renderBackground();
	void updateLimits();
	void updateCollision();
};

