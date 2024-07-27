#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class SwagBall
{
private:

	enum swagBallTypes { DEF = 0, DMG, HEAL, NROFTYPES };
	int type;

	sf::CircleShape shape;
	
	float speed; ;
	
	void initShape(sf::RenderWindow* window);


public:

	///Constructors and Destructors:
	SwagBall(sf::RenderWindow* window);
	virtual ~SwagBall();
	
	///Functions:
	const sf::CircleShape getShape() const;
	void update(float delta);
	void render(sf::RenderTarget* target);
	int randomizeSwagBalls();
	

	///Accessors:
	const int getType() const;

};

