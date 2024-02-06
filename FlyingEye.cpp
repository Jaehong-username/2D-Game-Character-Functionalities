#include "stdafx.h"
#include "FlyingEye.h"


FlyingEye::FlyingEye() : Enemy()
{
	this->initTexture(); //I need to call this overriden function!!! otherwise it will not replace it!!
	
	
}

FlyingEye::~FlyingEye()
{
	std::cout << "A Destructor for FlyingEye class invoked" << std::endl;
}

void FlyingEye::updateAnimation()
{
	if (this->animState == ENEMY_ANIMATION_STATES::STILL || this->animState == ENEMY_ANIMATION_STATES::RIGHT)
	{

		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 900.f) //if not included = equal sign animated scene will disappear.
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
			if (this->currentFrame.left >= 900.f) //if not included = equal sign animated scene will disappear.
				this->currentFrame.left = 0;


			this->animationTimer.restart(); //so that each aninatedscene happens every 0.5f seconds
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-2.f, 2.f); //only flipping the x sign
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
	}
}




void FlyingEye::initTexture()
{
	if (!this->texture.loadFromFile("FlyingEye.png"))
	{
		std::cout << "FlyingEye class initTexture() error: FlyingEye.png is not loaded correctly!" << std::endl;
	}
}
