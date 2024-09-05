#include "Character.h"

void Character::initVar()
{
	this->movementSpeed = 10.f;
	this->hpmax = 10;
	this->hp = this->hpmax;
}

void Character::initShape()
{
	this->shape.setFillColor(sf::Color::Cyan);
	this->shape.setSize(sf::Vector2f(20.f, 20.f));
	this->shape.setPosition(300, 300);
}

void Character::update( sf::RenderTarget * target)
{

	this->updateInput();
	this->updateWindowBounceCollision(target);
}

void Character::render(sf::RenderTarget* target)
{	//checking for collisions
	target->draw(this->shape);
}

void Character::updateWindowBounceCollision(sf::RenderTarget* target)
{
		if (this->shape.getGlobalBounds().left <= 0.f)
		{
			this->shape.setPosition(0.f, this->shape.getPosition().y);

		}
		if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		{
			this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
		}
		if (this->shape.getGlobalBounds().top <= 0.f)
		{
			this->shape.setPosition(this->shape.getPosition().x,0);
		}
		if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		{
			this->shape.setPosition(this->shape.getPosition().x,target->getSize().y - this->shape.getGlobalBounds().height);
		}
}

void Character::updateInput()
{
	

//keyboard input 
	//left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0,-this->movementSpeed);
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0,this->movementSpeed);
	}
}

const sf::RectangleShape Character::getshape() const
{

	return this->shape;
}

const int& Character::gethp() const
{
	return this->hp;
}

const int& Character::gethpmax() const
{
	return this->hpmax;
}

void Character::TakeDamage(const int damage)
{
	if (this->hp > 0)
	{
		this->hp -= damage;
	}
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Character::Heal(const int health)
{
	if (this->hp < this->hpmax)
	{
		this->hp += health;
	}
	if (this->hp > this->hpmax)
	{
		this->hp = this->hpmax;
	}
}



Character::Character(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVar();
	this->initShape();
}

Character::~Character()
{
	
}
