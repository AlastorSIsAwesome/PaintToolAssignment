#pragma once
#include "cButton.h"
class cSizeButton :
    public cButton
{
private:
protected:
    float m_SizeButtonSize = 0.f;  // the color that the color button holds

public:
    cSizeButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role,
                    float _size);
    ~cSizeButton();

    void SetSize(float _size);
    float GetSize();
};

