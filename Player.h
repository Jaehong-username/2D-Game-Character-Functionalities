#pragma once

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, ATTACK, DEAD };
enum ATTACK_STATES {NOT_ATTACK = 6, FIRSTATTACK, SECONDATTACK};

class Player
{
public:

	Player();

	~Player();

	//Accessor
	const bool& getAnimSwitch(); //needed so that initially the three character not shown up!
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	sf::Sprite& getSprite();
	sf::Vector2f getVelocity();


	void updateAnimation();
	void updateAttack();
	void updateMovement();

	void update();

	void render(sf::RenderTarget& target);

private:


	sf::Texture texture;
	sf::Sprite sprite;

	sf::IntRect currentFrame;
	sf::IntRect currentAttackFrame;
	sf::Clock animationTimer;
	short animState;
	short attackState;
	bool animationSwitch;

	//bool canAttack;

	bool canJump;
	sf::Vector2f velocity;

	void initAnimation();
	void initVariables();

	void initTexture();
	void initSprite();

	void initTextureIdle();
	void initTextureMove();
	void initTextureJump();
	void initTextureFall();
	void initTextureFirstAttack();
	void initTextureSecondAttack();
	void updateSprite();

};

