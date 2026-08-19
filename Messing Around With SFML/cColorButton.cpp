/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cColorButton.cpp]
Description : [Implimentation for the setters and getters from corresponding .h file]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cColorButton.h"

cColorButton::cColorButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role)
	: cButton(_position, _color, _role) // uses cButton constructor to assign perameters 
{
}

cColorButton::~cColorButton()
{
}

void cColorButton::SetColor(sf::Color _color)
{
	m_ButtonShape.setFillColor(_color);
}

sf::Color cColorButton::GetColor()
{
	return m_ButtonShape.getFillColor();
}
