// Animation Controller class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_ANIMATION_CONTROLLER_H_
#define _OE_ANIMATION_CONTROLLER_H_

#include <Core/IListener.h>
#include <Core/Event.h>
#include <Core/EngineEvents.h>
#include <Utils/Timer.h>

namespace OpenEngine {
namespace Animations {

    using Core::IListener;
    using Core::Event;
    using Core::ProcessEventArg;
    using Utils::Time;

    class AnimationEventArg {
    public:
        Time time;
        AnimationEventArg(Time time): time(time) {}
        virtual ~AnimationEventArg() {}
    };

    /**
     * Animation Controller Module.
     * 
     * The animation controller is responsible for driving every
     * individual animation by sending out animation events in regular
     * time intervals.
     * 
     * @class AnimationController AnimationController.h Animations/AnimationController.h
     */
    class AnimationController : public IListener<ProcessEventArg> {
    private:
        Event<AnimationEventArg> event;
        Time time;
    public:
        
        AnimationController();
        virtual ~AnimationController();
        
        void Handle(ProcessEventArg e);
        
        Event<AnimationEventArg>& AnimationEvent() { return event; }
    
    };
    
} // NS Animations
} // NS OpenEngine


#endif // _OE_ANIMATION_CONTROLLER_H_
