#pragma once

class Interactable
{
public:

    virtual bool HasActionText() = 0;
    virtual std::string GetActionText() = 0;
    virtual bool AutoInteract() = 0;
    virtual bool CanInteract(class Player* _player) = 0;
    virtual void Interact(class Player* _player) = 0;
};

