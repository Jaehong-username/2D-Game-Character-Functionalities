#pragma once

#include "Player.h"
#include "Enemy.h"
class Collision
{
public:
	
	void checkMapBounds(Player& player, sf::RenderTarget& target);
	
	void checkMapBounds(Enemy& enemy, sf::RenderTarget& target);

private:

};

