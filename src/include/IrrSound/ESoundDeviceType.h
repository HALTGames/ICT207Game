#ifndef __E_SOUND_DEVICE_TYPE_H_INCLUDED__
#define __E_SOUND_DEVICE_TYPE_H_INCLUDED__

namespace irr
{
namespace sound
{

//! Enumeration for the available SoundDevices that can be used by IrrSound
enum ESoundDeviceType
{
	//! Use FMODEx as SoundDevice
	ESDT_Fmod,
	//! Use IrrKlang as SoundDevice
	ESDT_IrrKlang,
};

//! Enumeration for sound mixing mode
enum ESoundMixingMode
{
	//! Use hardware for sound mixing. This will use the 3d buffers of the soundcard
	ESMM_Hardware,
	//! Calculate 3d positions in software. Can fix some problems with bad soundcards
	ESMM_Software
};

//! Enumeration for sound quality
enum ESoundQuality
{
	//! Sounds worst but run fastes
	ESQ_Low=0,
	//! Sounds best but is slowest
	ESQ_High
};

}
}

#endif