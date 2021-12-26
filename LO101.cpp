#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO101(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO1\\L011f.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\LO1\\L011fRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;
	if (*OUT <= 23)
	{
		character= load_bitmap ("image\\ThingForAM.bmp",NULL);//應數事件物品
		masked_blit (character, background, 0, 0, PeopleW*8, PeopleH*2, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*7, PeopleH*2, PeopleW*2, PeopleH*1);
		blit (Not2, Not, PeopleW*1, PeopleH*2, PeopleW*8, PeopleH*3, PeopleW*1, PeopleH*1);
//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*7, PeopleH*2, PeopleW*2, PeopleH*1);
//		blit (Not2, background, PeopleW*1, PeopleH*2, PeopleW*8, PeopleH*3, PeopleW*1, PeopleH*1);
//		masked_blit (character, background, 0, 0, PeopleW*8, PeopleH*2, PeopleW, PeopleH);
	}
	if (*OUT <= 24)
	{
		character= load_bitmap ("image\\character\\AM.bmp",NULL);//應數
		masked_blit (character, background, PeopleW*1, PeopleH*3, PeopleW*9, PeopleH*23, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*8, PeopleH*23, PeopleW*2, PeopleH*1);
	//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*8, PeopleH*23, PeopleW*2, PeopleH*1);
//		masked_blit (character, background, PeopleW*1, PeopleH*3, PeopleW*9, PeopleH*23, PeopleW, PeopleH);
	}
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if  (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 864 - 16;
			*Y = *Y + 32 * 6;
			return 2;//圖資二樓
		}
		if (key[KEY_SPACE] && *Y >= PeopleH*9 && (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20))//BGR
		{//與應數對話
			if (*OUT == 22)
			{
				*OUT = 23;
				Even_23();
			}
			if (*OUT > 22 && *OUT < 24)
			{Even_AM();}
			if (*OUT == 24)
			{
			*OUT = 25;
			Even_25();
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 1;//與應數對話
			}
		}
		if (*OUT == 23 && key[KEY_SPACE] && *Y <= PeopleH*9 &&  ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{
			*OUT = 24;
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 1;//拿應數事件物品
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,6);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,6,Music);}
	}
}