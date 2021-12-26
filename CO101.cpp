#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"
//#include "Cfont.h"

int CO101(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\CO1\\c011f_all.bmp",NULL);//工院一樓
	BITMAP *Not = load_bitmap ("image\\CO1\\c011f_allRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	if (*OUT == 0)
	{
 	character= load_bitmap ("image\\character\\WL.bmp",NULL);
		
	masked_blit (character, background, PeopleW*0, PeopleH*2, PeopleW*0, PeopleH*3, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*1, PeopleH*1, PeopleW*0, PeopleH*3, PeopleW*2, PeopleH*2);
//test//	blit (Not2, background, PeopleW*1, PeopleH*1, PeopleW*0, PeopleW*3, PeopleW*2, PeopleH*2);
	}

	character= load_bitmap ("image\\character\\CEE.bmp",NULL);
	masked_blit (character, background, PeopleW*0, PeopleH*0, PeopleW*25, PeopleH*20, PeopleW, PeopleH);
	blit (Not2, Not, 0, 0, PeopleW*24, PeopleH*19, Not2->w, Not2->h);
//test//	blit (Not2, background, 0, 0, PeopleW*24, PeopleH*19, Not2->w, Not2->h);

	character = load_bitmap ("image\\character\\EE.bmp",NULL);


	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*Y = 32*3+16;
			*last = 0;
			return 2;//四樓電梯出口
		}
		if  (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
//			*X = 1216+16;
			*Y = 768-16;
			return 5;//地下室樓梯
		}
		if (*OUT == 0 && key[KEY_SPACE] && *Y <= 288 && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{//與西語對話
			*OUT = 1;
			Even_01();

			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 1;
		}
		if (key[KEY_SPACE] && *Y >= 288 && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//與土環對話
			if (*OUT < 1)
			{Even_CEE01();}
			if (*OUT == 1)
			{
				*OUT = 2;
//				stop_sample(Music);
				Even_02(Music);
				play_sample( Music, 255, 0, 1000, 1);
			}
			if (*OUT > 1)
			{Even_CEE02();}
		}

		if (*OUT == 4 && *Y >= (background->h) - PeopleH/2)
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 100;
		}
		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,1);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,1,Music);}
	}
}