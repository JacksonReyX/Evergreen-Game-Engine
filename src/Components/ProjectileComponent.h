#pragma once

struct ProjectileComponent {
    bool is_friendly_;
    int hit_percent_damage_;
    float duration_;
    float elapsed_time_;

    ProjectileComponent(bool is_friendly = false, int hit_percent_damage = 0, int duration = 0) 
        : is_friendly_(is_friendly),
        hit_percent_damage_(hit_percent_damage),
        duration_(duration),
        elapsed_time_(0.0f)
    {
    }
};
