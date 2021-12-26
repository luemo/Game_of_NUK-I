#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO2toMO1road(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\L02toM01road.bmp",NULL);//法管院間的道路
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\L02toM01roadRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character= load_bitmap ("image\\character\\FIM.bmp",NULL);//金管
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*13, PeopleH*17, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*12, PeopleH*17, PeopleW*3, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*12, PeopleH*17, PeopleW*3, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*13, PeopleH*17, PeopleW, PeopleH);


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
			*X = 1728 - 16;
			//*Y = *Y;
			return 2;//LO2
		}
		if  (*OUT >= 18 && key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			//*Y = *Y;
			return 4;//MO1
		}
		if  (*OUT >= 20 && key[KEY_UP] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 30 && Not->line[*Y][*X*3+2] == 30)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = *X + 32 * 54;
			*Y = 864 - 16;
			return 5;//RoadUP
		}
		if (key[KEY_SPACE] && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{//與金管對話
			if (*OUT == 17)
			{
				*OUT = 18;
				Even_18();
			}
			if (*OUT > 17 && *OUT < 19)
			{Even_FIN01();}
			if (*OUT == 19)
			{
				*OUT = 20;
				Even_20();
			}
			if (*OUT > 19)
			{Even_FIN02();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,3,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,3,4,Music);}
	}
}