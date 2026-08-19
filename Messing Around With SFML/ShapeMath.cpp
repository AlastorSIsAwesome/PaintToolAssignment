/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [ShapeMath.cpp]
Description : [Implimentation for all mathmatical problems within the program]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "ShapeMath.h"
#include <iostream>
#include <cmath>

void ResizeRect(sf::RectangleShape& _rect, sf::Vector2f _mouse)
{
	sf::Vector2f _reSize;

	_reSize.x = (_mouse.x - _rect.getPosition().x);
	_reSize.y = (_mouse.y - _rect.getPosition().y);

	_rect.setSize(_reSize);
}

void ResizeEllipse(cEllipseShape& _ellipse, sf::Vector2f _mouse)
{
	sf::Vector2f _reSize;

	_reSize.x = ((_mouse.x - _ellipse.getPosition().x)/2); // need to half because its a radius
	_reSize.y = ((_mouse.y - _ellipse.getPosition().y)/2);


	_ellipse.SetRaidus(_reSize);
}

void ResizeLine(sf::RectangleShape& _line, sf::Vector2f _mouse, sf::Vector2f _ogLinePosition)
{
	// width should stay constant
	// Hypotonuse and length can fluctuate
	// 
	// Width = Outline length/starting length
	// Length = _line x position - _mouse x position
	sf::Vector2f _reSize;

	_reSize.x = (_mouse.x - _line.getPosition().x);
	_reSize.y = 10.f;

	_line.setSize(_reSize);

	// To get the angle of the line
	// (xa-xb) = O (ya-yb) = A
	// tan (theta) = O/A
	// inverse tan (O/A) = theta

	float Radians = std::atan2((_mouse.y - _ogLinePosition.y), (_mouse.x - _ogLinePosition.x));

	//convert from radians to degrees

	_line.rotate(sf::degrees((Radians * 180) / pi));

}
