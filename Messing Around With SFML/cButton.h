#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// KEY:  
/// <para> 0 Defaut,</para>
/// <para> 1-2 Files,</para>
/// <para> 3-5 Pen Styles,</para>
/// <para> 6-9 Shape Tools</para>
/// </summary>
enum ButtonRole
{
	DefaultButton = 0, // default

	//Save and load files 
	FileSaveButton,
	FileLoadButton,

	// pen tools
	PenCircleButton,
	PenSquareButton,
	PenTriangleButton,

	// Shape tools
	ShapeCircleButton,
	ShapeSquareButton,
	ShapeTriangleButton,
	ShapeLineButton,


};

class cButton
{
private:
protected:
	ButtonRole m_ButtonRole = DefaultButton;
	
public:

	sf::RectangleShape m_ButtonShape;

	

	cButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role);
	~cButton();

	inline void SetButtonRole(ButtonRole _role) // inline bc its small
	{
		m_ButtonRole = _role;
	}

	inline ButtonRole GetButtonRole() // inline bc its small
	{
		return m_ButtonRole;
	}


	void Update();

};

