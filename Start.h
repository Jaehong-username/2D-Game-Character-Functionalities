#pragma once

class Start
{
public:
	Start();
	~Start();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::CircleShape choice1;

	sf::CircleShape choice2;
};

