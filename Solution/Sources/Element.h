#pragma once

#include <string>
#include <math.h>
#include "Sources/MaxMaths.h"
class Element
{
public:

	// Properties
	char* m_name;
	char* m_path;
	MaxenceTools::Vector2 m_transform;
	MaxenceTools::Vector2 m_scale;
	MaxenceTools::Vector2i m_size;
	float m_rotation;
	unsigned char* m_data;

	//ctor
	Element(char* path, char* name);
	Element();

	//dtor
	~Element() {};
	
};