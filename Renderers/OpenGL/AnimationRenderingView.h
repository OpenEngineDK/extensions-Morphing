// Animation rendering view.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _ANIMATION_RENDERING_VIEW_H_
#define _ANIMATION_RENDERING_VIEW_H_

#include <Renderers/IRenderingView.h>

#include <stack>

namespace OpenEngine {
    namespace Scene {
        class AnimationNode;
        class TransformationNode;
    }
namespace Renderers {
namespace OpenGL {

using namespace OpenEngine::Scene;
using std::stack;

/**
 * Animation rendering view.
 */
class AnimationRenderingView : virtual public IRenderingView {
private:
    class JointVisitor: public ISceneNodeVisitor {
    private:
        stack<TransformationNode*> ts;
    public:
        JointVisitor() {}
        ~JointVisitor() {}
        void VisitTransformationNode(TransformationNode* node);
    };
    JointVisitor jointvisitor;
public:
    AnimationRenderingView(Viewport& viewport);
    virtual ~AnimationRenderingView();
    void VisitAnimationNode(AnimationNode* node);
};

} // NS OpenGL
} // NS Renderers
} // NS OpenEngine

#endif // _ACCELERATED_RENDERING_VIEW_H_
