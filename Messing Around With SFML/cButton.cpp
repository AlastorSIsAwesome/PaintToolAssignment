#include "cButton.h"

cButton::cButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role)
{
	m_ButtonShape.setPosition(_position);
	m_ButtonShape.setSize({ 50,50 });
	m_ButtonShape.setFillColor(_color);

	m_ButtonRole = _role;
}

cButton::~cButton()
{
}

void cButton::SetTexture(sf::Texture &_texture)
{
	m_ButtonShape.setTexture(&_texture);
}

void cButton::Update()
{
	printf("Button was Clicked");

}
