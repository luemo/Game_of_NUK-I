#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int Road003(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\Road\\road003.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\Road\\road003RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	if (*OUT <=9)
	{
		character= load_bitmap ("image\\ThingForLS.bmp",NULL);//生科事件物品
		masked_blit (character, background, 0, 0, PeopleW*24, PeopleH*2, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*23, PeopleH*2, PeopleW*2, PeopleH*2);
//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*23, PeopleH*2, PeopleW*2, PeopleH*2);
//		masked_blit (character, background, 0, 0, PeopleW*24, PeopleH*2, PeopleW, PeopleH);
	}

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (key[KEY_UP] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*Y = 864 -16;
			return 2;//Road002
		}
		if  (key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			return 4;//Road004
		}

		if (key[KEY_SPACE] &&  ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{
			if (*OUT < 9)
			{Even_Chicken();}
			if (*OUT == 9)
			{
				*OUT = 10;
				Even_10();
				destroy_bitmap (character);
				destroy_bitmap (background);
				destroy_bitmap (Not);
				destroy_bitmap (Not2);
				return 3;//拿生科事件物品
			}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,3,3);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,3,3,Music);}
	}
}