#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "SwagBall.h"
#include <vector>

class Game
{
private:
	
	Player player;

	std::vector<SwagBall> swagBalls;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	sf::Font font;
	sf::Text text;
	sf::Text hpText;
	sf::Text endGameText;

	bool endGame; 
	sf::Event sfmlEvent;
	
	void initVariables();
	void initWindow();
	void initFont();
	void initText();

	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

public:
	
	///Constructors and Destructors
	Game();
	~Game();

	///Accessories
	const bool& getEndGame() const;

	///Modifiers

	///Functions

	const bool running() const;

	void pollEvents();

	
	void spawnSwagBalls(float delta);
	void updatePlayer(float delta);
	void updateCollision();
	void update(float delta);
	void updateGUI();

	void renderGUI(sf::RenderTarget* target);
	void render();

};

