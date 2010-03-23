// Keyframe class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_KEY_FRAME_H_
#define _OE_KEY_FRAME_H_

#include <Utils/Timer.h>

#include <vector>

namespace OpenEngine {
namespace Animations {

    using Utils::Time;
    using std::vector;

/**
 * KeyFrame class.
 *
 * A key frame is a series of target-value pairs together with a time
 * variable. The semantics are that each value has to be applied to
 * its corresponding target when a specific time is reached.
 *
 * @class KeyFrame KeyFrame.h Animations/KeyFrame.h
 */
template <class T>
class KeyFrame {
private:
    class TargetValuePair {
    public:
        T *target, value;
        TargetValuePair(T* target, T value): target(target), value(value) {}
        virtual ~TargetValuePair() {}
    };

    Time time;
    vector< TargetValuePair > transformations; 
public:
    typedef typename vector< TargetValuePair >::iterator iterator;

    explicit KeyFrame() {}
    KeyFrame(Time time): time(time) {}
    virtual ~KeyFrame() {}

    Time GetTime() {
        return time;
    }
    
    void AddTransformation(T* target, T value) {
        transformations.push_back(TargetValuePair(target, value));
    }

    void Clear() {
        transformations.clear();
    }

    typename vector< TargetValuePair >::iterator begin() {
        return transformations.begin();
    }

    typename vector< TargetValuePair >::iterator end() {
        return transformations.end();
    }

};


} // NS Animations
} // NS OpenEngine

#endif // _OE_KEY_FRAME_H_
