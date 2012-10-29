#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>

#include "../inc/fmod.hpp"
#include "../inc/fmod_errors.h"

using namespace std;

class sounds
{
public:
	sounds();
	void ERRCHECK(FMOD_RESULT result);
	void SoundMenu();
	void addSound(const char *filename, string name);
	void playSound(string name);
	void PausePlaySoundTrack();
	void loopmain();

private:
	FMOD::System     *system;
    FMOD::Sound      *playlist;
    FMOD::Sound      *sound;
    FMOD::Channel    *channel;
	FMOD::Channel    *channel2;
    FMOD_TAG          tag;
    FMOD_RESULT       result;
    FMOD_SOUND_TYPE   soundtype;
	FMOD::Sound		  *sounds1[40];
    bool              isplaylist;
    char             *title;
    int               count;
    int               key;
    unsigned int      version;
    char              file[128];
	int itr;
	string names[40];
};