#include "RAWTexture.h"


RAWTexture::RAWTexture(void)
{
}


RAWTexture::~RAWTexture(void)
{
}

GLuint RAWTexture::LoadTexture(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;
	FILE * file;

	//The following code will read in our RAW file
	file = fopen( filename, "rb" );
	if ( file == NULL ) return 0;
	data = (unsigned char *)malloc( width * height * 4 );
	fread( data, width * height * 4, 1, file );
	fclose( file );

	glGenTextures( 1, &texture ); //generate the texture with the loaded data
	glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture to it’s array
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); //set texture environment parameters

	//here we are setting what textures to use and when. The MIN filter is which quality to show
	//when the texture is near the view, and the MAG filter is whichquality to show when the texture
	//is far from the view.

	//The qualities are (in order from worst to best)
	//GL_NEAREST
	//GL_LINEAR
	//GL_LINEAR_MIPMAP_NEAREST
	//GL_LINEAR_MIPMAP_LINEAR

	//And if you go and use extensions, you can use Anisotropic filtering textures which are of an
	//even better quality, but this will do for now.
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	//Here we are setting the parameter to repeat the texture instead of clamping the texture
	//to the edge of our shape. 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	//Generate the texture
	//gluBuild2DMipmaps(GL_TEXTURE_2D,4,width,height,GL_RGBA,GL_UNSIGNED_BYTE,data);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, data);
	free( data ); //free the texture
	return texture; //return whether it was successfull
}

void RAWTexture::FreeTexture(GLuint texture)
{
	glDeleteTextures( 1, &texture ); 
}
