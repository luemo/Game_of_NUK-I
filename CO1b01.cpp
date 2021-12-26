#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int CO1b01(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
	BITMAP *background = load_bitmap ("image\\CO1\\c01b1f_all.bmp",NULL);//工院地下室
	BITMAP *Not = load_bitmap ("image\\CO1\\c01b1f_allRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character= load_bitmap ("image\\character\\CM.bmp",NULL);
	masked_blit (character, background, PeopleW*0, PeopleH*0, PeopleW*5, PeopleH*18, PeopleW, PeopleH);
	blit (Not2, Not, 0, 0, PeopleW*4, PeopleH*17, Not2->w, Not2->h);
//test//	blit (Not2, background, 0, 0, PeopleW*4, PeopleH*17, Not2->w, Not2->h);

	character =  load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)
		{
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
//			*X = 1216+16;
			*Y = 896+16;
			return 1;//一樓樓梯出口
		}
		if (key[KEY_SPACE] && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{
			if (*OUT < 2)
			{Even_CM01();}
			if (*OUT == 2)
			{
				*OUT = 3;
				Even_03();
			}
			if (*OUT > 2)
			{Even_CM02();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,5,1);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,5,1,Music);}
	}
}