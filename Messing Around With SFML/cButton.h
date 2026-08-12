#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// KEY:  
/// <para>0-10 Testing,</para>
/// <para> 11-19 Files,</para>
/// <para> 21-29 Pen Styles,</para>
/// <para> 31-39 Shape Tools</para>
/// </summary>
enum ButtonRole
{
	DefaultButton = 0, // default

	//1 Save and load files 
	FileSaveButton = 11,
	FileLoadButton = 12,

	// pen tools
	PenCircleButton = 21,
	PenSquareButton = 22,
	PenTriangleButton = 23,

	// Shape tools
	ShapeCircleButton = 31,
	ShapeSquareButton = 32,
	ShapeTriangleButton = 33,
	ShapeLineButton = 34,


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

