#include "Element.h"

Element::Element(char* path, char* name)
{
	m_path = path;
	m_name = name;

	m_transform = MaxenceTools::Vector2(0, 0);
	m_rotation = 0;
	m_scale = MaxenceTools::Vector2(1, 1);
}

Element::Element()
{
	m_path = "../Sprites/test.jpg";
	m_name = "An awesome element";

	m_transform = MaxenceTools::Vector2(0, 0);
	m_rotation = 0;
	m_scale = MaxenceTools::Vector2(0.5f, 0.5f);
	m_size = MaxenceTools::Vector2i(0, 0);
}
