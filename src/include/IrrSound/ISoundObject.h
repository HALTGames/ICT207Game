#ifndef ___I_SOUND_OBJECT_H_INCLUDED__
#define ___I_SOUND_OBJECT_H_INCLUDED__

#include "IReferenceCounted.h"
#include "vector3d.h"
#include "ISceneNode.h"

namespace irr
{
namespace sound
{

//! Interface describing a soundobject
class ISoundObject : public IReferenceCounted
{
public:
	//! Destructor
	virtual ~ISoundObject() {};

	//! Checks if the sound is streamed or not
	virtual bool isStream() = 0;
	//! Returns the length of the sound in milliseconds
	virtual u32 getLength() = 0;
	//! Returns the current play position of the sound in milliseconds
	virtual u32 getPosition() = 0;
	//! Sets a new play position
	virtual void setPosition(u32 pos) = 0;
	//! Returns the current position of the sound in 3d space
	virtual core::vector3df get3DPosition() = 0;
	//! Sets a new position (and velocity) of the sound in 3d space
	virtual void set3DPosition(core::vector3df pos, core::vector3df *vel=0) = 0;

	//! Returns the current volume of the sound ( from 0.0 to 1.0, where 1.0 means 100%)
	virtual float getVolume() = 0;
	//! Sets a new volume for the sound
	virtual void setVolume(float volume) = 0;

	//! Sets a new maximum distance for the sound. This distance describes the point where the sound
	//! stops becoming quieter
	virtual void setMaxDistance(f32 newMax) = 0;
	//! Returns the current maximum distance of the sound
	virtual f32 getMaxDistance() = 0;
	//! Sets a new minimum distance for the sound. This distance describes the point where the sound
	//! stops becoming louder
	virtual void setMinDistance(f32 newMin) = 0;
	//! Returns the current minimum distance of the sound
	virtual f32 getMinDistance() = 0;
	//! Sets a new minimum and maximum distance for the sound
	virtual void setMinMaxDistance(f32 newMin, f32 newMax) = 0;

	//! Plays the sound with its current settings (position in 3d space, volume, etc.)
	virtual void play() = 0;
	//! Pauses the sound
	virtual void pause() = 0;
	//! Sets if the sound is paused or not
	virtual void setPaused(bool paused) = 0;
	//! Stops the sound and resets the play position to the beginning
	virtual void stop() = 0;

	//! Set if the sound should be looped
	virtual void setLoop(bool loop) = 0;
	//! Checks if the sound is looping
	virtual bool isLooping() = 0;
	//! Checks if the sound is currently playing
	virtual bool isPlaying() = 0;

	//! Updates the sound. You should not call this method manually. The ISoundSystem does this for you
	virtual void update(u32 time) = 0;

	//! Attaches the sound to a SceneNode. The sound will move with the scenenode
	virtual void attachSoundToNode(scene::ISceneNode* node) = 0;
	//! Detaches the sound if it's attached to any SceneNode
	virtual void detachSound() = 0;
	//! Checks if the sound is currently attached to a SceneNode
	virtual bool isAttached() = 0;
	//! Returns the SceneNode the sound is currently attached to. 0 if the sound is not attached
	virtual scene::ISceneNode* getAttachedNode() = 0;

	//! Returns the name of the file the sound was loaded from or an empty string if the sound was loaded from
	//! memory
	virtual core::stringc getFileName() = 0;

	//! Returns a pointer to the object the sound device uses. You don't need this method, but if you are trying
	//! to do something irrSound does not support or you need the native interface for some other reasons you can
	//! use this method. You have to cast the returned pointer to the interface you need. (You can check the used
	//! sound device by calling ISoundSystem::getDeviceType()
	virtual void* getDeviceObject() = 0;
};

}
}

#endif