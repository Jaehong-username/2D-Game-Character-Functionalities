#pragma once

#include "Enemy.h"

class Mushroom : public Enemy
{
public:
	Mushroom();
	virtual ~Mushroom() override;

	virtual void updateAnimation() override;

private:

	virtual void initTexture() override;
};

