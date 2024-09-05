#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "Character.h"
#include "SwagMyBalls.h"

class Game
{
private:
	sf::VideoMode vidmode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event eve;


	//functions private
	void initWindow();
	void initVar();





	Character player;
	std::vector<SwagMyBalls> swagmyballs;
	float spawnTimerMax;
	float SpawnTimer;
	int MaxBalls;
	int points;



public:
	Game();
	~Game();
	//accaesors
	const bool& getEndGame() const;
	//modifiers

	//functions

	void spawnSwagBalls();
	const int randomizeType() const;
	void updateCollisions();
	void update();
	void render();
	bool const running() const;
	void pollEvent();

};

