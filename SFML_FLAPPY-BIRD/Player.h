#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Player
{
private:
	sf::Texture texture;
	sf::Sprite shape;

	int jumpCooldown;
	int jumpCooldownMax;
	int posYjump;
	int posY;


	void initVariables();
	void initSprite();
public:
	Player();
	virtual ~Player();

	
	void updateJump();
	bool canJump();
	void updateInput();
	void update();
	void render(sf::RenderTarget* target);
	const sf::FloatRect getBounds() const;
};

