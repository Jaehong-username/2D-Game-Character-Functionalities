#include "stdafx.h"
#include "Collision.h"



void Collision::checkMapBounds(Player& player, sf::RenderTarget& target)
{
	//Check left collision
	if (player.getGlobalBounds().left < 0.f)
	{
		//player.getSprite().move(0.f, player.getVelocity().y); //stil retaining y velocity has to be the set position
		player.getSprite().setPosition(0.f, player.getGlobalBounds().top); //becuase we gonna keep the y coordinate!!.
	}

	//Check right collision
	else if (player.getGlobalBounds().left + player.getGlobalBounds().width > target.getSize().x)
	{
		player.getSprite().setPosition(target.getSize().x - player.getGlobalBounds().width, player.getGlobalBounds().top);
	}

	//Check top collision
	if (player.getGlobalBounds().top < 0.f)
	{
		//player.getSprite().move(player.getVelocity().y, 0.f);
		player.getSprite().setPosition(player.getGlobalBounds().left, 0.f);//.left makes you retain the x position
	}

	//check bottom collision
	else if (player.getGlobalBounds().top + player.getGlobalBounds().height >= target.getSize().y)
	{
		//player.getSprite().move(player.getGlobalBounds().top - player.getGlobalBounds().height, 0.f);
		player.getSprite().setPosition(player.getGlobalBounds().left, target.getSize().y - player.getGlobalBounds().height);
	}


}

void Collision::checkMapBounds(Enemy& enemy, sf::RenderTarget& target)
{
	
	if (enemy.getGlobalBounds().left < 0.f)
	{
		enemy.getSprite().setPosition(0.f, enemy.getGlobalBounds().top); //becuase we gonna keep the y coordinate!!.
		enemy.getSprite().move(0.f, 0.f);
		//enemy.setAnimState(10);
	}

	//Check right collision
	else if (enemy.getGlobalBounds().left + enemy.getGlobalBounds().width > target.getSize().x)
	{
		enemy.getSprite().setPosition(target.getSize().x - enemy.getGlobalBounds().width, enemy.getGlobalBounds().top);
		enemy.getSprite().move(0.f, 0.f);
		//enemy.setAnimState(5);
	}

	//Check top collision
	if (enemy.getGlobalBounds().top < 0.f)
	{
		//player.getSprite().move(player.getVelocity().y, 0.f);
		//enemy.getSprite().setPosition(enemy.getGlobalBounds().left, 0.f);//.left makes you retain the x position
		enemy.getSprite().move(0.f, 0.f);
		enemy.setUpAndDown(2);
	}

	//check bottom collision
	else if (enemy.getGlobalBounds().top + enemy.getGlobalBounds().height >= target.getSize().y)
	{
		//player.getSprite().move(player.getGlobalBounds().top - player.getGlobalBounds().height, 0.f);
		//enemy.getSprite().setPosition(enemy.getGlobalBounds().left, target.getSize().y - enemy.getGlobalBounds().height);
		enemy.getSprite().move(0.f, 0.f);
		enemy.setAnimState(1);
	}
}
