#pragma once
#include "libs/gl3w/GL/gl3w.h"
#include "sources/Element.h"
#include "Imgui/imgui.h"

class Preview
{
	public:

		Preview() { m_element = new Element(); };
		~Preview() {};
		void execute();
		void init();
		char* getElementName() { return m_element->m_name; };

	private:
		bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

		// Load from file
		Element* m_element;

		// OGL Texture ID
		GLuint m_texID = 0;

};

