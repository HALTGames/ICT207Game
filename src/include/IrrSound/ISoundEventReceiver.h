#ifndef __I_SOUND_EVENT_RECEIVER_H_INCLUDED__
#define __I_SOUND_EVENT_RECEIVER_H_INCLUDED__

namespace irr
{
namespace sound
{

class ISoundObject;

//! Enumeration for all Sound event
enum ESoundEventType
{
	//! Event is fired if a sound started to play
	ESET_SoundPlayed,
	//! Event is fired if a sound was paused
	ESET_SoundPaused,
	//! Event is fired if a sound was stopped
	ESET_SoundStopped,
	//! Event is fired if a sound reached its end
	ESET_SoundEnded,
	//! Event is fired when a sound is attached to a SceneNode
	ESET_SoundAttachedToNode,
	//! Event is fired when a sound is detached from its SceneNode
	ESET_SoundDetachedFromNode,
};

//! Struct for holding event data of a sound event
struct SSoundEvent
{
	//! The type of the event
	ESoundEventType EventType;
	//! Pointer to the object that created the event
	ISoundObject* Caller;
	
	//! constructor for the SoundEvent
	SSoundEvent(ESoundEventType type, ISoundObject* caller)
		: EventType(type),Caller(caller)
	{
	}
};

//! Event receiver for the soundsystem.
class ISoundEventReceiver
{
public:
	//! Destructor
	virtual ~ISoundEventReceiver() {}

	//! This method is called when the sound system produces an event
	virtual void OnEvent(SSoundEvent event) = 0;
};

}
}

#endif