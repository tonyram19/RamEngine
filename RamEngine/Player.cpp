#include "Player.h"

Player::Player(sf::RenderWindow* window, string texturePath, list<Entity*>& entitiesList) : 
	Entity(window, texturePath, entitiesList)
{
}

Player::Player(sf::RenderWindow* window, string texturePath, string shaderPath, list<Entity*>& entitiesList) : 
	Entity(window, texturePath, shaderPath, entitiesList)
{
}

Player::~Player()
{
}



void Player::GetInput(sf::Event event, float dt)
{
	if (event.type == sf::Event::KeyReleased)
	{
		decelerate = true;
		accelerate = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		accelerate = true;
		decelerate = false;
		orientation = Orientation::RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		accelerate = true;
		decelerate = false;
		orientation = Orientation::LEFT;
	}
	
}
void Player::Update(float dt)
{
	if (accelerate)
	{
		currentSpeed = currentSpeed + (acceleration * orientation) * dt;

		if (orientation == Orientation::RIGHT && currentSpeed >= maxSpeed)
			currentSpeed = maxSpeed;

		if (orientation == Orientation::LEFT && currentSpeed <= -maxSpeed)
			currentSpeed = -maxSpeed;
	}
	
	if (decelerate)
	{
		currentSpeed = currentSpeed - (acceleration * orientation) * dt;
		
		if (orientation == Orientation::RIGHT && currentSpeed < 0)
			currentSpeed = 0;

		if (orientation == Orientation::LEFT && currentSpeed > 0)
			currentSpeed = 0;
	}

	move(currentSpeed * dt, 0);
	
}


void Player::Finish()
{

}