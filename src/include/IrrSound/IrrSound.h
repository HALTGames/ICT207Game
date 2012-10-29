#ifndef __IRR_SOUND_H_INCLUDED__
#define __IRR_SOUND_H_INCLUDED__

#include "SoundCompileConfig.h"
#include "ISoundObject.h"
#include "ISoundListener.h"
#include "ISoundSystem.h"
#include "ISoundEventReceiver.h"
#include "ESoundDeviceType.h"
#include "IrrlichtDevice.h"

/*! \mainpage IrrSound API documentation
* \section Introduction
* IrrSound is supposed to be an easy to use (it consists of 4! classes) and flexible audio wrapper for the IrrlichtEngine<br>
* Currently it can use FMODEx and IrrKlang as OutputDevices, but it is easy to extend using OpenAL for example
*
* \section Files
* For an information about changes in a version see <a href="changes.txt">Changes.txt</a>
*
* \section Example
* To give you a short example of how to use IrrSound, this program initializes the SoundSystem and plays an
* audio stream.
*
* \code
* #include <Irrlicht.h>
* #include <IrrSound.h>
*
* using namespace irr;
*
* int main(int argc, char** argv)
* {
*    IrrlichtDevice* device = createDevice(); // You can use the null device since IrrSound only needs the IO-parts of the engine.
*    sound::ISoundSystem* soundSystem = sound::createSoundSystem(device);
*    sound::ISoundObject* stream = soundSystem->getStream("your_audio_file.mp3");
*
*    stream->play();
*
*    while(device->run())
*    {
*        soundSystem->update();
*    }
*    
*    // close the SoundSystem
*    soundSystem->drop();
*    device->drop();
*
*    return 0;
* }
* \endcode
*/

namespace irr
{
//! The only namespace IrrSound uses. Every class you need is stored here
namespace sound
{

//! Creates a new instance of the SoundSystem. You should call drop() on the pointer if you no longer need it
IRRSOUND_API ISoundSystem* IRRCALLCONV createSoundSystem(
	IrrlichtDevice* device, ESoundDeviceType deviceType=ESDT_Fmod, ESoundMixingMode mixingMode=ESMM_Hardware,
	ESoundQuality soundQuality=ESQ_High);

}
}

/*! \file IrrSound.h
\brief Main header file of IrrSound, the only file needed to include.
*/

#endif