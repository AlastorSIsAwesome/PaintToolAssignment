/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cDrawButton.h]
Description : [Declares cDrawButton to have a size and color]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once
#include "cButton.h"

class cDrawButton :
    public cButton
{
private:
protected:
    sf::Vector2f m_PenToolSize = sf::Vector2f({10.f, 10.f});
    sf::Color m_PenToolColor = sf::Color::White;

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

