#ifndef __I_SOUND_SYSTEM_H_INCLUDED__
#define __I_SOUND_SYSTEM_H_INCLUDED__

#include "IReferenceCounted.h"
#include "vector3d.h"
#include "IReadFile.h"
#include "IMesh.h"
#include "ISceneNode.h"
#include "ISoundEventReceiver.h"
#include "ESoundDeviceType.h"

namespace irr
{
namespace sound
{

class ISoundObject;
class ISoundListener;

//! Interface for accessing the sound system of the engine
class ISoundSystem : public IReferenceCounted
{
public:
	//! Destructor
	virtual ~ISoundSystem() {};

	//! Returns an interface to a sound.
	virtual ISoundObject* getSound(io::IReadFile* alreadyOpenedFile) = 0;
	//! Returns an interface to a sound.
	virtual ISoundObject* getSound(const c8* fileName) = 0;
	//! Returns an interface to a stream. A stream is just like a sound, except that a stream is not loaded
	//! completely into memory
	virtual ISoundObject* getStream(io::IReadFile* alreadyOpenedFile) = 0;
	//! Returns an interface to a stream. A stream is just like a sound, except that a stream is not loaded
	//! completely into memory
	virtual ISoundObject* getStream(const c8* fileName) = 0;

	//! Returns the currently active listener
	virtual ISoundListener* getCurrentListener() = 0;
	//! Sets a new listener as the active one
	virtual void setCurrentListener(ISoundListener* newListener) = 0;
	//! Creates a new SoundListener at the given position. If you set activate to true, the listener will
	//! be activated after it was created. You should call drop() on the pointer if you no longer need it.
	virtual ISoundListener* createNewListener(core::vector3df position, bool activate=false) = 0;

	//! Updates the SoundSystem and the underlying sound devices. You have to call this once per frame
	virtual void update(u32 time) = 0;

	//! Adds a mesh to the geometry engine. Note that this feature is currently only supported if you created
	//! the SoundSystem with ESDT_Fmod
	virtual void addMeshToGeometry(scene::IMesh* mesh, scene::ISceneNode* node = 0) = 0;
	//! Removes all meshes from the internal cache
	virtual void removeAllMeshes() = 0;

	//! Returns the number of currently loaded sounds
	virtual u32 getSoundObjectCount() = 0;
	//! Returns the number of currently playing sounds
	virtual u32 getPlayCount() = 0;

	//! Stops all sounds
	virtual void stopAll() = 0;
	//! Pauses all sounds
	//! \param pause: If set to true all sounds will stop playing, if set to false all sounds will start playing.
	virtual void pauseAll(bool pause=true) = 0;

	//! Sets a new event receiver to the SoundSystem
	virtual void setEventReceiver(ISoundEventReceiver* receiver) = 0;
	//! Sets if the event receiver should be enabled or not
	virtual void enableEventReceiver(bool enable) = 0;

	//! Injects an event into the event system. You should not call this unless you know what you are doing
	virtual void fireEvent(SSoundEvent event) = 0;

	//! Returns the type of the sound device, for example ESDT_Fmod if IrrSound was initialized using FMOD
	virtual ESoundDeviceType getDeviceType() = 0;

	//! Returns a pointer to the object the sound device uses. You don't need this method, but if you are trying
	//! to do something irrSound does not support or you need the native interface for some other reasons you can
	//! use this method. You have to cast the returned pointer to the interface you need. (You can check the used
	//! sound device by calling ISoundSystem::getDeviceType()
	virtual void* getDeviceObject() = 0;
};

}
}

#endif