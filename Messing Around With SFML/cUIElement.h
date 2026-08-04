#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class cUIElement
{
private:
protected:
	sf::RectangleShape m_ElementVisual;
	std::string m_ElementID;
	
	sf::Text  m_ElementText;
public:
	cUIElement(sf::Vector2f _position, sf::Vector2f _size, std::string _ID, sf::Font* _fontRef);
	~cUIElement();

	void ButtonReact();
	void Draw();


};

