#include "Game.h"
void Game::initWindow()
{
	int x = 800;
	int y = 600;



	this->vidmode = sf::VideoMode(x, y);
	this->window = new sf::RenderWindow(this->vidmode, "Swagging my balls", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initVar()
{
	this->endGame = false;
	this->spawnTimerMax = 100.0f;
	this->SpawnTimer = this->spawnTimerMax;
	this->MaxBalls = 10;
	this->points = 0;
	
}


//const and destruct
Game::Game()
{
	this->initVar();
	this->initWindow();

}

Game::~Game()
{
	delete this->window;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

void Game::spawnSwagBalls()
{
	if (this->SpawnTimer < this->spawnTimerMax)
	{
		this->SpawnTimer += 50.f;

	}
	else
	{
		if (this->swagmyballs.size() < this->MaxBalls)
		{
			this->swagmyballs.push_back(SwagMyBalls(*this->window, this->randomizeType()));
			this->SpawnTimer = 0.f;
		}
		

	}
}

const int Game::randomizeType() const
{
	int type = SwagBallTypes::DEFAULT;
	int randomNb = rand()%100 + 1;
	if (randomNb >= 60 && randomNb < 80)
	{
		type = SwagBallTypes::DAMAGING;
	}
	else if (randomNb >= 80 && randomNb <= 100)
	{
		type = SwagBallTypes::HEALING;
	}
	else
	{
		type = SwagBallTypes::DEFAULT;
	}
	return type;
}



void Game::updateCollisions()
{
	for (size_t i = 0; i < this->swagmyballs.size(); i++)
	{
		if (this->player.getshape().getGlobalBounds().intersects(this->swagmyballs[i].getshape().getGlobalBounds())) 
		{

			switch (this->swagmyballs[i].getType())
			{
			case SwagBallTypes::DEFAULT:
				points++;
				break;
			case SwagBallTypes::DAMAGING:
				this->player.TakeDamage(1SSS);
				break;
			case SwagBallTypes::HEALING:
				this->player.Heal(1);
				break;
			}
			if (this->player.gethp() == 0)
			{
				this->endGame = true;
			}

			
			
			this->swagmyballs.erase(this->swagmyballs.begin() + i);
			
			std::cout << "your current points count is : " << points << '\n';
			std::cout << "your hp is : " << player.gethp() << "/" << player.gethpmax() << '\n';
		}
	}
}

void Game::update()
{
	this->pollEvent();
	this->spawnSwagBalls();
	this->player.update(this->window);
	this->updateCollisions();

}

void Game::render()
{
	this->window->clear();

	this->player.render(this->window);
	for(auto i: this->swagmyballs)
	{
		i.render(this->window);
	}

	this->window->display();

}

bool const Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->eve))
	{
		switch (this->eve.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				switch (this->eve.key.code)
				{
				case sf::Keyboard::Escape:
					this->window->close();
					break;
				}
			
		}
	}
}
