#ifndef __I_SOUND_LISTENER_H_INCLUDED__
#define __I_SOUND_LISTENER_H_INCLUDED__

#include "IReferenceCounted.h"
#include "vector3d.h"
#include "ISceneNode.h"

namespace irr
{
namespace sound
{

//! Interface describing a listener in the sound system
class ISoundListener : public IReferenceCounted
{
public:
	//! Destructor
	virtual ~ISoundListener() {};

	//! Returns the position of the listener in 3d space
	virtual core::vector3df getPosition() = 0;
	//! Sets a new position for the listener in 3d space
	virtual void setPosition(core::vector3df newPosition) = 0;

	virtual core::vector3df getVelocity() = 0;
	//! Sets the velocity of the listener. Don't use units per seconds but units
	virtual void setVelocity(core::vector3df newVelocity) = 0;

	virtual core::vector3df getUpVector() = 0;
	virtual void setUpVector(core::vector3df newUpVector) = 0;

	virtual core::vector3df getForwardOrientation() = 0;
	virtual void setForwardOrientation(core::vector3df newForward) = 0;

	//! Attaches the listener to a SceneNode. If the listener is attached, it will move with the node
	virtual void attachToNode(scene::ISceneNode* node) = 0;
	//! Checks if the listener is attached to a node
	virtual bool isAttached() = 0;
	//! Returns the node to which the listener is attached
	virtual scene::ISceneNode* getAttachedNode() = 0;

	//! This is called every frame. You do not have to call this manually.
	virtual void update(u32 time) = 0;
};

} // end namespace sound
} // end namespace irr

#endif