#pragma once
#include "cButton.h"

class cColorButton :
	public cButton
{
private:
protected:
	sf::Color m_ColorButtonColor; // the color that the color button holds

public:
	cColorButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role,
					sf::Color _holidngColor); // called _holdingColor as there can't be two "_color"s
	~cColorButton();

	void SetColor(sf::Color _color);
	sf::Color GetColor();

};

