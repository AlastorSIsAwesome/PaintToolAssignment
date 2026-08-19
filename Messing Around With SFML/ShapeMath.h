/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [ShapeMath.h]
Description : [Blueprint for all math related situations in this program]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

#include <SFML/Graphics.hpp>
#include "cEllipseShape.h"

static constexpr float pi = 3.141592654f; // taken from the SFML website https://www.sfml-dev.org/tutorials/3.1/graphics/shape/#lines



// this is a series of functions that will be used througout the program
// this is not a class

/// <summary>
/// Returns a size for shape Rectange with respect to the shape's origin and the user's mosue position
/// </summary>
/// <param name="_origin"> The origin of the shape (Vector2f) </param>
/// <returns></returns>
void ResizeRect(sf::RectangleShape& _rect, sf::Vector2f _mouse);

void ResizeEllipse(cEllipseShape& _ellipse, sf::Vector2f _mouse);

void ResizeLine(sf::RectangleShape& _line, sf::Vector2f _mouse, sf::Vector2f _ogLinePosition);
