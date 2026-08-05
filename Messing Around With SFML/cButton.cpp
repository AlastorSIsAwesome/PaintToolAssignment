#include "cButton.h"

cButton::cButton(sf::Vector2f _position, sf::Color _color)
{
	m_ButtonShape.setPosition(_position);
	m_ButtonShape.setSize({ 95,105 });
	m_ButtonShape.setFillColor(_color);
}

cButton::~cButton()
{
}

void cButton::Update()
{
	printf("Button was Clicked");
}
