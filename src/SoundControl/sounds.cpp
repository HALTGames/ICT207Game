/*===============================================================================================
 PlayList Example
 Copyright (c), Firelight Technologies Pty, Ltd 2004-2011.

 This example shows how to load a playlist and play the sounds in a playlist.
===============================================================================================*/
#include "sounds.h"


sounds::sounds()
{
	system   = 0;
    playlist = 0;
    sound    = 0;
    channel  = 0;
	channel2 = 0;
    isplaylist = false;
    title = NULL;
    count = 0;
	itr = 0;

	result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);
       
}

void sounds::ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

void sounds::addSound(const char *filename, string name)
{
	result = system->createSound(filename, FMOD_HARDWARE, 0, &sounds1[itr]);
	names[itr] = name;
    ERRCHECK(result);
	itr++;
}

void sounds::playSound(string name)
{
	for(int i = 0; i<itr; i++)
	{
		if(names[i] == name)
		{
			system->playSound(FMOD_CHANNEL_FREE, sounds1[i], false, &channel2);
		}
	}

}




void sounds::SoundMenu()
{


	

    result = system->createSound("../media/testing.m3u", FMOD_DEFAULT, 0, &playlist);
    ERRCHECK(result);

    result = playlist->getFormat(&soundtype, 0, 0, 0);
    ERRCHECK(result);

    isplaylist = (soundtype == FMOD_SOUND_TYPE_PLAYLIST);

    if (isplaylist)
    {
        printf("PLAYLIST loaded.\n");
        /*
            Get the first song in the playlist, create the sound and then play it.
        */
        result = playlist->getTag("FILE", count, &tag);
        ERRCHECK(result);

        sprintf(file, "../media/%s", (char *)tag.data);

        result = system->createSound(file, FMOD_DEFAULT, 0, &sound);
        ERRCHECK(result);

        result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
        ERRCHECK(result);

        playlist->getTag("TITLE", count, &tag);
        title = (char *)tag.data;

        count++;
    }
    else
    {
        printf("SOUND loaded.\n");

        /*
            This is just a normal sound, so just play it.
        */
        sound = playlist;

        result = sound->setMode(FMOD_LOOP_NORMAL);
        ERRCHECK(result);

        result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
        ERRCHECK(result);
    }

    printf("\n");

    

	  

}

void sounds::PausePlaySoundTrack()
{
	if (channel)
     {
          bool paused;
		  channel->getPaused(&paused);
          channel->setPaused(!paused);
     }
}

void sounds::loopmain()
{
	
        bool  isplaying = false;

        if (channel && isplaylist)
        {
            /*
                When sound has finished playing, play the next sound in the playlist
            */

            channel->isPlaying(&isplaying);
            if (!isplaying)
            {
                if (sound)
                {
                    sound->release();

                    sound = NULL;
                }

                result = playlist->getTag("FILE", count, &tag);
                if (result != FMOD_OK)
                {
                    count = 0;
                }
                else
                {
                    printf("playing next song in playlist...\n");

                    sprintf(file, "../media/%s", (char *)tag.data);

                    result = system->createSound(file, FMOD_DEFAULT, 0, &sound);
                    ERRCHECK(result);

                    result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
                    ERRCHECK(result);

                    playlist->getTag("TITLE", count, &tag);
                    title = (char *)tag.data;

                    count++;
                }
            }
        }

		/*
        if (_kbhit())
        {
            key = _getch();

            switch (key)
            {
			case 'a' :
				system->playSound(FMOD_CHANNEL_FREE, sounds1[0], false, &channel2);
                    
                    break;
                case 'n' :
                {
                    /*
                        Play the next song in the playlist
                    */
		/*
                    if (channel && isplaylist)
                    {
                        channel->stop();
                    }

                    break;
                }
                case ' ' :
                { 
                    if (channel)
                    {
                        bool paused;

                        channel->getPaused(&paused);
                        channel->setPaused(!paused);
                    }
                }
            }
        }
		*/

        system->update();

        {
            unsigned int ms = 0;
            unsigned int lenms = 0;
            bool         paused = 0;

            if (channel)
            {
                if (sound)
                {
                    result = sound->getLength(&lenms, FMOD_TIMEUNIT_MS);
                    if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                    {
                        ERRCHECK(result);
                    }
                }

                result = channel->getPaused(&paused);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                {
                    ERRCHECK(result);
                }

                result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                {
                    ERRCHECK(result);
                }
            }

          //  printf("Time %02d:%02d:%02d/%02d:%02d:%02d : %s : %s\r", ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100, lenms / 1000 / 60, lenms / 1000 % 60, lenms / 10 % 100, paused ? "Paused " : "Playing ", title);

        }

        Sleep(10);

    
}
