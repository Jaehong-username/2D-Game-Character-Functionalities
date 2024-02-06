#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initFlyingEye();
	this->initMushroom();
}

Game::~Game()
{
	delete this->player;
	std::cout << "A detructor for a player invoked!" << std::endl;

	delete this->flyingEye; //once delete is called it will inbvoked the destructor fromn flying eye.
	delete this->mushroom; //once delete is called it will inbvoked the destructor fromn flying eye.

	delete this->window;
	std::cout << "A detructor for a window invoked!" << std::endl;
	
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();

		this->update();

		this->render();
	}
}

void Game::updatePollEvents()
{
	//first check for poll event: computer waiting for inputs like closing
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed) this->window->close();
		//is keypressed and keycode is esc
		if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape) this->window->close();
	}
}

void Game::updateInput()
{
	////Move Player
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	this->player->move(-1.0f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//	this->player->move(1.0f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	this->player->move(0.f, -1.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	this->player->move(0.f, 1.f);
}

void Game::update()
{
	this->player->update();
	this->flyingEye->update(*this->player);
	this->mushroom->update(*this->player);
	this->collision.checkMapBounds(*this->player, *this->window);
	this->collision.checkMapBounds(*(dynamic_cast<FlyingEye*> (flyingEye)), *this->window);
	this->collision.checkMapBounds(*(dynamic_cast<Mushroom*> (mushroom)), *this->window);
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	this->flyingEye->render(*this->window);

	this->mushroom->render(*this->window);

	this->window->display();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 1400), "Adventure Game!");
	this->window->setFramerateLimit(144);
}

void Game::initPlayer()
{
	this->player = new Player(); //dont forget to init the player
}

void Game::initFlyingEye()
{
	this->flyingEye = new FlyingEye();
}

void Game::initMushroom()
{
	this->mushroom = new Mushroom();
}
