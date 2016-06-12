#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
	Finish();
}

void Game::Initialize(string gameTitle, float frameRate, int screenW, int screenH)
{
	//Initialize game stuff
	this->window = new sf::RenderWindow(sf::VideoMode(screenW, screenH), gameTitle);
	this->isRunning = true;
	this->frameRate = 1 / frameRate;
	this->clock.restart();



	//Create entities
	bg = new Entity(window, "Assets/colored_desert.png", entitiesList);
	bg->setPosition(0, 0);

	player = new Player(window, "Assets/player.png", "shader.frag", entitiesList);
	player->SetMaxSpeed(350);
	player->SetAcceleration(400);
	player->setPosition(0, 500);
}

void Game::Update()
{
	//Get the delta time
	deltaTime = clock.restart().asSeconds();

	//Check for events
	while (window->pollEvent(this->event))
	{
		//Check for game exit
		if (this->event.type == sf::Event::Closed)
		{
			QuitGame();
		}

		if (event.type == sf::Event::KeyPressed)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				QuitGame();
			}

		//Check input for all game entiies
		for each (Entity* entity in entitiesList)
		{
			entity->GetInput(this->event, deltaTime);
		}
	}


	//Update all the entities
	for each (Entity* entity in entitiesList)
	{
		entity->Update(deltaTime);
	}

}

void Game::Draw()
{
	window->clear();

	//Draw all game entities
	for each (Entity* entity in entitiesList)
	{
		entity->Draw();
	}

	//Refresh screen
	window->display();
}

void Game::Finish()
{
	for each (Entity* entity in entitiesList)
	{
		delete entity;
	}

	delete window;
}

void Game::QuitGame()
{
	window->close();
	isRunning = false;
}