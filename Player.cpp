#include "Player.h"
#include <iostream>
void Player::initVariables()
{
	
	this->hpMax = 10;
	this->hp = hpMax;
	this->points = 0;

	this->movementSpeed = 400.f;
}

void Player::initShape()
{

	shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setOutlineThickness(-2.f);
	shape.setOutlineColor(sf::Color::White);

}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initShape();
	this->initVariables();

}

Player::~Player()
{
}

void Player::addPoints(int point)
{
	this->points += point;
}

const int Player::getPoints() const
{
	return this->points;
}

void Player::setHP(int value)
{
	this->hp += value;
	if (this->hp > this->hpMax) {
		this->hp = this->hpMax;
	}
}

const int Player::getHP() const
{
	return this->hp;
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

void Player::update(float delta, sf::RenderTarget * target)
{
	///Keyboard Input
	this->updateInput(delta);
	///Window Bounds Collision
	this->updateWindowBoundsCollision(target);

}

void Player::updateInput(float delta)
{
	///For A AND S
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(-this->movementSpeed * delta, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(this->movementSpeed * delta, 0.f);
	}

	///For W AND D
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed * delta);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed * delta);
	}

}

void Player::render(sf::RenderTarget* Target)
{
	Target->draw(shape);
}

void Player::updateWindowBoundsCollision(sf::RenderTarget* target)
{
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();


	//Left
	if (playerBounds.left <= 0.f) {
		this->shape.setPosition(0.f, playerBounds.top);
	}

	//RIGHT
	else if (playerBounds.left + playerBounds.width >= target->getSize().x) {
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	}
	
	//TOP
	else if (playerBounds.top <= 0.f) {
		this->shape.setPosition(playerBounds.left, 0.f);
	}

	//BOTTOM
	else if (playerBounds.top + playerBounds.height >= target->getSize().y) {
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
	}
	
	//TOP LEFT
	if (playerBounds.left <= 0.f && playerBounds.top <= 0.f) {
		this->shape.setPosition(0.f, 0.f);
	}
	//TOP RIGHT
	else if (playerBounds.left + playerBounds.width >= target->getSize().x && playerBounds.top <= 0.f) {
		this->shape.setPosition(target->getSize().x - playerBounds.width, 0.f);
	}

	//BOTTOM LEFT
	else if (playerBounds.left <= 0.f && playerBounds.top + playerBounds.height >= target->getSize().y) {
		this->shape.setPosition(0.f, target->getSize().y - playerBounds.height);
	}

	//BOTTOM RIGHT
	else if (playerBounds.left + playerBounds.width >= target->getSize().x && playerBounds.top + playerBounds.height >= target->getSize().y) {
		this->shape.setPosition(target->getSize().x - playerBounds.width, target->getSize().y - playerBounds.height);
	}
}
