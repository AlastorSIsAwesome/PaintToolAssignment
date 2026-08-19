/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cButton.h]
Description : [Base file for cButton class. Includes enum used for later classifications of buttons]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// KEY:  
/// <para> 0 Defaut,</para>
/// <para> 1-2 Files,</para>
/// <para> 3 Pen</para>
/// <para> 4-6 Shape Tools</para>
/// <para> 7-10 Outline </para>
/// <para> 11-15  Color </para>
/// </summary>
enum ButtonRole
{
	DefaultButton = 0, // default

	//Save and load files 
	FileSaveButton,
	FileLoadButton,

	// pen 
	PenButton,

	// Shape tools
	ShapeSquareButton,
	ShapeEllipseButton,
	ShapeLineButton,

	// Outline
	SmallSizeOutlineButton,
	MediumIshSizeOutlineButton,
	MediumOutSizelineButton,
	LargeSizeOutlineButton,

	// Color
	RedColorButton,
	BlueColorButton,
	GreenColorButton,
	WhiteColorButton,
	BlackColorButton,
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

	inline sf::RectangleShape GetButtonObject()
	{
		return m_ButtonShape;
	}


	inline void SetButtonRole(ButtonRole _role) // inline bc its small
	{
		m_ButtonRole = _role;
	}

	inline ButtonRole GetButtonRole() // inline bc its small
	{
		return m_ButtonRole;
	}

	void SetTexture(sf::Texture &_texture); // sets and impliments given texture


	void Update();

};

