/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cSizeButton.h]
Description : [Declearation file for cSizeButton, gets and sets the outline size]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once
#include "cButton.h"
class cSizeButton :
    public cButton
{
private:
protected:
    float m_SizeButtonSize = 0.f;  // the size of outline the size button holds

public:
    cSizeButton(sf::Vector2f _position, sf::Color _color, ButtonRole _role,
                    float _size);
    ~cSizeButton();

    void SetSize(float _size);
    float GetSize();
};

