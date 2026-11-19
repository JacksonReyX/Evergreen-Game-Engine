-- Define the level
Level = {

    ----------------------------------------------------
    -- Window configuration
    ----------------------------------------------------
    window = {
        width = 800,
        height = 600
    },


    ----------------------------------------------------
    -- Assets
    ----------------------------------------------------
    assets = {
        [0] =
        {
            type = "texture",
            id = "mario-image",
            file = "Assets/Images/mario.png"
        },

        {
            type = "texture",
            id = "chopper-image",
            file = "Assets/Images/chopper.png"
        },

        {
            type = "texture",
            id = "chopper-sprite",
            file = "Assets/Images/chopper-spritesheet.png"
        },

        {
            type = "texture",
            id = "luigi-image",
            file = "Assets/Images/luigi.png"
        },

        {
            type = "texture",
            id = "radar-image",
            file = "Assets/Images/radar.png"
        },

        {
            type = "texture",
            id = "tilemap-image",
            file = "Assets/Tilemaps/jungle.png"
        },

        {
            type = "texture",
            id = "bullet-image",
            file = "Assets/Images/bullet.png"
        },
        { type = "font"   , id = "pico8-font-5",    file = "./assets/fonts/pico8.ttf"},
        { type = "font"   , id = "charriot-font",   file = "./assets/fonts/charriot.ttf"}
    },


    ----------------------------------------------------
    -- Tilemap
    ----------------------------------------------------
    tilemap = {
        map_file = "Assets/Tilemaps/jungle.map",
        texture_asset_id = "tilemap-image",

        num_rows = 20,
        num_cols = 25,

        tile_size = 32,
        scale = 2.0
    },


    ----------------------------------------------------
    -- Entities
    ----------------------------------------------------
    entities = {

        ------------------------------------------------
        -- Chopper 10 10 0 0 0 0 0 50 50
        ------------------------------------------------
        [0] =
        {
            tag = "player",

            components = {

                transform = {
                    position = {
                        x = 10,
                        y = 10
                    }
                },

                rigidbody = {
                    velocity = {
                        x = 0,
                        y = 0
                    },

                    is_static = false,
                    mass = 1.0,
                    bounce = 0.5
                },

                sprite = {
                    -- Size it is drawn at
                    width = 50,
                    height = 50,

                    texture_asset_id = "chopper-sprite",

                    -- Frame picked out of the texture
                    source_width = 32,
                    source_height = 32,

                    src_rect_x = 0,
                    src_rect_y = 0,

                    fixed = false
                },

                animation = {
                    num_frames = 2,
                    start_frame = 1,
                    speed_rate = 10,
                    loop = true
                },

                boxcollider = {
                    width = 50,
                    height = 50
                },

                keyboard_controller = {

                    up_velocity = {
                        x = 0,
                        y = -40
                    },

                    right_velocity = {
                        x = 40,
                        y = 0
                    },

                    down_velocity = {
                        x = 0,
                        y = 40
                    },

                    left_velocity = {
                        x = -40,
                        y = 0
                    }
                },

                camera_follow = {
                    follow = true
                },

                projectile_emitter = {

                    projectile_velocity = {
                        x = 250,
                        y = 150
                    },

                    repeat_frequency = 0,
                    projectile_duration = 10,

                    hit_percentage_damage = 0,

                    friendly = true
                },

                health = {
                    health_percentage = 100
                }
            }
        },


        ------------------------------------------------
        -- Circle
        -- Circle 200 200 2 4 0 0 255 100
        ------------------------------------------------
        {
            tag = "enemies",

            components = {

                transform = {
                    position = {
                        x = 200,
                        y = 200
                    }
                },

                rigidbody = {
                    velocity = {
                        x = 2,
                        y = 4
                    },

                    is_static = false,
                    mass = 1.0,
                    bounce = 0.5
                },

                shape = {
                    type = "circle",

                    width = 100,
                    height = 100,

                    color = {
                        r = 0,
                        g = 0,
                        b = 255,
                        a = 255
                    }
                },

                boxcollider = {
                    width = 100,
                    height = 100
                },

                health = {
                    health_percentage = 100
                }
            }
        },


        ------------------------------------------------
        -- UI
        -- UI 74 20 0 0 0 0 0 50 50
        ------------------------------------------------
        {
            components = {

                transform = {
                    -- Old code:
                    -- game.window_width_ - x
                    --
                    -- 800 - 74 = 726

                    position = {
                        x = 726,
                        y = 20
                    }
                },

                rigidbody = {
                    velocity = {
                        x = 0,
                        y = 0
                    },

                    is_static = true,
                    mass = 0,
                    bounce = 0
                },

                sprite = {
                    -- Size it is drawn at
                    width = 50,
                    height = 50,

                    texture_asset_id = "radar-image",

                    -- Frame picked out of the texture
                    source_width = 64,
                    source_height = 64,

                    src_rect_x = 0,
                    src_rect_y = 0,

                    fixed = true
                },

                animation = {
                    num_frames = 8,
                    start_frame = 1,
                    speed_rate = 5,
                    loop = true
                },

                boxcollider = {
                    width = 50,
                    height = 50
                }
            }
        },


        ------------------------------------------------
        -- Rectangle
        -- Rectangle 100 50 0 0 255 0 0 25 25 0 1
        ------------------------------------------------
        {
            components = {

                transform = {
                    position = {
                        x = 100,
                        y = 50
                    }
                },

                rigidbody = {
                    velocity = {
                        x = 0,
                        y = 0
                    },

                    is_static = false,
                    mass = 1.0,
                    bounce = 0.5
                },

                shape = {
                    type = "rectangle",

                    width = 25,
                    height = 25,

                    color = {
                        r = 255,
                        g = 0,
                        b = 0,
                        a = 255
                    }
                },

                boxcollider = {
                    width = 25,
                    height = 25
                },

                projectile_emitter = {

                    projectile_velocity = {
                        x = 100,
                        y = 0
                    },

                    repeat_frequency = 2,
                    projectile_duration = 3,

                    hit_percentage_damage = 20,

                    friendly = false
                }
            }
        }
    }
}