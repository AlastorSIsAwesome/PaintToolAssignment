#pragma once

// THIS WAS TAKEN FROM THE WEBSITE https://www.sfml-dev.org/tutorials/3.1/graphics/shape/#lines
// THIS IS NOT MY OWN CODE

#include <SFML/Graphics.hpp>


class cEllipseShape : public sf::Shape
{
private:
protected:
	sf::Vector2f m_radius = { 0, 0 };
public:
	cEllipseShape(sf::Vector2f _radius);
	~cEllipseShape();

	void SetRaidus(sf::Vector2f _radius);
	sf::Vector2f GetRadius();

	std::size_t getPointCount() const override;

	sf::Vector2f getPoint(std::size_t index) const override;
};

