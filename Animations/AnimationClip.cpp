// Animation Clip class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Animations/AnimationClip.h>

namespace OpenEngine {
namespace Animations {

    AnimationClip::AnimationClip(): state(STOPPED) {

    }
    
    AnimationClip::~AnimationClip() {

    }

    void AnimationClip::Play() {
        state = RUNNING;
    }
    
    void AnimationClip::Stop() {
        state = STOPPED;
    }
    
    void AnimationClip::Pause() {
        state = PAUSED;
    }
    
    AnimationClip::PlayState AnimationClip::GetPlayState() {
        return state;
    }

} // NS Scene
} // NS OpenEngine
