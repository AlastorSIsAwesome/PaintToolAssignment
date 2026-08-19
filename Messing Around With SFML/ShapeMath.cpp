#include "ShapeMath.h"
#include <iostream>

void ResizeRect(sf::RectangleShape& _rect, sf::Vector2f _mouse)
{
	//
	// get origin and mouse vector
	// 
	// do trig to get hypotonuse of triangle
	// 
	// set shape size to result
	//


	sf::Vector2f _reSize;

	//std::cout << _rect.getPosition().y << std::endl;
	//std::cout << _rect.getPosition().x << std::endl;

	//std::cout << _reSize.y << std::endl;
	_reSize.y = (_mouse.y - _rect.getPosition().y);
	_reSize.x = (_mouse.x - _rect.getPosition().x);
	//float _cSquared = ((_a*_a) + (_b*_b));

	// a = y2 - y1 ... b = x2 - x1 ... c = sqrt(sqr(a) + sqr(b))
	//float LineBetweenOriginAndMouse = ( + );
	//std::cout << _reSize.x << std::endl;
	//std::cout << _reSize.y << std::endl;

	_rect.setSize(_reSize);
}
