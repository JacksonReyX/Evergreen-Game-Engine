#pragma once
struct ColorComponent
{
	int r_, g_, b_;

	ColorComponent(int r = 0, int g = 0, int b = 0)
		: r_(r),
		  b_(b),
		  g_(g)
	{
	}
};