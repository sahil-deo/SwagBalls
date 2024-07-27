#include "SwagBall.h"
#include <iostream>
void SwagBall::initShape(sf::RenderWindow* window)
{

	this->shape.setRadius(static_cast<float>(rand()%10+10));

	sf::Color color;
	switch (type) {
		case 0:
			color = sf::Color::White;
;			break;
		case 2:
			color = sf::Color::Green;
			break;
		case 1:
			color = sf::Color::Red;
			break;
		
	}

	
	
	
	this->shape.setFillColor(color);
	
	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window->getSize().x - this->shape.getGlobalBounds().width),
			static_cast<float>(rand() % window->getSize().y - this->shape.getGlobalBounds().height)
		)
	);

	this->shape.setOutlineThickness(-2.f);
	this->shape.setOutlineColor(sf::Color(1 - color.r, 1-color.g, 1-color.b, color.a));
}
SwagBall::SwagBall(sf::RenderWindow* window)
{
	this->type = this->randomizeSwagBalls();
	this->initShape(window);
}

SwagBall::~SwagBall()
{
}

const sf::CircleShape SwagBall::getShape() const
{
	return this->shape;
}

void SwagBall::update(float delta)
{
}

void SwagBall::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

int SwagBall::randomizeSwagBalls()
{
	int randValue = rand() % 100 + 1;
	if (randValue <= 20) {
		return 1;
	}
	else if (randValue <= 30) {
		return 2;
	}
	else if (randValue <= 100) {
		return 0;
	}
	else {
		return 0;
	}
}


const int SwagBall::getType() const
{
	return this->type;
}
