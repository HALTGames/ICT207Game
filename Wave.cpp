#include "Wave.h"

Wave wv = Wave();

Wave::Wave(void)
{
	wiggle = 0;

	initWave();
}


void Wave::initWave()
{
	for (int x = 0; x < 45; x++) {
		for(int y = 0; y < 45; y++) {
			points[x][y][0]=float((x/5.0f)-4.5f);
			points[x][y][1]=float((y/5.0f)-4.5f);
			points[x][y][2]=float(sin((((x/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
		}
	}
}

// Our Rendering Is Done Here
void Wave::renderWave(void)   
{
	int x, y;
	float float_x, float_y, float_xb, float_yb, tmp;

	glBegin(GL_QUADS);
	for (x = 0; x < 44; x++) {
		for (y = 0; y < 44; y++) {
			float_x = float(x)/44.0f;
			float_y = float(y)/44.0f;
			float_xb = float(x+1)/44.0f;
			float_yb = float(y+1)/44.0f;

			glTexCoord2f(float_x, float_y);
			glVertex3f(points[x][y][0], points[x][y][1], points[x][y][2]);

			glTexCoord2f(float_x, float_yb);
			glVertex3f(points[x][y+1][0], points[x][y+1][1], points[x][y+1][2]);

			glTexCoord2f(float_xb, float_yb);
			glVertex3f(points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2]);

			glTexCoord2f(float_xb, float_y);
			glVertex3f(points[x+1][y][0], points[x+1][y][1], points[x+1][y][2]);
		}
	}
	glEnd();

	if (wiggle == 4) {
		for (y = 0; y < 45; y++) {
			tmp = points[0][y][2];
			for (x = 0; x < 44; x++) points[x][y][2] = points[x+1][y][2];
			points[44][y][2] = tmp;
		}
		wiggle = 0;
	}

	wiggle++;

	
}