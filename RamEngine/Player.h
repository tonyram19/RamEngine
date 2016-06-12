#pragma once

#include "Entity.h"

class Player :	public Entity
{

private:

	bool keyPressed = false;

public:
	
	Player(sf::RenderWindow* window, string texturePath, list<Entity*>& entitiesList);
	Player(sf::RenderWindow* window, string texturePath, string shaderPath, list<Entity*>& entitiesList);
	~Player();

	void Update(float dt) override;
	void GetInput(sf::Event event, float dt) override;
	void Finish() override;

};

