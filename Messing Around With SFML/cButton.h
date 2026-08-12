#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// KEY:  
/// <para>0-9 Testing,</para>
/// <para>10-19 Files,</para>
/// <para>20-29 Pen Styles,</para>
/// <para>30-39 Shape Tools</para>
/// </summary>
enum ButtonRole
{
	DefaultButton = 0, // default

	//1 Save and load files 
	FileSaveButton = 11,
	FileLoadButton = 12,

	// pen tools


	// Shape tools



};

class cButton
{
private:
	ButtonRole m_ButtonRole = DefaultButton;
protected:
public:



	sf::RectangleShape m_ButtonShape;

	cButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role);
	~cButton();

	void Update();

};

