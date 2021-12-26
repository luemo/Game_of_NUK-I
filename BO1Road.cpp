#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"

int BO1Road(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\BO1\\road_all.bmp",NULL);//工院和綜合間的道路
	BITMAP *Not = load_bitmap ("image\\BO1\\road_allRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);


	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if  (key[KEY_DOWN] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 0 && Not->line[*Y][*X*3+2] == 0)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*Y = 16;
			return 2;//綜合
		}
		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,2);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,2,Music);}
	}
}