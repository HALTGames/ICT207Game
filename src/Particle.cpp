#include "Particle.h"


Particle::Particle(void)
{
}


Particle::~Particle(void)
{
}

void Particle::CreateMissile(int i)
{
	 MissileEffect[i].lifetime= (float)(rand()%500000)/500000.0;
     MissileEffect[i].decay=0.001;
     MissileEffect[i].r = 0.7;
     MissileEffect[i].g = 0.7;
     MissileEffect[i].b = 1.0;
     MissileEffect[i].xpos= 0.0;
     MissileEffect[i].ypos= 0.0;
     MissileEffect[i].zpos= 0.0;
     MissileEffect[i].xspeed = 0.0005-(float)(rand()%100)/100000.0;
     MissileEffect[i].yspeed = 0.01-(float)(rand()%100)/100000.0;
     MissileEffect[i].zspeed = 0.0005-(float)(rand()%100)/100000.0;
     MissileEffect[i].active = true;
}