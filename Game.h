#pragma once

#include "Player.h"

#include "Collision.h"

#include "FlyingEye.h"

#include "Mushroom.h"

class Game
{
public:

	Game(); //put a bunch of init functions in here!
	~Game();

	void run();

	void updatePollEvents();

	void updateInput();
	void update();




	void render();

private:
	Collision collision;

	sf::RenderWindow* window;
	
	Player* player;

	FlyingEye* flyingEye;

	Mushroom* mushroom;

	void initWindow();
	void initPlayer();
	void initFlyingEye();
	void initMushroom();
};

