#pragma once

#include "Enemy.h"




class FlyingEye : public Enemy
{
public:
	FlyingEye();
	virtual ~FlyingEye() override;

	virtual void updateAnimation() override;


private:

	virtual void initTexture() override;
};

