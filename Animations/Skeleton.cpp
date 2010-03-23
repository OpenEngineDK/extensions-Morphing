// Skeleton class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Animations/Skeleton.h>

#include <Scene/SceneNode.h>
#include <Scene/TransformationNode.h>

namespace OpenEngine {
namespace Animations {

    using namespace Scene;

    Skeleton::Skeleton()
        : joints(new SceneNode())
    {

    }
    
    Skeleton::~Skeleton() {
        delete joints;
    }

    void Skeleton::AddJoints(TransformationNode* joints) {
        this->joints->AddNode(joints);
    }

    ISceneNode* Skeleton::GetJoints() {
        return joints;
    }


} // NS Animations
} // NS OpenEngine
