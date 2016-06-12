#include "Entity.h"
#include "Entity.h"


Entity::Entity(sf::RenderWindow* window, string texturePath, list<Entity*>& entitiesList)
{
	
	this->window = window;

	texture.loadFromFile(texturePath);
	setTexture(texture);

	entitiesList.push_back(this);
}

Entity::Entity(sf::RenderWindow* window, string texturePath, string shaderPath, list<Entity*>& entitiesList) :
	Entity(window, texturePath, entitiesList)
{
	SetFragmentShader(shaderPath);
}

Entity::~Entity()
{
}

void Entity::GetInput(sf::Event event, float dt)
{
	
}

void Entity::Update(float dt)
{

}

void Entity::Draw()
{
	if (HasShader())
	{
		shader.setParameter("texture", texture);
		window->draw(*this, &shader);
	}
	else
		window->draw(*this);
}

void Entity::SetFragmentShader(string path)
{
	if (!shader.loadFromFile(path, sf::Shader::Fragment))
	{
		cout << "Couldn't load shader (" << path << ")" << endl;
	}
	else
	{
		hasShader = true;
		shader.setParameter("texture", texture);
		cout << "Successfully loaded shader (" << path << ")" << endl;
	}
}

void Entity::Finish()
{

}
