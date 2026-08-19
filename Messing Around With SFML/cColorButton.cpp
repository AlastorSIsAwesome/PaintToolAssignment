#include "cColorButton.h"

cColorButton::cColorButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role,
							sf::Color _holidngColor)
	: cButton(_position, _color, _role) // uses cButton constructor to assign perameters 
{
	m_ColorButtonColor = _holidngColor;
}

cColorButton::~cColorButton()
{
}

void cColorButton::SetColor(sf::Color _color)
{
	m_ColorButtonColor = _color;
}

sf::Color cColorButton::GetColor()
{
	return m_ColorButtonColor;
}
