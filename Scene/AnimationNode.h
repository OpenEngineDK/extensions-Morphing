// Animation node.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_ANIMATION_NODE_H_
#define _OE_ANIMATION_NODE_H_

#include <Scene/ISceneNode.h>

namespace OpenEngine {
    namespace Animations {
        class Skeleton;
    }
namespace Scene {

using Animations::Skeleton;

/**
 * Animation node.
 * 
 * A node for representing an animatable object in the scene graph.
 * Basically this is just a container for the Animation class.
 *
 * @class AnimationNode AnimationNode.h Scene/AnimationNode.h
 */
class AnimationNode : public ISceneNode {
    OE_SCENE_NODE(AnimationNode, ISceneNode);
private:
    float tmp;
    Skeleton* skeleton;
public:
    AnimationNode() {}
    AnimationNode(Skeleton* skeleton);
    virtual ~AnimationNode() {};
    
    Skeleton* GetSkeleton();
};

} // NS Scene
} // NS OpenEngine

#endif // _OE_ANIMATION_NODE_H_
