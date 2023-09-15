#include "Player.h"

Player::Player()
{
	initSprite();
	initVariables();
}

Player::~Player()
{
}

void Player::initVariables()
{
	jumpCooldownMax = 100;
	jumpCooldown = jumpCooldownMax;
}

void Player::initSprite()
{
	texture.loadFromFile("Files/planeDown.png");
	shape.setTexture(texture);
	shape.setPosition(10.f, 10.f);
	shape.setScale(0.3f, 0.3f);
}

void Player::updateJump()
{
	if (jumpCooldown < jumpCooldownMax)
	{
		jumpCooldown += 5;
	}
}

bool Player::canJump()
{
	if (jumpCooldown >= jumpCooldownMax)
	{
		jumpCooldown = 0;
		return true;
	}
	return false;
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump())
	{
		texture.loadFromFile("Files/planeUp.png");
		shape.setTexture(texture);
		std::cout << "Jump\n";
		posY = shape.getPosition().y;
		shape.move(0.f, -50.f);
	}
}

void Player::update()
{
	
	updateJump();
	updateInput();
	if (shape.getPosition().y >= posY)
	{
		texture.loadFromFile("Files/planeDown.png");
		shape.setTexture(texture);
	}
	shape.move(0.f, 1.2f);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(shape);
}

const sf::FloatRect Player::getBounds() const
{
	return shape.getGlobalBounds();
}
