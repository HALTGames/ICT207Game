#include "AIManager.h"

void AIManager::CheckForAICreate()
{
	seconds = time(NULL);
	if(seconds>minuser+1)
	{
	minuser = seconds;
	CreateAI();
	}
}



void AIManager::CreateAI() 
{
	RandomAI = rand() %4;
	cout<<RandomAI<<"   RANDOM AI NUM \n";
	switch(RandomAI)
	{
	case 0:
		{
			cout<<"BirdCreated \n";
			//AIBird = new Bird;
			//AIBird->SetPosition(Placement);
			BirdList->push_back(new Bird);
			//delete[] AIBird;
			break;
		}
	case 1:
		{
			cout<<"ShooterCreated \n";
			//AIShooter = new Shooter;
			//AIShooter->SetPosition(Placement);
			ShooterList->push_back(new Shooter);
			//delete[] AIShooter;
			break;
		}
	case 2:
		{
			cout<<"AlligatorCreated \n";
			//AIAlligator = new Alligator;
			//AIAlligator->SetPosition(Placement);
			AlligatorList->push_back(new Alligator);
			//delete[] AIAlligator;
			break;
		}
	case 3:
		{
			cout<<"StraferCreated \n";
			//AIStrafer = new Strafer;
			//AIStrafer->SetPosition(Placement);
			StraferList->push_back(new Strafer);
			break;
		}
	}
}

void AIManager::UpdateAI()
{

	list<Bird*>::iterator itr;
	for(itr=BirdList->begin(); itr != BirdList->end(); ++itr)
	{
		//(*itr)->SubtractHealth(1);
		//(*itr)->Update(playerObj->GetPosition());
		(*itr)->Display();
		if((*itr)->GetHealth() < 0)
		{
			itr = BirdList->erase(itr);
		}

	}


	list<Shooter*>::iterator itrs;
	for(itrs=ShooterList->begin(); itrs != ShooterList->end(); ++itrs)
	{
		//(*itrs)->SubtractHealth(1);
		//(*itrs)->Update(playerObj->GetPosition());
		(*itrs)->Display();
		if((*itrs)->GetHealth() < 0)
		{
			itrs = ShooterList->erase(itrs);
		}

	}

	list<Alligator*>::iterator itra;
	for(itra=AlligatorList->begin(); itra != AlligatorList->end(); ++itra)
	{
		//(*itra)->SubtractHealth(1);
		//(*itra)->Update(playerObj->GetPosition());
		(*itra)->Display();
		if((*itra)->GetHealth() < 0)
		{
			itra = AlligatorList->erase(itra);
		}

	}

	list<Strafer*>::iterator itrst;
	for(itrst=StraferList->begin(); itrst != StraferList->end(); ++itrst)
	{
		//(*itrst)->SubtractHealth(1);
		//(*itrst)->Update(playerObj->GetPosition());
		(*itrst)->Display();
		if((*itrst)->GetHealth() < 0)
		{
			itrst = StraferList->erase(itrst);
		}

	}
}

void AIManager::WipeAI()
{
	list<Bird*>::iterator itr;
	for(itr=BirdList->begin(); itr != BirdList->end(); ++itr)
	{
		itr = BirdList->erase(itr);
		(*itr)->Display();
	}
	

	list<Shooter*>::iterator itrs;
	for(itrs=ShooterList->begin(); itrs != ShooterList->end(); ++itrs)
	{
		itrs = ShooterList->erase(itrs);
		(*itrs)->Display();
	}
	

	list<Alligator*>::iterator itra;
	for(itra=AlligatorList->begin(); itra != AlligatorList->end(); ++itra)
	{
		itra = AlligatorList->erase(itra);
		(*itra)->Display();
	}
	
	list<Strafer*>::iterator itrst;
	for(itrst=StraferList->begin(); itrst != StraferList->end(); ++itrst)
	{
		itrst = StraferList->erase(itrst);
		(*itrst)->Display();
	}
}