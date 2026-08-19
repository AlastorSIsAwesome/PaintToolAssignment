/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cColorButton.h]
Description : [Declares cColorButton to have setters and getters for thier color]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once
#include "cButton.h"

class cColorButton :
	public cButton
{
private:
protected:

public:
	// only one _color because the display color will be the same as the return color
	cColorButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role);
	~cColorButton();

	void SetColor(sf::Color _color);
	sf::Color GetColor();

};

