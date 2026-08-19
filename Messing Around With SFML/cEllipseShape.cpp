#include "cEllipseShape.h"

// THIS WAS TAKEN FROM THE WEBSITE https://www.sfml-dev.org/tutorials/3.1/graphics/shape/#lines
// THIS IS NOT MY OWN CODE

cEllipseShape::cEllipseShape(sf::Vector2f _radius)
	: m_radius(_radius)
{
	update();
}

cEllipseShape::~cEllipseShape()
{
}

void cEllipseShape::SetRaidus(sf::Vector2f _radius)
{
	m_radius = _radius;
	update();
}

sf::Vector2f cEllipseShape::GetRadius()
{
	return m_radius;
}

std::size_t cEllipseShape::getPointCount() const
{
	return 30; // fixed, but could be an attribute of the class if needed
}

sf::Vector2f cEllipseShape::getPoint(std::size_t index) const
{
	static constexpr float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount() - pi / 2;
	float x = std::cos(angle) * m_radius.x;
	float y = std::sin(angle) * m_radius.y;

	return m_radius + sf::Vector2f(x, y);
}
