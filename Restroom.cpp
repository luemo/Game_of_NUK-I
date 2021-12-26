#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int Restroom(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\restroom.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\restroomRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character= load_bitmap ("image\\character\\CS.bmp",NULL);//資工
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*2, PeopleH*3, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*1, PeopleH*3, PeopleW*3, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*1, PeopleH*3, PeopleW*3, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*2, PeopleH*3, PeopleW, PeopleH);

	if (*OUT <= 14)
	{
		character= load_bitmap ("image\\ThingForCS.bmp",NULL);//資工事件物品
		masked_blit (character, background, 0, 0, PeopleW*15, PeopleH*8, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*14, PeopleH*8, PeopleW*2, PeopleH*2);
//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*14, PeopleH*8, PeopleW*2, PeopleH*2);
//		masked_blit (character, background, 0, 0, PeopleW*15, PeopleH*8, PeopleW, PeopleH);
	}

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32*4 - 16;
			*Y = *Y - 32 * (16 - 3);
			return 2;//LO2
		}
		if (key[KEY_SPACE] && *X <= PeopleH*6 && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{//與資工對話
			if (*OUT < 13)
			{Even_CS01();}
			if (*OUT == 13)
			{
				*OUT = 14;
				Even_14();
			}
			if (*OUT > 13 && *OUT < 15)
			{Even_CS02();}
			if (*OUT == 15)
			{
				*OUT = 16;
				Even_16();
			}
			if (*OUT > 15)
			{Even_CS03();}
		}
		if (*OUT == 14 && key[KEY_SPACE] && *X >= PeopleH*6 && ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{
			*OUT = 15;
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 6;//拿資工事件物品
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,6,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,6,4,Music);}
	}
}