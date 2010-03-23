// Animation class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_ANIMATION_H_
#define _OE_ANIMATION_H_

#include <Animations/KeyFrame.h>
#include <Animations/AnimationController.h>
#include <Scene/TransformationNode.h>
#include <Utils/Timer.h>

#include <boost/shared_ptr.hpp>

#include <vector>
#include <map>

namespace OpenEngine {
namespace Animations {

    using Scene::TransformationNode;
    using Core::IListener;

    using std::vector;
    using std::map;

/**
 * Animation class.
 * 
 *
 * @class Animation Animation.h Animations/Animation.h
 */
class Animation : public IListener<AnimationEventArg> {
private:
    Time time;
    vector< KeyFrame< TransformationNode > > frames;
    vector< KeyFrame< TransformationNode > >::iterator first, last;
    map<TransformationNode*, TransformationNode> state;
public:

    Animation();
    virtual ~Animation();

    void AddKeyFrame(KeyFrame<TransformationNode> frame);
    void Handle(AnimationEventArg e); 
};

typedef boost::shared_ptr<Animation> AnimationPtr;


} // NS Scene
} // NS OpenEngine

#endif // _OE_ANIMATION_H_
