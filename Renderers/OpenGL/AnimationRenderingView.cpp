// Animation rendering view.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Renderers/OpenGL/AnimationRenderingView.h>

#include <Scene/AnimationNode.h>
#include <Scene/TransformationNode.h>
#include <Animations/Skeleton.h>
#include <Meta/OpenGL.h>

namespace OpenEngine {
namespace Renderers {
namespace OpenGL {

    using namespace Scene;
    using namespace Animations;

    AnimationRenderingView::AnimationRenderingView(Viewport& viewport)
        : IRenderingView(viewport) {
        
    }

    AnimationRenderingView::~AnimationRenderingView() {
        
    }
    
    void AnimationRenderingView::VisitAnimationNode(AnimationNode* node) {
        node->GetSkeleton()->GetJoints()->Accept(jointvisitor);
        node->VisitSubNodes(*this);
    }

    void AnimationRenderingView::JointVisitor::VisitTransformationNode(TransformationNode* node) {
        if (!ts.empty()) {
            TransformationNode* t = ts.top();
            float parent[3], child[3], squaref[4][3];
            Vector<3,float> square[4];
            t->GetPosition().ToArray(parent);
            node->GetPosition().ToArray(child);
            const float hs = 2.0;
            square[0] = t->GetPosition() + Vector<3,float>( hs, 0,  hs);  
            square[1] = t->GetPosition() + Vector<3,float>(-hs, 0,  hs);  
            square[2] = t->GetPosition() + Vector<3,float>(-hs, 0, -hs);  
            square[3] = t->GetPosition() + Vector<3,float>( hs, 0, -hs);  
            
            square[0].ToArray(squaref[0]);
            square[1].ToArray(squaref[1]);
            square[2].ToArray(squaref[2]);
            square[3].ToArray(squaref[3]);

            glBegin(GL_TRIANGLES); 
            glColor3f(1.0,1.0,1.0);

            glVertex3fv(child);
            glVertex3fv(squaref[0]);
            glVertex3fv(squaref[1]);

            glVertex3fv(child);
            glVertex3fv(squaref[1]);
            glVertex3fv(squaref[2]);

            glVertex3fv(child);
            glVertex3fv(squaref[2]);
            glVertex3fv(squaref[3]);

            glVertex3fv(child);
            glVertex3fv(squaref[3]);
            glVertex3fv(squaref[0]);
            glEnd();
            glBegin(GL_QUADS); 
            glVertex3fv(squaref[0]);
            glVertex3fv(squaref[1]);
            glVertex3fv(squaref[2]);
            glVertex3fv(squaref[3]);
            glEnd();
        }
        ts.push(node);
        node->VisitSubNodes(*this);
        ts.pop();
    }
    
} // NS OpenGL
} // NS Renderers
} // NS OpenEngine
