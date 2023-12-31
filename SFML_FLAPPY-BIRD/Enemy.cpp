#include "Enemy.h"

void Enemy::initSprite()
{
	texture.loadFromFile("Files/predio.png");
	sprite.setTexture(texture);
}

void Enemy::initVariables()
{
}

Enemy::Enemy(int pos_x, int pos_y,float scale)
{
	sprite.setPosition(pos_x, pos_y);
	sprite.setScale(1, scale/10);
	initSprite();
	initVariables();
}

Enemy::~Enemy()
{
}


const sf::FloatRect Enemy::getBounds() const
{
	return sprite.getGlobalBounds();
}

void Enemy::update()
{
	sprite.move(-1.f, 0.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
