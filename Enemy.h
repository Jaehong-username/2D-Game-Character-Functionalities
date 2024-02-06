#pragma once

#include "Player.h"

//All the puire virtual functions must be defined in the inhereited class otherwise
//even if call a derived class, still get an error saying: cannot instantiate an abstract class!

enum ENEMY_ANIMATION_STATES { STILL = 0, LEFT = 5, RIGHT = 10 };

enum ENEMY_UP_DOWN { NOT_MOVING = 0, UP = 1, DOWN = 2 };

class Enemy
{
public:
	Enemy();
	virtual ~Enemy() = 0;

	virtual void updateAnimation();
	virtual void updateAttack(Player& player);
	virtual void updateMovement();
	virtual void update(Player& player);
	virtual void render(sf::RenderTarget& target);

	void updateDirCoolTime();
	bool canChangeDir();

	//Accessors
	const bool& getAnimSwitch(); //needed so that initially the three character not shown up!
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	sf::Sprite& getSprite();
	int getAnimState();
	int getUpAndDown();

	//Modifier
	void setAnimState(int newAnimState);
	void setUpAndDown(int newUpAndDown);
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::IntRect currentFrame;
	sf::IntRect currentAttackFrame;
	sf::Clock animationTimer;
	short animState;
	short attackState;
	bool animationSwitch;

	short updown;

	float dirCoolTimeMax;
	float dirCoolTime;

	int chooseDir;
	float velocityX;
	float velocityY;

	virtual void initTexture() = 0;
	virtual void initSprite();
	virtual void initVariables();
};

