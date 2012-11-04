#include "AIManager.h"


AIManager::AIManager()
{
	
	srand(time(0));
	RandomAI =0;
}

void AIManager::CheckForAICreate()
{
	seconds = time(NULL);
	if(seconds>minuser+3)
	{
	minuser = seconds;
	CreateAI();
	}
}



void AIManager::CreateAI() 
{
	RandomAI = rand() %10;
	
	
	if((RandomAI == 1) ||(RandomAI ==2)||(RandomAI ==3)||(RandomAI ==4))
		{
			BirdList.push_back(new Bird());
		}
	else if((RandomAI == 5) ||(RandomAI ==6)||(RandomAI ==7))	
		{
			ShooterList.push_back(new Shooter());
		}
	else if((RandomAI == 8) ||(RandomAI ==9))
		{
			StraferList.push_back(new Strafer());	
		}
	else if(RandomAI == 0)
		{
			AlligatorList.push_back(new Alligator());
		}
}

void AIManager::UpdateAI(Vector3 PlayerPos)
{
	
	
	for(itr=BirdList.begin(); itr != BirdList.end(); ++itr)
	{
		//(*itr)->SubtractHealth(1);
		(*itr)->Update(PlayerPos);
		(*itr)->Display();
		if((*itr)->GetHealth() <= 0)
		{
			Score::Instance()->Modify(10);
			itr = BirdList.erase(itr);
		}

	}

	
	
	for(itrs=ShooterList.begin(); itrs != ShooterList.end(); ++itrs)
	{
		//(*itrs)->SubtractHealth(1);
		(*itrs)->Update(PlayerPos);
		(*itrs)->Display();
		if((*itrs)->GetHealth() <= 0)
		{
			itrs = ShooterList.erase(itrs);
		}

	}

	
	for(itra=AlligatorList.begin(); itra != AlligatorList.end(); ++itra)
	{
		//(*itra)->SubtractHealth(1);
		(*itra)->Update(PlayerPos);
		(*itra)->Display();
		if((*itra)->GetHealth() <= 0)
		{
			itra = AlligatorList.erase(itra);
		}

	}

	
	for(itrst=StraferList.begin(); itrst != StraferList.end(); ++itrst)
	{
		//(*itrst)->SubtractHealth(1);
		(*itrst)->Update(PlayerPos);
		(*itrst)->Display();
		if((*itrst)->GetHealth() <= 0)
		{
			itrst = StraferList.erase(itrst);
		}

	}
}

void AIManager::WipeAI()
{
	list<Bird*>::iterator itr;
	for(itr=BirdList.begin(); itr != BirdList.end(); ++itr)
	{
		itr = BirdList.erase(itr);
		(*itr)->Display();
	}
	

	list<Shooter*>::iterator itrs;
	for(itrs=ShooterList.begin(); itrs != ShooterList.end(); ++itrs)
	{
		itrs = ShooterList.erase(itrs);
		(*itrs)->Display();
	}
	

	list<Alligator*>::iterator itra;
	for(itra=AlligatorList.begin(); itra != AlligatorList.end(); ++itra)
	{
		itra = AlligatorList.erase(itra);
		(*itra)->Display();
	}
	
	list<Strafer*>::iterator itrst;
	for(itrst=StraferList.begin(); itrst != StraferList.end(); ++itrst)
	{
		itrst = StraferList.erase(itrst);
		(*itrst)->Display();
	}
}