#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;

#pragma once

class Entity : public sf::Sprite
{

protected:

	sf::RenderWindow* window;
	sf::Texture texture;

	//Movement and positioning
	enum Orientation { LEFT = -1, RIGHT = 1 };
	float currentSpeed = 0;
	float maxSpeed;
	float acceleration = 1;
	bool decelerate = false;
	bool accelerate = false;
	Orientation orientation;

	//Shaders
	sf::Shader shader;
	bool hasShader = false;

public:

	Entity(sf::RenderWindow* window, string texturePath, list<Entity*>& entitiesList);
	Entity(sf::RenderWindow* window, string texturePath, string shaderPath, list<Entity*>& entitiesList);
	~Entity();

	//Core stuff
	virtual void Update(float dt);
	virtual void GetInput(sf::Event event, float dt);
	virtual void Draw();
	virtual void Finish();

	//Shaders
	void SetFragmentShader(string path);
	bool HasShader() { return hasShader; }

	//Movement and positioning
	void SetMaxSpeed(float speed) { this->maxSpeed = speed; }
	float GetMaxSpeed() { return maxSpeed; }
	float GetCurrentSpeed() { return currentSpeed; }

	void SetAcceleration(float acceleration) { this->acceleration = acceleration; }
	float GetAcceleration() { return acceleration; }

	void FlipHorizontal() { setScale(-getScale().x, getScale().y); }
	//void FlipHorizontalLeft() { sprite.setScale(-sprite.getScale().x, sprite.getScale().y); }
	//void FlipHorizontalRight() { sprite.setScale(abs(sprite.getScale().x), sprite.getScale().y); }

};

