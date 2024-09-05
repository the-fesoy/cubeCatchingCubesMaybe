#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum SwagBallTypes { DEFAULT = 0, DAMAGING , HEALING , NBOFTYPES };
class SwagMyBalls
{
private:
	sf::CircleShape shape;



	int type;
	int EnemySpeed;
	void initShape(sf::RenderWindow& window);



public:

	const sf::CircleShape getshape() const;
	const int& getType() const;
	void update();
	void render(sf::RenderTarget * target);
	SwagMyBalls(sf::RenderWindow& window, int type);
	~SwagMyBalls();
};

