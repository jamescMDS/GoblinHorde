#include "PickUp.h"

PickUp::PickUp(sf::RenderWindow* _window, Scene* _scene)
{
    window = _window;
    scene = _scene;
}

bool PickUp::HasActionText()
{
    return false;
}

std::string PickUp::GetActionText()
{
    return std::string();
}

bool PickUp::AutoInteract()
{
    return true;
}

bool PickUp::CanInteract(Player* _player)
{
    return true;
}

void PickUp::Interact(Player* _player)
{
}

PickUp::PickUp()
{
}
