#include "PlayerObj.h"

//-----------------------------------------------------------------------------

	int PlayerObj::Health = 100;
	int PlayerObj::Mana = 50;
	std::vector<bool> PlayerObj::Inventory;
	PlayerObj::Spells PlayerObj::SelectedSpell = (Spells)1;
	int PlayerObj::ProtectionTimer = 0;
	int PlayerObj::Timer = 0;
	bool PlayerObj::ProtectionStatus = false;

//-----------------------------------------------------------------------------

PlayerObj::PlayerObj()
{
	model.LoadModel("./models/wizard_tpose.obj");
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0;
	SetScale(2);
	Inventory.resize(10); //only 4 currently used atm
	for(int i = 0; i < 10; i++)
	{
		Inventory[i] = false;
	}

	GameCollision::AddCollidable(PLAYER, this);
}

//-----------------------------------------------------------------------------

void PlayerObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();

	int time = glutGet(GLUT_ELAPSED_TIME);
	/*
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glTranslatef(0+position.x, 0+position.y, 0+position.z);
	GLfloat mat_specular1[] = { 0.9, 0.9, 0.9, 0.5 };
	GLfloat mat_both1[] = { 0.9, 0.9, 0.9, 0.5 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_both1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular1);
	if(ProtectionStatus == true)
	{
		//std::cout << "true";
		glutSolidSphere(2.5,10,10);
	}
	glPopMatrix();
	GLfloat mat_specular2[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat mat_both2[] = { 0.1, 0.1, 0.1, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_both2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);

	glPushMatrix();
	//glClearColor (0.0, 0.0, 0.0, 0.0); 
		//glColor4f(0.0, 1.0, 1.0, 0.0);
	//	glTranslatef(position.x, position.y, position.z);
	//	glutSolidSphere(2,6,6);
	glPopMatrix();	*/

 glEnable (GL_BLEND);
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glPushMatrix();
glTranslatef(0+position.x, 0+position.y, 0+position.z);
GLfloat mat_specular1[] = { 0.9, 0.9, 0.9, 0.5 };
GLfloat mat_both1[] = { 0.9, 0.9, 0.9, 0.5 };
glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_both1);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular1);
if(ProtectionStatus == true)
{
std::cout << "true";
glutSolidSphere(2.5,10,10);
}
glPopMatrix();
GLfloat mat_specular2[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat mat_both2[] = { 0.1, 0.1, 0.1, 1 };
glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_both2);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);

if((time/1000) -2 >= Timer/1000)
{
Timer = time;
ProtectionStatus = false;
}



}

//-----------------------------------------------------------------------------

void PlayerObj::ChangePosition(const Vector3 pos)
{
	Vector3 newPos = position + pos;
	model.GetCollisionSphere()->SetCenter(newPos);

	//if(GameCollision::CollidesWith(this->model.GetCollisionSphere(), TERRAIN) ||
	//	GameCollision::CollidesWith(this->model.GetCollisionSphere(), ENEMY))
	//{
	//	model.GetCollisionSphere()->SetCenter(position);
	//}
	//else
	//{
		GameObj::ChangePosition(pos);
	//}
}

//-----------------------------------------------------------------------------

void PlayerObj::ModifyHealth(int Change)
{
	if(ProtectionStatus == false)
	{
		Health += Change;
		if(Health > 100)
		{
			Health = 100;
		}
		else if(Health <= 0)
		{
			Health = 0;
			Death();
		}
	}
}

//-----------------------------------------------------------------------------

bool PlayerObj::ModifyMana(int Change)
{
	Mana += Change;
	if(Mana > 100)
	{
		Mana = 100;
	}
	else if(Mana < 0)
	{
		//reverses the change
		Mana -= Change;
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------

void PlayerObj::Death()
{
	//stubbed
}

//-----------------------------------------------------------------------------

void PlayerObj::SelectSpell(int i)
{
	Spells New = (Spells)i;

	int time = glutGet(GLUT_ELAPSED_TIME);

	if(New != SelectedSpell)
	{
		if(New == (Spells)2)
		{
			if((time / 1000)-2 >=  ProtectionTimer/1000)
			{
				//std::cout << "2 Pressed";
				ProtectionTimer = time;
				SetSpell(New);
			}	
		}
		else
		{
			SetSpell(New);
		}		
	}
}

//-----------------------------------------------------------------------------

void PlayerObj::Shoot(int x, int y)
{
	if(SelectedSpell == (Spells)1)
	{
		Vector3 Target;
		Target.Set(x,y,0);
		ProjectileManager::AddProjectile(PLAYER_PROJECTILE, position.x, position.z, x, y);
	}
	else if(SelectedSpell = (Spells)2)
	{
		if(ModifyMana(-15) == true)
		{
			//std::cout << "SPHERE AAACTIVATE!";
			ProtectionStatus = true;
			Timer = glutGet(GLUT_ELAPSED_TIME);
			glutSetWindow(1);
			glPushMatrix();
				glLoadIdentity();
				glColor3f(0,0,1);
				glTranslatef(GetPosition().x, GetPosition().y, GetPosition().z);
				glutSolidSphere(0.1,6,6);
			glPopMatrix();	
			glutSwapBuffers();
		}
		SetSpell((Spells)1);
	}
}

//-----------------------------------------------------------------------------
