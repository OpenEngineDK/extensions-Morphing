// Skeleton class.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_SKELETON_H_
#define _OE_SKELETON_H_

namespace OpenEngine {
    namespace Scene {
        class ISceneNode;
        class SceneNode;
        class TransformationNode;
    }

namespace Animations {

    using Scene::ISceneNode;
    using Scene::SceneNode;
    using Scene::TransformationNode;

/**
 * Skeleton class.
 * 
 * 
 *
 * @class Skeleton Skeleton.h Animations/Skeleton.h
 */
class Skeleton {
private:
    SceneNode* joints; 
public:

    Skeleton();
    virtual ~Skeleton();
    
    void AddJoints(TransformationNode* joints);
    ISceneNode* GetJoints();
};

} // NS Animations
} // NS OpenEngine

#endif // _OE_ANIMATION_CLIP_H_
