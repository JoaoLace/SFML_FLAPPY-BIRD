#pragma once
#include "Player.h"
class Enemy
{
	sf::Texture texture;
	sf::Sprite sprite;

	void initSprite();
	void initVariables();
public:
	Enemy(int pos_x, int pos_y);
	virtual ~Enemy();

	const int width() const;
	const sf::FloatRect getBounds() const;
	void update();
	void render(sf::RenderTarget* target);
};

