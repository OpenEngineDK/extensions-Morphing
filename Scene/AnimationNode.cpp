// Animation node.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Scene/AnimationNode.h>

#include <Animations/Skeleton.h>

namespace OpenEngine {
namespace Scene {

    AnimationNode::AnimationNode(Skeleton* skeleton): skeleton(skeleton) {
    
    }

    // AnimationNode::~AnimationNode() {
    // }
    
    Skeleton* AnimationNode::GetSkeleton() { 
        return skeleton; 
    } 

} // NS Scene
} // NS OpenEngine
