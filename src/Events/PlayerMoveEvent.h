#pragma once
#include "../EventBus/Event.h"
#import "raylib.h"
#include "raylib-cpp.hpp"
#include <SFML/Window.hpp>


class PlayerMoveEvent : public Event {
public:


    int pressed_key_;

    PlayerMoveEvent(int pressed_key) : pressed_key_(pressed_key) {}
};

