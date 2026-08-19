#pragma once
#include "cButton.h"

class cDrawButton :
    public cButton
{
private:
protected:
    sf::Vector2f m_PenToolSize;
    sf::Color m_PenToolColor;

   // sf::Texture m_ButtonTexture = loadFromFile("textures/alastorsphere.png");
public:
    cDrawButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role);
    ~cDrawButton();

    void SetPenToolSize(sf::Vector2f _size);
    sf::Vector2f GetPenToolSize();

    void SetPenToolColor(sf::Color _color);
    sf::Color GetPenToolColor();
    
    void Update();
};

