#ifndef __SOUND_COMPILE_CONFIG_H_INCLUDED__
#define __SOUND_COMPILE_CONFIG_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifndef _IRR_STATIC_LIB_
#ifdef IRRSOUND_EXPORTS
#define IRRSOUND_API __declspec(dllexport)
#else
#define IRRSOUND_API __declspec(dllimport)
#endif // IRRLICHT_EXPORT
#else
#define IRRSOUND_API
#endif // _IRR_STATIC_LIB_

//! define _IRR_COMPILE_WITH_FMOD to compile the sound engine with fmod support
#define _IRR_COMPILE_WITH_FMOD

#ifdef _IRR_COMPILE_WITH_FMOD
//! define _IRR_USE_FMOD_PLUGINS to link against the smaller version of fmod, which has no plugins built in
// #define _IRR_USE_FMOD_PLUGINS
#endif // _IRR_COMPILE_WITH_FMOD

//! define _IRR_COMPILE_WITH_FMOD to compile the sound engine with irrklang support
#define _IRR_COMPILE_WITH_IRRKLANG

#endif // __SOUND_COMPILE_CONFIG_H_INCLUDED__