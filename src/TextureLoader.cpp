#include "TextureLoader.h"


TextureLoader::TextureLoader(void)
{
}


TextureLoader::~TextureLoader(void)
{
}

void TextureLoader::LoadTexture(int i, std::string Name)
{
	/*std::vector<char> chars(Name.c_str(), Name.c_str() + Name.size() + 1u); 
	
	Texture[i] = SOIL_load_OGL_texture
	(
	&chars[0],
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);
	glBindTexture(GL_TEXTURE_2D, Texture[i]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);*/
}
