#include <iostream>
#include <list>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"

#pragma once

class Game
{

private:

	//Game stuff
	Entity* bg;
	Entity* bg2;
	Player* player;

	//Core Engine
	list<Entity*> entitiesList;
	string gameTitle;
	sf::RenderWindow* window;
	bool isRunning;
	sf::Clock clock;
	float deltaTime;
	float frameRate;

	sf::Event event;



public:

	//Core Engine stuff
	Game();
	~Game();

	void Initialize(string gameTitle, float frameRate, int screenW, int screenH);
	void Update();
	void Finish();
	void Draw();
	void QuitGame();

	sf::RenderWindow* GetWindow() { return this->window; }
	bool IsRunning() { return this->isRunning; }

};
