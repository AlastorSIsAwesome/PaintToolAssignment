#include "ShapeMath.h"

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

	_reSize.y = (_mouse.y - _rect.getOrigin().y);
	_reSize.x = (_mouse.x - _rect.getOrigin().x);
	//float _cSquared = ((_a*_a) + (_b*_b));

	// a = y2 - y1 ... b = x2 - x1 ... c = sqrt(sqr(a) + sqr(b))
	//float LineBetweenOriginAndMouse = ( + );

	_rect.setSize(_reSize);
}
