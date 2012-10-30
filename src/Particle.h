#pragma once

#include <stdlib.h>
class Particle
{
public:
	typedef struct
	{
		float lifetime;                       // total lifetime of the particle
		float decay;                          // decay speed of the particle
		float r,g,b;                          // color values of the particle
		float xpos,ypos,zpos;                 // position of the particle
		float xspeed,yspeed,zspeed;           // speed of the particle
		bool active;						  // is particle active or not?
	} PARTICLES;

	Particle(void);
	~Particle(void);

	void CreateMissile(int i);

private:
	PARTICLES MissileEffect[100];
	PARTICLES SecondEffect[100];
};

