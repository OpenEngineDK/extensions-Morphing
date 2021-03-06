// Animation Controller class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Animations/AnimationController.h>

namespace OpenEngine {
namespace Animations {



    AnimationController::AnimationController() {

    }
    
    AnimationController::~AnimationController() {

    }

    void AnimationController::Handle(ProcessEventArg e) {
        event.Notify(AnimationEventArg(Time(e.approx)));
    }
    
} // NS Animations
} // NS OpenEngine
