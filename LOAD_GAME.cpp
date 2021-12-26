#include <allegro.h>
#include "Save.h"
#include "system.h"
#include "College.h"

void LOAD_GAME(int X, int Y, int last, int OUT, int Map, int College)
{
		if (College == 1)
		{
			CO1(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 2)
		{
			BO1(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 3)
		{
			Road(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 4)
		{
			LO2_MO1(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 5)
		{
			CO2(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 6)
		{
			LO1(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 101)
		{
			RoadtoLO1_01(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 102)
		{
			RoadtoLO1_02(&X, &Y, &last, &Map, &OUT);
		}
		if (College == 103)
		{
			RoadtoLO1_03(&X, &Y, &last, &Map, &OUT);
		}
}