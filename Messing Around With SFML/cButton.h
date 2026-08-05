#pragma once
#include <SFML/Graphics.hpp>

enum ButonRole
{
	// blah blah blah
};

class cButton
{
private:
protected:
public:



	sf::RectangleShape m_ButtonShape;

	cButton(sf::Vector2f _position, sf::Color _color);
	~cButton();

	void Update();

};

