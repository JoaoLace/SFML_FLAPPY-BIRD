#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
class Game
{
private:
	Player player;
	Enemy* control;
	std::vector<Enemy*> enemies;
	std::vector<Enemy*> enemies2;
	sf::RenderWindow* window;

	int	spawnTimer;
	int spawnTimerMax;
	int sizeOfEnemy;

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
};

