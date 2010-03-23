
ADD_LIBRARY(Extensions_Animations
  Scene/AnimationNode.h
  Scene/AnimationNode.cpp
  Animations/AnimationClip.h
  Animations/AnimationClip.cpp
  Animations/AnimationController.h
  Animations/AnimationController.cpp
  Animations/Animation.h
  Animations/Animation.cpp
  Animations/KeyFrame.h
  Animations/Skeleton.h
  Animations/Skeleton.cpp

  Renderers/OpenGL/AnimationRenderingView.h
  Renderers/OpenGL/AnimationRenderingView.cpp
)

TARGET_LINK_LIBRARIES(Extensions_Animations
  OpenEngine_Renderers
  OpenEngine_Scene
)
