#define STB_IMAGE_IMPLEMENTATION
#include "libs/stb_image.h"
#include "Imgui/imgui.h"
#include "Preview.h"

bool Preview::LoadTextureFromFile(const char * filename, GLuint * out_texture, int* out_width, int * out_height)
{
	// Load from file
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	// Create a OpenGL texture identifier
	GLuint image_texture;
	glGenTextures(1, &image_texture);
	glBindTexture(GL_TEXTURE_2D, image_texture);

	// Setup filtering parameters for display
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Upload pixels into texture
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	stbi_image_free(image_data);

	*out_texture = image_texture;
	*out_width = image_width;
	*out_height = image_height;

	return true;
}

void Preview::execute()
{
	ImGui::Text("Name: %s", m_element->m_name);


	ImGui::SetNextItemWidth(ImGui::GetWindowSize().x * 0.4f);
	ImGui::SliderFloat("PosX", &(m_element->m_transform.x), 0, 2, "%.2f");
	ImGui::SetNextItemWidth(ImGui::GetWindowSize().x * 0.4f);
	ImGui::SameLine(0, 10);
	ImGui::SliderFloat("PosY", &(m_element->m_transform.y), 0, 2, "%.2f");

	ImGui::SetNextItemWidth(ImGui::GetWindowSize().x * 0.4f);
	ImGui::SliderFloat("ScaleX", &(m_element->m_scale.x), 0, 2, "%.1f");
	ImGui::SetNextItemWidth(ImGui::GetWindowSize().x * 0.4f);
	ImGui::SameLine(0, 10);
	ImGui::SliderFloat("ScaleY", &(m_element->m_scale.y), 0, 2, "%.1f");

	ImGui::Text("size = %d x %d", m_element->m_size.x, m_element->m_size.y);
	ImGui::Image((void*)(intptr_t)m_texID, ImVec2(m_element->m_size.x * m_element->m_scale.x, m_element->m_size.y * m_element->m_scale.y));
}

void Preview::init()
{
	bool ret = LoadTextureFromFile(m_element->m_path, &m_texID, &(m_element->m_size.x), &(m_element->m_size.y));
	IM_ASSERT(ret);
}


