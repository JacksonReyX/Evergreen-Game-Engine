-- Define a table with the start values of the first level
Level = {
            ----------------------------------------------------
    -- Window configuration
    ----------------------------------------------------
    window = {
        width = 800,
        height = 600
    },
    ----------------------------------------------------
    -- Table to define the list of assets
    ----------------------------------------------------
    assets = {
        [0] =
        { type = "texture", id = "tilemap-texture",             file = "Assets/Tilemaps/jungle.png" },
        { type = "texture", id = "chopper-texture",             file = "Assets/Images/chopper-green-spritesheet.png" },
        { type = "texture", id = "su27-texture",                file = "Assets/Images/su27-spritesheet.png" },
        { type = "texture", id = "f22-texture",                 file = "Assets/Images/f22-spritesheet.png" },
        { type = "texture", id = "fw190-texture",               file = "Assets/Images/fw190-spritesheet.png" },
        { type = "texture", id = "upf7-texture",                file = "Assets/Images/upf7-spritesheet.png" },
        { type = "texture", id = "bf109-texture",               file = "Assets/Images/bf109-spritesheet.png" },
        { type = "texture", id = "bomber-texture",              file = "Assets/Images/bomber-spritesheet.png" },
        { type = "texture", id = "carrier-texture",             file = "Assets/Images/carrier.png" },
        { type = "texture", id = "boat-texture",                file = "Assets/Images/boat.png" },
        { type = "texture", id = "tank-tiger-up-texture",       file = "Assets/Images/tank-tiger-up.png" },
        { type = "texture", id = "tank-tiger-right-texture",    file = "Assets/Images/tank-tiger-right.png" },
        { type = "texture", id = "tank-tiger-down-texture",     file = "Assets/Images/tank-tiger-down.png" },
        { type = "texture", id = "tank-tiger-left-texture",     file = "Assets/Images/tank-tiger-left.png" },
        { type = "texture", id = "tank-tiger-killed-texture",   file = "Assets/Images/tank-tiger-killed.png" },
        { type = "texture", id = "tank-panther-up-texture",     file = "Assets/Images/tank-panther-up.png" },
        { type = "texture", id = "tank-panther-right-texture",  file = "Assets/Images/tank-panther-right.png" },
        { type = "texture", id = "tank-panther-down-texture",   file = "Assets/Images/tank-panther-down.png" },
        { type = "texture", id = "tank-panther-left-texture",   file = "Assets/Images/tank-panther-left.png" },
        { type = "texture", id = "tank-panther-killed-texture", file = "Assets/Images/tank-panther-killed.png" },
        { type = "texture", id = "truck-ford-up-texture",       file = "Assets/Images/truck-ford-up.png" },
        { type = "texture", id = "truck-ford-right-texture",    file = "Assets/Images/truck-ford-right.png" },
        { type = "texture", id = "truck-ford-down-texture",     file = "Assets/Images/truck-ford-down.png" },
        { type = "texture", id = "truck-ford-left-texture",     file = "Assets/Images/truck-ford-left.png" },
        { type = "texture", id = "truck-ford-killed-texture",   file = "Assets/Images/truck-ford-killed.png" },
        { type = "texture", id = "army-walk-up-texture",        file = "Assets/Images/army-walk-up.png" },
        { type = "texture", id = "army-walk-right-texture",     file = "Assets/Images/army-walk-right.png" },
        { type = "texture", id = "army-walk-down-texture",      file = "Assets/Images/army-walk-down.png" },
        { type = "texture", id = "army-walk-left-texture",      file = "Assets/Images/army-walk-left.png" },
        { type = "texture", id = "army-walk-killed-texture",    file = "Assets/Images/army-walk-killed.png" },
        { type = "texture", id = "army-gun-up-texture",         file = "Assets/Images/army-gun-up.png" },
        { type = "texture", id = "army-gun-right-texture",      file = "Assets/Images/army-gun-right.png" },
        { type = "texture", id = "army-gun-down-texture",       file = "Assets/Images/army-gun-down.png" },
        { type = "texture", id = "army-gun-left-texture",       file = "Assets/Images/army-gun-left.png" },
        { type = "texture", id = "army-gun-killed-texture",     file = "Assets/Images/army-gun-killed.png" },
        { type = "texture", id = "sam-truck-right-texture",     file = "Assets/Images/sam-truck-right.png" },
        { type = "texture", id = "sam-tank-left-texture",       file = "Assets/Images/sam-tank-left-spritesheet.png" },
        { type = "texture", id = "sam-tank-right-texture",      file = "Assets/Images/sam-tank-right-spritesheet.png" },
        { type = "texture", id = "takeoff-base-texture",        file = "Assets/Images/takeoff-base.png" },
        { type = "texture", id = "landing-base-texture",        file = "Assets/Images/landing-base.png" },
        { type = "texture", id = "runway-texture",              file = "Assets/Images/runway.png" },
        { type = "texture", id = "obstacles1-texture",          file = "Assets/Images/obstacles-1.png" },
        { type = "texture", id = "obstacles2-texture",          file = "Assets/Images/obstacles-2.png" },
        { type = "texture", id = "obstacles3-texture",          file = "Assets/Images/obstacles-3.png" },
        { type = "texture", id = "obstacles4-texture",          file = "Assets/Images/obstacles-4.png" },
        { type = "texture", id = "obstacles5-texture",          file = "Assets/Images/obstacles-5.png" },
        { type = "texture", id = "obstacles6-texture",          file = "Assets/Images/obstacles-6.png" },
        { type = "texture", id = "obstacles7-texture",          file = "Assets/Images/obstacles-7.png" },
        { type = "texture", id = "tree1-texture",               file = "Assets/Images/tree-1.png" },
        { type = "texture", id = "tree2-texture",               file = "Assets/Images/tree-2.png" },
        { type = "texture", id = "tree3-texture",               file = "Assets/Images/tree-3.png" },
        { type = "texture", id = "tree4-texture",               file = "Assets/Images/tree-4.png" },
        { type = "texture", id = "tree5-texture",               file = "Assets/Images/tree-5.png" },
        { type = "texture", id = "tree6-texture",               file = "Assets/Images/tree-6.png" },
        { type = "texture", id = "tree7-texture",               file = "Assets/Images/tree-7.png" },
        { type = "texture", id = "tree8-texture",               file = "Assets/Images/tree-8.png" },
        { type = "texture", id = "tree9-texture",               file = "Assets/Images/tree-9.png" },
        { type = "texture", id = "tree10-texture",              file = "Assets/Images/tree-10.png" },
        { type = "texture", id = "tree11-texture",              file = "Assets/Images/tree-11.png" },
        { type = "texture", id = "tree12-texture",              file = "Assets/Images/tree-12.png" },
        { type = "texture", id = "tree13-texture",              file = "Assets/Images/tree-13.png" },
        { type = "texture", id = "tree14-texture",              file = "Assets/Images/tree-14.png" },
        { type = "texture", id = "tree15-texture",              file = "Assets/Images/tree-15.png" },
        { type = "texture", id = "tree16-texture",              file = "Assets/Images/tree-16.png" },
        { type = "texture", id = "tree17-texture",              file = "Assets/Images/tree-17.png" },
        { type = "texture", id = "tree18-texture",              file = "Assets/Images/tree-18.png" },
        { type = "texture", id = "tree19-texture",              file = "Assets/Images/tree-19.png" },
        { type = "texture", id = "tree20-texture",              file = "Assets/Images/tree-20.png" },
        { type = "texture", id = "bullet-texture",              file = "Assets/Images/bullet.png" },
        { type = "texture", id = "radar-texture",               file = "Assets/Images/radar-spritesheet.png" },
        { type = "font"   , id = "pico8-font-5",    file = "Assets/Fonts/pico8.ttf"},
        { type = "font"   , id = "charriot-font",   file = "Assets/Fonts/charriot.ttf"}
    },

    ----------------------------------------------------
    -- table to define the map config variables
    ----------------------------------------------------
    tilemap = {
        map_file = "Assets/Tilemaps/jungle.map",
        texture_asset_id = "tilemap-texture",
        num_rows = 20,
        num_cols = 25,
        tile_size = 32,
        scale = 2.0
    },

    ----------------------------------------------------
    -- table to define entities and their components
    ----------------------------------------------------
    entities = {
        [0] =
        {
            -- Player
            tag = "player",
            components = {
                transform = {
                    position = { x = 234, y = 102 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                rigidbody = {
                    velocity = { x = 0.0, y = 0.0 }
                },
                sprite = {
                    texture_asset_id = "chopper-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 4,
                    fixed = false,
                    src_rect_x = 0,
                    src_rect_y = 0
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                },
                boxcollider = {
                    width = 48,
                    height = 37.5,
                    offset = { x = 0, y = 7.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 200, y = 200 },
                    projectile_duration = 10, -- seconds
                    repeat_frequency = 0, -- seconds
                    hit_percentage_damage = 10,
                    friendly = true
                },
                keyboard_controller = {
                    up_velocity = { x = 0, y = -50 },
                    right_velocity = { x = 50, y = 0 },
                    down_velocity = { x = 0, y = 50 },
                    left_velocity = { x = -50, y = 0 }
                },
                camera_follow = {
                    follow = true
                }
            }
        },
        {
            -- Takeoff base
            components = {
                transform = {
                    position = { x = 232, y = 105 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "takeoff-base-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                }
            }
        },
        {
            -- Landing base
            components = {
                transform = {
                    position = { x = 1388, y = 485 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "landing-base-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                }
            }
        },
        {
            -- Radar UI animation
            group = "ui",
            components = {
                transform = {
                    position = { x = 10, y = 10 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "radar-texture",
                    width = 64,
                    height = 64,
                    z_index = 10,
                    fixed = true
                },
                animation = {
                    num_frames = 8,
                    speed_rate = 7 -- fps
                }
            }
        },
        {
            -- Runway
            components = {
                transform = {
                    position = { x = 934.75, y = 17.25 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 270.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "runway-texture",
                    width = 31.5,
                    height = 286.5,
                    source_width = 21,
                    source_height = 191,
                    z_index = 1
                }
            }
        },
        {
            -- Runway
            components = {
                transform = {
                    position = { x = 464.75, y = 337.25 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "runway-texture",
                    width = 31.5,
                    height = 286.5,
                    source_width = 21,
                    source_height = 191,
                    z_index = 1
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 192, y = 489 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 0, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 100, y = 0 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 20,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 777, y = 162 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 27,
                    offset = { x = 10.5, y = 15 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -50 },
                    projectile_duration = 4, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 777, y = 242 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 30,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 20 },
                    projectile_duration = 3, -- seconds
                    repeat_frequency = 3, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 777, y = 342 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -50, y = 0 },
                    projectile_duration = 3, -- seconds
                    repeat_frequency = 3, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 562, y = 512 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 60, y = 0 },
                    projectile_duration = 4, -- seconds
                    repeat_frequency = 4, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 562, y = 592 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -60, y = 0 },
                    projectile_duration = 4, -- seconds
                    repeat_frequency = 4, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1042, y = 162 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 60, y = 0 },
                    projectile_duration = 4, -- seconds
                    repeat_frequency = 4, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1162, y = 108 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 27,
                    offset = { x = 12, y = 9 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 40 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1372, y = 108 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 27,
                    offset = { x = 12, y = 9 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 40 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1257, y = 232 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-killed-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1257, y = 282 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 30,
                    height = 25.5,
                    offset = { x = 10.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -40, y = 0 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 632, y = 792 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 27,
                    height = 30,
                    offset = { x = 10.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 100 },
                    projectile_duration = 5, -- seconds
                    repeat_frequency = 5, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 782, y = 737 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 10.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -60, y = 0 },
                    projectile_duration = 10, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 972, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 0, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 60, y = 0 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1062, y = 862 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 12, y = 6 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 100 },
                    projectile_duration = 4, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1182, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 10.5, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -200 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1202, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 10.5, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -200 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1222, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 10.5, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -200 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1242, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 10.5, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -200 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 992, y = 437 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 10.5, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -200 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1418, y = 752 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 33,
                    height = 27,
                    offset = { x = 7.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 200, y = 0 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1415, y = 827 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 27,
                    offset = { x = 10.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -200, y = 0 },
                    projectile_duration = 1, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1442, y = 292 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 28.5,
                    height = 30,
                    offset = { x = 9, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 300 },
                    projectile_duration = 1, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 187, y = 972 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-tiger-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 27,
                    height = 37.5,
                    offset = { x = 10.5, y = 10.5 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = -100 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 102, y = 1117 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 25.5,
                    height = 30,
                    offset = { x = 12, y = 6 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 0, y = 300 },
                    projectile_duration = 1, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 10,
                    friendly = false
                }
            }
        },
        {
            -- Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1387, y = 532 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tank-panther-killed-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 105, y = 572 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 172, y = 1037 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 187, y = 1047 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 202, y = 1057 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 537, y = 652 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 552, y = 662 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 37.5,
                    offset = { x = 15, y = 3 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1352, y = 872 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 30,
                    offset = { x = 15, y = 12 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1372, y = 872 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 30,
                    offset = { x = 15, y = 12 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1392, y = 872 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 18,
                    height = 30,
                    offset = { x = 15, y = 12 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1497, y = 772 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
                boxcollider = {
                    width = 37.5,
                    height = 24,
                    offset = { x = 4.5, y = 15 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1507, y = 782 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "truck-ford-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 37.5,
                    height = 24,
                    offset = { x = 4.5, y = 15 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- SAM Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 487, y = 372 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-tank-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 2 -- fps
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -50, y = -50 },
                    projectile_duration = 3, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 487, y = 402 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-tank-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 2 -- fps
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -50, y = -50 },
                    projectile_duration = 3, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1282, y = 107 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-tank-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 2 -- fps
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -100, y = -75 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Tank
            group = "enemies",
            components = {
                transform = {
                    position = { x = 927, y = 549 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-tank-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 2 -- fps
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = -100, y = -60 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 2, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 106, y = 692 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -50 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 106, y = 712 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -50 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 108, y = 491 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -70 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1446, y = 207 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -70 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1446, y = 223 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -70 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- SAM Truck
            group = "enemies",
            components = {
                transform = {
                    position = { x = 1446, y = 239 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "sam-truck-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
                boxcollider = {
                    width = 25.5,
                    height = 22.5,
                    offset = { x = 12, y = 12 }
                },
                health = {
                    health_percentage = 100
                },
                projectile_emitter = {
                    projectile_velocity = { x = 50, y = -70 },
                    projectile_duration = 2, -- seconds
                    repeat_frequency = 1, -- seconds
                    hit_percentage_damage = 5,
                    friendly = false
                }
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 107, y = 625 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree5-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 109, y = 642 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree5-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 310, y = 482 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree6-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 660, y = 518 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree14-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1013.75, y = 733 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree17-texture",
                    width = 25.5,
                    height = 30,
                    source_width = 17,
                    source_height = 20,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1029.75, y = 733 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree17-texture",
                    width = 25.5,
                    height = 30,
                    source_width = 17,
                    source_height = 20,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1023.75, y = 740 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree18-texture",
                    width = 25.5,
                    height = 30,
                    source_width = 17,
                    source_height = 20,
                    z_index = 2
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1382.25, y = 432 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree10-texture",
                    width = 46.5,
                    height = 48,
                    source_width = 31,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1392.25, y = 437 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree10-texture",
                    width = 46.5,
                    height = 48,
                    source_width = 31,
                    source_height = 32,
                    z_index = 2
                },
            }
        },
        {
            -- Vegetation
            components = {
                transform = {
                    position = { x = 1357, y = 282 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "tree14-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 665, y = 545 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 681, y = 545 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 311, y = 501 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 3
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 326, y = 503 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 434, y = 386 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 445, y = 404 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 427, y = 412 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 936, y = 691 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 951, y = 701 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1081, y = 503 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1071, y = 523 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1071, y = 543 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1081, y = 563 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1347, y = 441 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles2-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1422, y = 438 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles2-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1431, y = 191 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1421, y = 211 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1421, y = 231 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1421, y = 251 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1431, y = 271 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 2
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1356, y = 306 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1376, y = 308 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles7-texture",
                    width = 24,
                    height = 24,
                    source_width = 16,
                    source_height = 16,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1322, y = 204 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles1-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Obstacles
            components = {
                transform = {
                    position = { x = 1352, y = 224 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "obstacles1-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 622, y = 397 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 489, y = 442 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 564, y = 552 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 106, y = 972 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 106, y = 1022 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 875, y = 482 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 105, y = 843 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 742, y = 622 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-left-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 792, y = 622 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 848, y = 107 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 892, y = 107 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-up-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 1109, y = 522 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-right-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 747, y = 432 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 802, y = 432 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-gun-down-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 1382, y = 682 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-killed-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 1417, y = 682 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-killed-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Army
            components = {
                transform = {
                    position = { x = 1457, y = 682 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "army-walk-killed-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 1
                },
            }
        },
        {
            -- Boat
            components = {
                transform = {
                    position = { x = 74.75, y = 488.5 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "boat-texture",
                    width = 31.5,
                    height = 189,
                    source_width = 21,
                    source_height = 126,
                    z_index = 1
                },
            }
        },
        {
            -- Boat
            components = {
                transform = {
                    position = { x = 74.75, y = 758.5 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "boat-texture",
                    width = 31.5,
                    height = 189,
                    source_width = 21,
                    source_height = 126,
                    z_index = 1
                },
            }
        },
        {
            -- Boat
            components = {
                transform = {
                    position = { x = 339.75, y = 391.5 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 270.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "boat-texture",
                    width = 31.5,
                    height = 189,
                    source_width = 21,
                    source_height = 126,
                    z_index = 1
                },
            }
        },
        {
            -- Boat
            components = {
                transform = {
                    position = { x = 1504.75, y = 428.5 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "boat-texture",
                    width = 31.5,
                    height = 189,
                    source_width = 21,
                    source_height = 126,
                    z_index = 1
                },
            }
        },
        {
            -- Carrier
            components = {
                transform = {
                    position = { x = 655.25, y = 102.25 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "carrier-texture",
                    width = 88.5,
                    height = 286.5,
                    source_width = 59,
                    source_height = 191,
                    z_index = 1
                },
            }
        },
        {
            -- Carrier
            components = {
                transform = {
                    position = { x = 285.25, y = 927.25 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "carrier-texture",
                    width = 88.5,
                    height = 286.5,
                    source_width = 59,
                    source_height = 191,
                    z_index = 1
                },
            }
        },
        {
            -- F-22 fighter jet
            group = "enemies",
            components = {
                transform = {
                    position = { x = 680, y = 157 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "f22-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 4
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                },
                boxcollider = {
                    width = 30,
                    height = 37.5,
                    offset = { x = 7.5, y = 7.5 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- SU-27 fighter jet
            group = "enemies",
            components = {
                transform = {
                    position = { x = 677, y = 292 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = -10.0, -- degrees
                },
                rigidbody = {
                    velocity = { x = -5.5 , y = -35.0 }
                },
                sprite = {
                    texture_asset_id = "su27-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 5
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                },
                boxcollider = {
                    width = 37.5,
                    height = 45,
                    offset = { x = 7.5, y = 0 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- Bomber plane
            group = "enemies",
            components = {
                transform = {
                    position = { x = 456, y = 512 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "bomber-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 5
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                },
                boxcollider = {
                    width = 48,
                    height = 48,
                    offset = { x = 0, y = 0 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- FW190 plane
            group = "enemies",
            components = {
                transform = {
                    position = { x = 992, y = 135 },
                    scale = { x = 1.0, y = 1.0 },
                    rotation = -90.0, -- degrees
                },
                rigidbody = {
                    velocity = { x = -50.0, y = 0.0 }
                },
                sprite = {
                    texture_asset_id = "fw190-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 6
                },
                animation = {
                    num_frames = 3,
                    speed_rate = 15 -- fps
                },
                boxcollider = {
                    width = 48,
                    height = 45,
                    offset = { x = 0, y = 0 }
                },
                health = {
                    health_percentage = 100
                }
            }
        },
        {
            -- UPF7 plane
            group = "enemies",
            components = {
                transform = {
                    position = { x = 912, y = 171 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "upf7-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 5
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                }
            }
        },
        {
            -- UPF7 plane
            group = "enemies",
            components = {
                transform = {
                    position = { x = 942, y = 171 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "upf7-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 5
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                }
            }
        },
        {
            -- UPF7 plane
            group = "enemies",
            components = {
                transform = {
                    position = { x = 972, y = 171 },
                    scale = { x = 0.8, y = 0.8 },
                    rotation = 0.0, -- degrees
                },
                sprite = {
                    texture_asset_id = "upf7-texture",
                    width = 48,
                    height = 48,
                    source_width = 32,
                    source_height = 32,
                    z_index = 5
                },
                animation = {
                    num_frames = 2,
                    speed_rate = 10 -- fps
                }
            }
        },
    }
}

-- Define some useful global variables
map_width = Level.tilemap.num_cols * Level.tilemap.tile_size * Level.tilemap.scale
map_height = Level.tilemap.num_rows * Level.tilemap.tile_size * Level.tilemap.scale
