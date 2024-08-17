#include "Game.h"


void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;	
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Window", sf::Style::Close | sf::Style::Titlebar);
	//this->window->setFramerateLimit(60);

}

void Game::initFont()
{
	this->font.loadFromFile("Font/Roboto-Regular.ttf");
}

void Game::initText()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(0.f, 0.f);
	this->text.setOutlineColor(sf::Color::Blue);
	this->text.setString("0");

	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(30);
	this->hpText.setFillColor(sf::Color::White);
	this->hpText.setPosition(this->window->getSize().x - this->hpText.getGlobalBounds().width, 0.f);
	this->hpText.setOutlineColor(sf::Color::Blue);
	this->hpText.setString("0");

	this->endGameText.setFont(this->font);
	this->endGameText.setCharacterSize(50);
	this->endGameText.setFillColor(sf::Color::Black);
	this->endGameText.setStyle(sf::Text::Style::Bold);
	this->endGameText.setOutlineColor(sf::Color::White);
	this->endGameText.setOutlineThickness(2.f);
	this->endGameText.setString("Game Ended, Use ESC to Close\nScore: " + std::to_string(this->player.getPoints()));
	this->endGameText.setPosition((this->window->getSize().x - this->endGameText.getGlobalBounds().width) / 2, 100.f);


}


Game::Game()
{
	initVariables();
	initWindow();
	initFont();
	initText();
}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	// TODO: insert return statement here
	return this->endGame;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		
		switch (this->sfmlEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}

	}
}

void Game::spawnSwagBalls(float delta)
{
	///Timer
	if (this->spawnTimer < this->spawnTimerMax) {
		this->spawnTimer += (60.f * delta);
	}
	else {
	
		if (this->swagBalls.size() < this->maxSwagBalls) {
			this->swagBalls.push_back(SwagBall(window));
			this->spawnTimer = 0.f;

		}
	}
}

void Game::updatePlayer(float delta)
{
	this->player.update(delta, this->window);

	if (this->player.getHP() <= 0) {
		this->endGame = true;
	}
}

void Game::updateCollision()
{
	//Check the Collision
	for (size_t i = 0; i < this->swagBalls.size(); i++) {

	
		if (this->player.getShape().getGlobalBounds().intersects(swagBalls[i].getShape().getGlobalBounds())) {
			
			if (swagBalls[i].getType() == 1) {
				//DMG
				this->player.setHP(-10);
			}
			else if (swagBalls[i].getType() == 2) {
				//HEAL
				this->player.setHP(1);
				
			}
			
			
			this->swagBalls.erase(this->swagBalls.begin() + i);
			this->player.addPoints(1);

			

		}
	}

}

void Game::update(float delta)
{


	this->pollEvents();

	if (!this->getEndGame()) {


	this->spawnSwagBalls(delta);


	this->updatePlayer(delta);
	this->updateCollision();
	this->updateGUI();

	}
}

void Game::updateGUI()
{
	this->hpText.setPosition(this->window->getSize().x - (this->hpText.getGlobalBounds().width + 5), 0.f);
	this->hpText.setString("Health: " + std::to_string(this->player.getHP()));
	this->text.setString("Points: " + std::to_string(this->player.getPoints()));
}

void Game::renderGUI(sf::RenderTarget* target)
{
	target->draw(this->text);
	target->draw(this->hpText);
	
	if (this->getEndGame()) {
		this->window->draw(this->endGameText);
	}

}

void Game::render()
{
	this->window->clear();

	///Render Stuff
	this->player.render(window);

	for (SwagBall i : this->swagBalls) {
		i.render(this->window);
	}

	this->renderGUI(window);

	///Display 
	this->window->display();
	
}


