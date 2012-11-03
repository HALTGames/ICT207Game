#include "Particle.h"


Particle::Particle(void)
{
	MaxParticle = 1000;
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

void Particle::DecayMissile()
{
	 for(int i=0;i<=MaxParticle;i++){      // evolve the particle parameters
     MissileEffect[i].lifetime-=MissileEffect[i].decay;
     MissileEffect[i].xpos+=MissileEffect[i].xspeed;
     MissileEffect[i].ypos+=MissileEffect[i].yspeed;
     MissileEffect[i].zpos+=MissileEffect[i].zspeed;
     MissileEffect[i].yspeed-=0.00007;
   }
}

void Particle::DrawMissile()
{
	glLoadIdentity();

	//glBindTexture(GL_TEXTURE_2D,0);          // choose particle texture
	for (int i=0;i<=MaxParticle;i++)
	{
		if(MissileEffect[i].ypos<0.0)
		{
			MissileEffect[i].lifetime=0.0;
		}
		if((MissileEffect[i].active==true) && (MissileEffect[i].lifetime>0.0))
		{
			glColor3f(MissileEffect[i].r,MissileEffect[i].g,MissileEffect[i].b);
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(0.0,1.0); glVertex3f(MissileEffect[i].xpos+0.002, MissileEffect[i].ypos+0.002, MissileEffect[i].zpos+0.0);     // top    right
				glTexCoord2f(0.0,0.0); glVertex3f(MissileEffect[i].xpos-0.002, MissileEffect[i].ypos+0.002, MissileEffect[i].zpos+0.0);     // top    left
				glTexCoord2f(1.0,1.0); glVertex3f(MissileEffect[i].xpos+0.002, MissileEffect[i].ypos-0.002, MissileEffect[i].zpos+0.0);     // bottom right
				glTexCoord2f(1.0,0.0); glVertex3f(MissileEffect[i].xpos-0.002, MissileEffect[i].ypos-0.002, MissileEffect[i].zpos+0.0);     // bottom left
			glEnd();
		} 
		else 
		{
			CreateMissile(i);
		}
    }
	DecayMissile();
}