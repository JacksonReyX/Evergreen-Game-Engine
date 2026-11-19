//
// Created by Jackson Reynolds on 10/21/26.
//

#pragma once
struct MoveableComponent
{
    int speed_;
    bool right_;
    bool left_;
    bool down_;
    bool up_;
    bool player_moving_;
    int direction_;


    MoveableComponent(
        int speed = 2
        )
    : speed_(speed), right_(false), left_(false), down_(false), up_(false)
    {

    }
};
