#pragma once

#include <SFML/Graphics.hpp>

struct AnimationComponent
{
	int num_frames_;
	int tick_counter_;
	int current_frame_;
	int ticks_per_frame_;
	int num_rows_;
	bool is_loop_;
	float speed_rate_;


	AnimationComponent(int num_frames = 0, int current_frame = 1, int ticks_per_frame = 100, bool is_loop = false, int tick_counter = 0, float speed_rate = 0, int num_rows = 4)
		: num_frames_(num_frames),
		  current_frame_(current_frame),
		  ticks_per_frame_(ticks_per_frame),
		  is_loop_(is_loop),
		  tick_counter_(tick_counter),
          speed_rate_(speed_rate),
	      num_rows_(num_rows)
	{
	}
};
