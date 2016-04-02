// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

class Application: public ouzel::Noncopyable, public ouzel::App
{
public:
    virtual ~Application();

    virtual void begin() override;

    bool handleKeyboard(const ouzel::KeyboardEventPtr& event, const ouzel::VoidPtr& sender) const;
    bool handleMouse(const ouzel::MouseEventPtr& event, const ouzel::VoidPtr& sender) const;
    bool handleTouch(const ouzel::TouchEventPtr& event, const ouzel::VoidPtr& sender) const;
    bool handleGamepad(const ouzel::GamepadEventPtr& event, const ouzel::VoidPtr& sender) const;
    bool handleUI(const ouzel::UIEventPtr& event, const ouzel::VoidPtr& sender) const;

protected:
    ouzel::scene::LayerPtr _layer;

    ouzel::EventHandlerPtr _eventHandler;
};
