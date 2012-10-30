#include "TextureLoader.h"

int TextureLoader::count = 0;

TextureLoader::TextureLoader(void)
{
}


TextureLoader::~TextureLoader(void)
{
}

void TextureLoader::LoadTexture(const char * filename, int width, int height, int i)
{

	unsigned char * data;
    FILE * file;

	//The following code will read in our RAW file
    file = fopen( filename, "rb" );
    if ( file == NULL ) //throw error!
    data = (unsigned char *)malloc( width * height * 4 );
    fread( data, width * height * 4, 1, file );
    fclose( file );

	glGenTextures(1, &Texture[i]); //generate the texture with the loaded data
    glBindTexture(GL_TEXTURE_2D, Texture[i]); //bind the texture to it’s array

    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); //set texture environment parameters
    //And if you go and use extensions, you can use Anisotropic filtering textures which are of an
    //even better quality, but this will do for now.
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	//Here we are setting the parameter to repeat the texture instead of clamping the texture
    //to the edge of our shape. 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, data);
						std::cout << "Here";
    free( data ); //free the texture
}