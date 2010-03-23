// Animation Clip class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_ANIMATION_CLIP_H_
#define _OE_ANIMATION_CLIP_H_

#include <Utils/Timer.h>
#include <Animations/Animation.h>
#include <list>

namespace OpenEngine {
namespace Animations {

    using Utils::Time;
    using std::list;

/**
 * Animation clip.
 * 
 * An animation clip consists of a collection of animations that are
 * to be executed sequentially. This enables a complex animation to be
 * expressed in simpler smaller animations. An animation named "run
 * and jump" could be expressed as an animation named "run" followed
 * by an animation named "jump".
 *
 * @class AnimationClip AnimationClip.h Animations/AnimationClip.h
 */
class AnimationClip {
public:
    enum PlayState{RUNNING, PAUSED, STOPPED};
private:
    PlayState state;
    list<AnimationPtr> animations;
    Time start, current, end;
public:

    AnimationClip();
    virtual ~AnimationClip();

    void Play();
    void Stop();
    void Pause();
    
    PlayState GetPlayState();
};

} // NS Animations
} // NS OpenEngine

#endif // _OE_ANIMATION_CLIP_H_
