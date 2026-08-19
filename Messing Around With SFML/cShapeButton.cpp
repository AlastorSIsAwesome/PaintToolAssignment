/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cShapeButton.cpp]
Description : [Implimentation for all setters and getters in cShapeButton.h]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cShapeButton.h"

cShapeButton::cShapeButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role)
							: cButton(_position, _color, _role) // uses cButton constructor to assign perameters 
{
}

cShapeButton::~cShapeButton()
{
}

void cShapeButton::SetOutlineWidth(float _width)
{
	m_OutlineWidth = _width;
}

float cShapeButton::GetOutlineWidth()
{
	return m_OutlineWidth;
}

void cShapeButton::SetFillColor(sf::Color _color)
{
	m_FillColor = _color;
}

sf::Color cShapeButton::GetFillColor()
{
	return m_FillColor;
}
