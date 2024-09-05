#include "SwagMyBalls.h"

void SwagMyBalls::initShape(sf::RenderWindow& window)
{
	this->shape.setPosition(sf::Vector2f(static_cast<float>(rand()% window.getSize().x - this->shape.getGlobalBounds().width), static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;
	switch (this->type)
	{
	case DEFAULT: 
		color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case DAMAGING:
		color = sf::Color::Red;
		this->shape.setOutlineThickness(5.f);
		this->shape.setOutlineColor(sf::Color(255, 70, 70));
		break;
	case HEALING:
		color = sf::Color::Yellow;
		this->shape.setOutlineThickness(5.f);
		this->shape.setOutlineColor(sf::Color(255, 215 , 0));
		break;
	}
	this->shape.setFillColor(color);
}

const sf::CircleShape SwagMyBalls::getshape() const
{
	return this->shape;
}

const int& SwagMyBalls::getType() const
{
	return this->type;

}

void SwagMyBalls::update()
{
}

void SwagMyBalls::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
SwagMyBalls::SwagMyBalls(sf::RenderWindow& window, int type) : type(type)
{

	this->initShape(window);


}


SwagMyBalls::~SwagMyBalls()
{
	
}
