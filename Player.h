#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Player
{

private:
	sf::RectangleShape shape;
	
	float movementSpeed;
	
	int hp;
	int hpMax;
	int points;
	
	
	
	void initVariables();
	void initShape();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();


	void update(float delta, sf::RenderTarget* target);
	void updateInput(float delta);
	void render(sf::RenderTarget* Target);
	void updateWindowBoundsCollision(sf::RenderTarget* target);



	//Setters and Getters

	void addPoints(int point);
	const int getPoints() const;
	
	void setHP(int value);
	const int getHP() const;

	const sf::RectangleShape& getShape() const;
};

