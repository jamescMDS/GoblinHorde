/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2022 Media Design School
File Name : GameObject.h
Description : Shared implemenation for objects in the game, base class of every game object
Author : Devon Millar, James Charnley, Sam Chandler, Mahalon
Mail : devon.millar@mds.ac.nz, james.charnley@mds.ac.nz, samuel.chandler@mds.ac.nz, mahalon.Devoe@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

class GameObject
{

public:

	virtual ~GameObject();

	// Called every frame from Game.cpp
	virtual void Update(float _deltaTime);

	// Called every frame from Game.cpp. 
	virtual void Render();

	// Sets position of SFML shape
	// IMPORTANT: If GameObject is using a Rigidbody you most likely want to set the position using Rigidbody::SetPosition()
	void SetPosition(sf::Vector2f _position);

	// return SFML shapes current position
	sf::Vector2f GetPosition();

	// Sets rotation of SFML shape 
	// IMPORTANT: If GameObject is using a Rigidbody you most likely want to set the rotation using Rigidbody::SetRotation()
	void SetRotation(float _angle);

	// return SFML shapes current rotation
	float GetRotation();

	// returns SFML shape's scale
	sf::Vector2f GetScale();
	// Sets SFML shape's scale
	void SetScale(sf::Vector2f _scale);

	// Destroy this GameObject. NOTE: Will not be destroyed until all GameObjects in current scene have been updated
	virtual void Destroy();

	// get collision radius. all objects will be treated as circles with collision detection.
	float GetCollisionRadius();

	// set collision radius
	void SetCollisionRadius(float _radius);

	class Collider* GetCollider();

	virtual void OnCollision(GameObject* _other);

	virtual void AddSprite(const char* _filePath);

	void SetColor(sf::Color _color);

	void AddCollider(ECollisionType _collisionType);

protected:

	// private constructor. This is an abstract class so the contructor should never be called from an outside class
	GameObject();

	// pointer to the sf::Shape this class will use. This must be given a reference to the sf::Shape being used in sub class
	sf::Shape* objectShape;

	// pointer to sf::RenderWindow
	sf::RenderWindow* window;

	// pointer to current Scene() class
	class Scene* scene = nullptr;

	float collisionRadius = 1;
	
	class Collider* collider = nullptr;

	// sprite overlay
	sf::Texture texture;

	class SpriteComponent* sprite;
};

