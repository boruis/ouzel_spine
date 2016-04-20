// Copyright (C) 2015 Elviss Strazdins

#pragma once

#include <ouzel.h>
#include <spine/spine.h>
#include <spine/extension.h>

#ifndef SPINE_MESH_VERTEX_COUNT_MAX
#define SPINE_MESH_VERTEX_COUNT_MAX 1000
#endif

namespace spine
{
    class SkeletonNode: public ouzel::scene::Node
    {
    public:
        SkeletonNode(const std::string& atlasFile, const std::string& skeletonFile);
        ~SkeletonNode();

        void update(float delta);
        virtual void draw() override;

        float getTimeScale() const { return _timeScale; }
        void setTimeScale(float timeScale) { _timeScale = timeScale; }

        void setAnimation(int trackIndex, const std::string& animationName, bool loop);
        void addAnimation(int trackIndex, const std::string& animationName, bool loop, float delay);

        void setAnimationMix(const std::string& from, const std::string& to, float duration);

        spSkeleton* getSkeleton() const { return _skeleton; }
        spAtlas* getAtlas() const { return _atlas; }
        spAnimationState* getState() const { return _state; }
        
    private:
        spSkeleton* _skeleton = nullptr;
        spAtlas* _atlas = nullptr;
        spAnimationState* _state = nullptr;
        spAnimationStateData* _stateData = nullptr;

        float _timeScale = 1.0f;
        ouzel::video::MeshBufferPtr _meshBuffer;

        float _worldVertices[SPINE_MESH_VERTEX_COUNT_MAX / sizeof(float)];
        
        ouzel::video::ShaderPtr _shader;
        ouzel::video::BlendStatePtr _blendState;

        ouzel::UpdateCallbackPtr _updateCallback;
    };
}