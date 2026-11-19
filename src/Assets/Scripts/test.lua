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
		{ type = "texture", id = "tilemap-texture",             file = "Assets/Tilemaps/grass.png" },
		{type = "texture", id = "bunny-guy", file = "Assets/Sprites/Characters/CharacterSheetWithIdle.png"},
		{type = "texture", id = "grass_biome", file = "Assets/Sprites/Objects/Basic_Grass_Biom_things 1.png"},
		{type = "texture", id = "chicken_coop", file = "Assets/Sprites/Objects/Free_Chicken_House.png"},
		{type = "texture", id = "egg_justegg", file = "Assets/Sprites/Objects/Egg_item.png"},
		{type = "texture", id = "cow", file = "Assets/Sprites/Characters/Cow.png"},
		{type = "texture", id = "chicken", file = "Assets/Sprites/Characters/Chicken.png"}
	},

	----------------------------------------------------
	-- table to define the map config variables
	----------------------------------------------------

	tilemap = {
		map_file = "Assets/Tilemaps/hubWorld.map",
		collider_map_file = "Assets/Collider_maps/hubWorldCollider.map",
		texture_asset_id = "tilemap-texture",
		num_rows = 50,
		num_cols = 50,
		tile_size = 16,
		scale = 1
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
					position = { x = 0, y = 0 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "bunny-guy",
					width = 48,
					height = 48,
					source_width = 48,
					source_height = 48,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				player = {
					speed = 80.0
				},

				animation = {
					num_frames = 4,
					num_rows = 5,
					loop = true,
					speed_rate = 0
				},

				boxcollider = {
					width = 20,
					height = 20,
					x = 14,
					y = 10
				}
			}
		},
		{
			-- Cow_1
			tag = "Cows",
			components = {
				transform = {
					position = { x = 300, y = 32 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "cow",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				animation = {
					num_frames = 4,
					num_rows = 2,
					loop = true,
					speed_rate = 0
				},

				boxcollider = {
					width = 32,
					height = 20,
					x = 0,
					y = 10
				}
			}
		},
		{
			-- Cow_2
			tag = "Cows",
			components = {
				transform = {
					position = { x = 170, y = 300 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "cow",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				animation = {
					num_frames = 4,
					num_rows = 2,
					loop = true,
					speed_rate = 0
				},

				boxcollider = {
					width = 32,
					height = 20,
					x = 0,
					y = 10
				}
			}
		},
		{
			-- Chicken
			group = "Chickens",
			components = {
				transform = {
					position = { x = 170, y = 335 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "chicken",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 16
				},

				animation = {
					num_frames = 4,
					num_rows = 2,
					loop = true,
					speed_rate = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			-- Chicken
			group = "Chickens",
			components = {
				transform = {
					position = { x = 186, y = 335 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "chicken",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				animation = {
					num_frames = 2,
					num_rows = 2,
					loop = true,
					speed_rate = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		------------------------------
		--trees and flora
		------------------------------
		{
			--tree_1
			group = "trees",
			components = {
				transform = {
					position = { x = 100, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 64,
					source_width = 16,
					source_height = 32,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 64,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_2
			group = "trees",
			components = {
				transform = {
					position = { x = 150, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 16,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_3
			group = "trees",
			components = {
				transform = {
					position = { x = 182, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 48,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_4
			group = "trees",
			components = {
				transform = {
					position = { x = 214, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 16,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_5
			group = "trees",
			components = {
				transform = {
					position = { x = 246, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 48,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_6
			group = "trees",
			components = {
				transform = {
					position = { x = 310, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 16,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_7
			group = "trees",
			components = {
				transform = {
					position = { x = 342, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 48,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_8
			group = "trees",
			components = {
				transform = {
					position = { x = 374, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 16,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--tree_8
			group = "trees",
			components = {
				transform = {
					position = { x = 406, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 32,
					height = 32,
					source_width = 32,
					source_height = 32,
					fixed = false,
					src_rect_x = 48,
					src_rect_y = 0
				},

				boxcollider = {
					width = 32,
					height = 32,
					x = 0,
					y = 0
				}
			}
		},
		{
			--bush_1
			components = {
				transform = {
					position = { x = 486, y = 100 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 64,
					height = 64,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 48
				},

				boxcollider = {
					width = 64,
					height = 64,
					x = 0,
					y = 0
				}
			}
		},
		{
			--mushroom_1
			components = {
				transform = {
					position = { x = 486, y = 200 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_2
			components = {
				transform = {
					position = { x = 470, y = 200 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_3
			components = {
				transform = {
					position = { x = 454, y = 200 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_4
			components = {
				transform = {
					position = { x = 438, y = 200 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_5
			components = {
				transform = {
					position = { x = 422, y = 200 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_6
			components = {
				transform = {
					position = { x = 486, y = 184 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_7
			components = {
				transform = {
					position = { x = 470, y = 184 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_8
			components = {
				transform = {
					position = { x = 454, y = 184 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_9
			components = {
				transform = {
					position = { x = 438, y = 184 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--mushroom_10
			components = {
				transform = {
					position = { x = 422, y = 184 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 0.0, -- degrees
				},

				sprite = {
					texture_asset_id = "grass_biome",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 80,
					src_rect_y = 0
				}
			}
		},
		{
			--coop
			components = {
				transform = {
					position = { x = 100, y = 300 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "chicken_coop",
					width = 48,
					height = 48,
					source_width = 48,
					source_height = 48,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 48,
					height = 48,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg
			components = {
				transform = {
					position = { x = 84, y = 300 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg_2
			components = {
				transform = {
					position = { x = 84, y = 316 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg_3
			components = {
				transform = {
					position = { x = 84, y = 332 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg_4
			components = {
				transform = {
					position = { x = 148, y = 300 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg_5
			components = {
				transform = {
					position = { x = 148, y = 316 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		},
		{
			--egg_6
			components = {
				transform = {
					position = { x = 148, y = 332 },
					scale = { x = 1.0, y = 1.0 },
					size = { x = 16, y = 16 },
					rotation = 90.0, -- degrees
				},

				sprite = {
					texture_asset_id = "egg_justegg",
					width = 16,
					height = 16,
					source_width = 16,
					source_height = 16,
					fixed = false,
					src_rect_x = 0,
					src_rect_y = 0
				},

				boxcollider = {
					width = 16,
					height = 16,
					x = 0,
					y = 0
				}
			}
		}




	}


}

-- Define some useful global variables
--map_width = Level.tilemap.num_cols * Level.tilemap.tile_size * Level.tilemap.scale
--map_height = Level.tilemap.num_rows * Level.tilemap.tile_size * Level.tilemap.scale
