#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Enemy::~Enemy()
{
}

void Enemy::updateAnimation()
{
	//Pure virtual function this must be overridden
}

void Enemy::updateAttack(Player& player)
{
	//Pure virtual function this must be overridden
}

void Enemy::updateMovement()
{
	
	this->animState = ENEMY_ANIMATION_STATES::STILL;
	
	if (canChangeDir())
	{
		chooseDir = rand() % 15;
	}
	
	if (5 < chooseDir && chooseDir <= 10)
	{
		this->sprite.move(-velocityX, 0.f);
		this->animState = ENEMY_ANIMATION_STATES::LEFT;
	}

	else if (10 < chooseDir && chooseDir <= 15) //Right 
	{
		this->sprite.move(velocityX, 0.f);
		this->animState = ENEMY_ANIMATION_STATES::RIGHT;
	}

	else if (0 <= chooseDir && chooseDir <= 15) //Stand still
	{
		this->sprite.move(0.f, 0.f);
		this->animState = ENEMY_ANIMATION_STATES::STILL;
	}
	
}

void Enemy::update(Player& player)
{
	this->updateAnimation();
	this->updateMovement();
	this->updateDirCoolTime();
	this->updateAttack(player);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Enemy::updateDirCoolTime()
{
	if (this->dirCoolTime < this->dirCoolTimeMax) dirCoolTime += 0.1f;
	
}

bool Enemy::canChangeDir()
{
	if (this->dirCoolTime >= this->dirCoolTimeMax)
	{
		this->dirCoolTime = 0.f;
		return true;
	}

	return false;
}

const bool& Enemy::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch) //if swithc is tree
		this->animationSwitch = false;

	return anim_switch;
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Enemy::getPosition()
{
	return this->sprite.getPosition();
}

sf::Sprite& Enemy::getSprite()
{
	return this->sprite;
}

int Enemy::getAnimState()
{
	return animState;
}

int Enemy::getUpAndDown()
{
	return this->updown;
}

void Enemy::setAnimState(int newAnimState)
{
	this->animState = newAnimState;
}

void Enemy::setUpAndDown(int newUpAndDown)
{
	this->updown = newUpAndDown;
}

void Enemy::initTexture()
{
	//Pure virtual function this must be overridden
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 40, 178, 130);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.f, 2.f);
}

void Enemy::initVariables()
{
	this->animState = ENEMY_ANIMATION_STATES::STILL;
	this->updown = ENEMY_UP_DOWN::NOT_MOVING;
	this->dirCoolTimeMax = 50;
	this->dirCoolTime = this->dirCoolTimeMax;
	this->chooseDir = rand() % 15;
	this->velocityX = 5.f;
	this->velocityY = 5.f;
}



