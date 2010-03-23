// Animation class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Animations/Animation.h>

#include <Logging/Logger.h>

namespace OpenEngine {
namespace Animations {

    Animation::Animation()
        : first(frames.begin()) 
        , last(first)
    {
        
    }
    
    Animation::~Animation() {

    }

    void Animation::Handle(AnimationEventArg e) {
        time += e.time;
        // logger.info << time << logger.end;
        if (first == frames.end() || last == frames.end()) {
            first = last = frames.begin();
            return;
        }        
        KeyFrame<TransformationNode> f_frame = *first, l_frame = *last;
        if (time < f_frame.GetTime()) 
            return;
        while (time > l_frame.GetTime()) {
            KeyFrame<TransformationNode>::iterator i = l_frame.begin();
            for (; i != l_frame.end(); ++i) {
                state[(*i).target] = (*i).value;
            }
            first = last;
            if (++last != frames.end()) {
                f_frame = l_frame;
                l_frame = *last;
            }
            else {
                first = last = frames.begin();
                time = Time();
                // state.clear();
                return;
            }
        }
        // interpolate between first and last keyframe
        float scale = (float)(time - f_frame.GetTime()).AsInt() 
            / (l_frame.GetTime() - f_frame.GetTime()).AsInt(); 
        KeyFrame<TransformationNode>::iterator i = l_frame.begin();
        for (; i != l_frame.end(); ++i) {
            map<TransformationNode*,TransformationNode>::iterator j = state.find((*i).target);
            TransformationNode t;
            if (j != state.end())
                t = (*j).second;
            else {
                t = *(*i).target;
                state[(*i).target] = t;
            }
            (*i).target->SetPosition((t.GetPosition() + ((*i).value.GetPosition() - t.GetPosition()) * scale ));
        }
    }
    
    void Animation::AddKeyFrame(KeyFrame<TransformationNode> frame) {
        // @todo: assert that frame.time is greater than time of last frame in list.
        frames.push_back(frame);
        first = last = frames.begin();
    }


} // NS Animations
} // NS OpenEngine

