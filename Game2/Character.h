#pragma once
#include "SwagMyBalls.h"
class Character
{
private:
	sf::RectangleShape shape;
	//private functions
	void initVar();
	void initShape();
	//private members
	float movementSpeed;
	int hp;
	int hpmax;

public:
	//functions
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
	void updateWindowBounceCollision(sf::RenderTarget* target);
	void updateInput();
	void TakeDamage(const int damage);
	void Heal(const int health);
	const sf::RectangleShape getshape() const;

	//accessors
	const int& gethp() const;
	const int& gethpmax() const;


	


	//constructor AND destructor
	Character(float x = 0.f, float y = 0.f);
	~Character();

};

