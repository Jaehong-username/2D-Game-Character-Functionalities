#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
}

Player::~Player()
{

}



void Player::updateAnimation()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		this->initTextureIdle();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f || this->getAnimSwitch())
		{
			this->currentFrame.left += 250.f;
			if (this->currentFrame.left >= 2000.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}
	}

	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		this->initTextureMove();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{

			this->currentFrame.left += 250.f;
			if (this->currentFrame.left >= 2000.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(2.f, 2.f);
		this->sprite.setOrigin(0.f, 0.f);
	}

	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		this->initTextureMove();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.left += 250.f;
			if (this->currentFrame.left >= 2000.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-2.f, 2.f); //only flipping the x sign
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
	}

	else if (this->animState == PLAYER_ANIMATION_STATES::JUMPING)
	{
		this->initTextureJump();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.left += 250.f;
			if (this->currentFrame.left >= 500.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

	}

	else if (this->animState == PLAYER_ANIMATION_STATES::FALLING)
	{
		this->initTextureFall();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.left += 250.f;
			if (this->currentFrame.left >= 500.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

	}


	if (this->attackState == ATTACK_STATES::FIRSTATTACK /*&& !canAttack*/)
	{
		this->initTextureFirstAttack();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			
			this->currentAttackFrame.left += 250.f;
			if (this->currentAttackFrame.left >= 2000.f) //if not included = equal sign animated scene will disappear.
			{
				this->currentAttackFrame.left = 0;
				//this->canAttack = true;
				this->attackState = ATTACK_STATES::NOT_ATTACK;
			}
				


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentAttackFrame);
		}
	}

	else if (this->attackState == ATTACK_STATES::SECONDATTACK /*&& !canAttack*/)
	{
		this->initTextureSecondAttack();
		this->updateSprite();

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			
			this->currentAttackFrame.left += 250.f;
			if (this->currentAttackFrame.left >= 2000.f) //if not included = equal sign animated scene will disappear.
			{
				this->currentAttackFrame.left = 0;
				//this->canAttack = true;
				this->attackState = ATTACK_STATES::NOT_ATTACK;
			}
				


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentAttackFrame);
		}
	}
}

void Player::updateAttack()
{
	//this->animState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) /*&& this->canAttack*/ && this->attackState == ATTACK_STATES::NOT_ATTACK
		&& this->animState == PLAYER_ANIMATION_STATES::IDLE) //First attack
	{
		//this->animState = PLAYER_ANIMATION_STATES::FIRSTATTACK;
		this->attackState = ATTACK_STATES::FIRSTATTACK;
		//this->canAttack = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L) /*&& this->canAttack*/ && this->attackState == ATTACK_STATES::NOT_ATTACK
		&& this->animState == PLAYER_ANIMATION_STATES::IDLE) //Second attack 
	{
		//this->animState = PLAYER_ANIMATION_STATES::SECONDATTACK;
		this->attackState = ATTACK_STATES::SECONDATTACK;
		//this->canAttack = false;
	}
}

void Player::updateMovement()
{
	
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left 
	{
		this->sprite.move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right 
	{
		this->sprite.move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump)
	{
		this->velocity.y = -70.f;
		this->sprite.move(0.f, -1.f);

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->sprite.move(0.f, 1.f);
			this->animationTimer.restart();
		}

		this->canJump = true;
		this->animState = PLAYER_ANIMATION_STATES::JUMPING;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->sprite.move(0.f, 1.f);
		this->animState = PLAYER_ANIMATION_STATES::FALLING;
	}

	
}


void Player::update()
{
	
	this->updateAnimation();
	this->updateMovement();
	this->updateAttack();
	
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch) //if swithc is tree
		this->animationSwitch = false;

	return anim_switch;
}

void Player::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true; //so first animationcan start directly
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->animState = 0;
	this->canJump = true;
	this->currentAttackFrame = sf::IntRect(0, 40, 250, 130);
	//this->canAttack = true;
	this->attackState = ATTACK_STATES::NOT_ATTACK;
}

sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}

sf::Sprite& Player::getSprite()
{
	return this->sprite;
}

sf::Vector2f Player::getVelocity()
{
	return velocity;
}





void Player::initTexture()
{
	if (!this->texture.loadFromFile("Idle.png"))
	{
		std::cout << "Idle.png not loaded correctly" << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 40, 178, 130);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.f, 2.f);
}


void Player::initTextureIdle()
{
	if (!this->texture.loadFromFile("Idle.png"))
	{
		std::cout << "Idle.png not loaded correctly" << std::endl;
	}
	
}



void Player::initTextureMove()
{
	if (!this->texture.loadFromFile("Move.png"))
	{
		std::cout << "Move.png not loaded correctly" << std::endl;
	}
}



void Player::initTextureJump()
{
	if (!this->texture.loadFromFile("Jump.png"))
	{
		std::cout << "Jump.png not loaded correctly" << std::endl;
	}

}

void Player::initTextureFall()
{
	if (!this->texture.loadFromFile("Fall.png"))
	{
		std::cout << "Fall.png not loaded correctly" << std::endl;
	}
}


void Player::initTextureFirstAttack()
{
	if (!this->texture.loadFromFile("Attack1.png"))
	{
		std::cout << "Attack1.png not loaded correctly" << std::endl;
	}

}

void Player::initTextureSecondAttack()
{
	if (!this->texture.loadFromFile("Attack2.png"))
	{
		std::cout << "Attack2.png not loaded correctly" << std::endl;
	}

}

void Player::updateSprite()
{
	this->sprite.setTexture(this->texture);

}