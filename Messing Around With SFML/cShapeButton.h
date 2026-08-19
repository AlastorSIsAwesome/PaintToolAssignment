/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cShapeButton]
Description : [used for all shapes, declears cShapeButton to have an outline width and fill color]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once
#include "cButton.h"
class cShapeButton :
    public cButton
{
private:
protected:
    float m_OutlineWidth = 0.f;
    sf::Color m_FillColor = sf::Color::White;

public:
    cShapeButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role);
    ~cShapeButton();

    void SetOutlineWidth(float _width);
    float GetOutlineWidth();

    void SetFillColor(sf::Color _color);
    sf::Color GetFillColor();
};

