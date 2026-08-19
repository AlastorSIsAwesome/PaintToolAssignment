#include "cDrawButton.h"

cDrawButton::cDrawButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role) 
	: cButton(_position, _color, _role) // uses cButton constructor to assign perameters 
{

}

cDrawButton::~cDrawButton()
{
}

void cDrawButton::SetPenToolSize(sf::Vector2f _size)
{
}

sf::Vector2f cDrawButton::GetPenToolSize()
{
	return sf::Vector2f();
}

void cDrawButton::SetPenToolColor(sf::Color _color)
{
}

sf::Color cDrawButton::GetPenToolColor()
{
	return sf::Color();
}

void cDrawButton::Update()
{
	printf("Draw Button was Clicked");
}
