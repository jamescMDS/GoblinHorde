#include "SFMLVectorMath.h"
#include "Weapon.h"
#include "Scene.h"
#include "Character.h"

Character::Character(sf::RenderWindow* _window, Scene* _scene, float _maxHealth)
{
	window = _window;
	scene = _scene;
	maxHealth = _maxHealth;
	currentHealth = maxHealth;
}

void Character::Update(float _deltatime)
{
	GameObject::Update(_deltatime);

	if (equippedWeapon != nullptr)
	{
		equippedWeapon->SetPosition(GetPosition());
		equippedWeapon->SetRotation(GetRotation());
	}

	Move(velocity * (moveSpeed * _deltatime));
}



void Character::Move(sf::Vector2f _movement)
{
	SetPosition(GetPosition() + _movement);
}

void Character::TakeDamage(int _amount)
{
	currentHealth -= _amount;

	if (currentHealth <= 0)
	{
		Destroy();
	}
}

void Character::TakeDamage(int _amount, Character* _player)
{
}

void Character::AddHealth(int _amount)
{
	if (currentHealth + _amount > maxHealth)
	{
		currentHealth = maxHealth;
	}
	else
	{
		currentHealth += _amount;
	}
}

void Character::Destroy()
{
	// destory weapon if exists
	if (equippedWeapon != nullptr)
	{
		scene->DestroySceneObject(equippedWeapon);
	}
	scene->DestroySceneObject(this);
}


