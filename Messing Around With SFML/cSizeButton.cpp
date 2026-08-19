#include "cSizeButton.h"

cSizeButton::cSizeButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role,
							float _size)
	: cButton(_position, _color, _role) // uses cButton constructor to assign perameters 
{
	m_SizeButtonSize = _size;
}

cSizeButton::~cSizeButton()
{
}

void cSizeButton::SetSize(float _size)
{
	m_SizeButtonSize = _size;
}

float cSizeButton::GetSize()
{
	return m_SizeButtonSize;
}
