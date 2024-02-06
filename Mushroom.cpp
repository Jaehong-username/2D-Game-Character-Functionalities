#include "stdafx.h"
#include "Mushroom.h"

Mushroom::Mushroom() : Enemy()
{
	this->initTexture();
	this->sprite.setPosition(200.f, 200.f);
	this->dirCoolTimeMax = 30.f;
}

Mushroom::~Mushroom() //override the pure virtual destructor from Enemy base class
{
	std::cout << "A Destructor for Mushroom class invoked" << std::endl;
}

void Mushroom::updateAnimation()
{
	if (this->animState == ENEMY_ANIMATION_STATES::STILL || this->animState == ENEMY_ANIMATION_STATES::RIGHT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 1650.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(2.f, 2.f);
		this->sprite.setOrigin(0.f, 0.f);
	}


	else if (this->animState == ENEMY_ANIMATION_STATES::LEFT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 1650.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-2.f, 2.f); //only flipping the x sign
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
	}
}



void Mushroom::initTexture()
{
	if (!this->texture.loadFromFile("Mushroom.png"))
	{
		std::cout << "Mushroom class initTexture() error: Mushroom.png is not loaded correctly!" << std::endl;
	}
}
