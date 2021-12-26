#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int BO101(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\BO1\\B011f.bmp",NULL);//綜合一樓
	BITMAP *Not = load_bitmap ("image\\BO1\\B011fRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

 	character= load_bitmap ("image\\character\\TCCD.bmp",NULL);//傳創
	masked_blit (character, background, PeopleW*0, PeopleH*0, PeopleW*12, PeopleH*9, PeopleW, PeopleH);
	blit (Not2, Not, 0, 0, PeopleW*11, PeopleH*8, Not2->w, Not2->h);
//test//
//	blit (Not2, background, 0, 0, PeopleW*11, PeopleW*8, Not2->w, Not2->h);
//	masked_blit (character, background, PeopleW*0, PeopleH*0, PeopleW*12, PeopleH*9, PeopleW, PeopleH);

	character= load_bitmap ("image\\character\\EL.bmp",NULL);//東語
	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*3, PeopleH*39, PeopleW, PeopleH);
	blit (Not2, Not, 0, 0, PeopleW*2, PeopleH*38, PeopleW*2, PeopleH*3);
//test//
//	blit (Not2, background, 0, 0, PeopleW*2, PeopleH*38, PeopleW*2, PeopleH*3);
//	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*3, PeopleH*39, PeopleW, PeopleH);

	character= load_bitmap ("image\\character\\DKHL.bmp",NULL);//運健休
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*3, PeopleH*78, PeopleW, PeopleH);
	blit (Not2, Not, 0, 0, PeopleW*2, PeopleH*77, PeopleW*2, PeopleH*2);
//test//
//	blit (Not2, background, 0, 0, PeopleW*2, PeopleH*77, PeopleW*2, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*3, PeopleH*78, PeopleW, PeopleH);



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
			*Y = 1728 - 16;
			return 1;//工院和綜合間的道路
		}

		if (key[KEY_SPACE] && (*Y >= PeopleH*15 && *Y <= PeopleH*57) &&  ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//與東語對話
			if (*OUT == 4)
			{
				*OUT = 5;
				Even_05();
			}
			if (*OUT > 4 && *OUT < 6)
			{Even_EL01();}
			if (*OUT == 6)
			{
			*OUT = 7;
			Even_07();
			}
			if (*OUT > 6)
			{Even_EL02();}
		}
		if (key[KEY_SPACE] && *Y <= PeopleH*15 &&  ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//與傳創對話
			if (*OUT == 5)
			{
				*OUT = 6;
				Even_06();
			}
			else
			{Even_TCCD();}
		}
		if (key[KEY_SPACE] && *Y >= PeopleH*57 &&  ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//與運修對話
			if (*OUT < 7)
			{Even_DKHL01();}
			if (*OUT == 7)
			{
				*OUT = 8;
				Even_08();
			}
			if (*OUT > 7)
			{Even_DKHL02();}
		}

		if  (*OUT == 8 && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 100;//前往ROAD
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,2,2);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,2,2,Music);}
	}
}