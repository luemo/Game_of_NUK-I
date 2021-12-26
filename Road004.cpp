#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int Road004(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\Road\\road004.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\Road\\road004RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character= load_bitmap ("image\\character\\LS.bmp",NULL);//生科
	masked_blit (character, background, PeopleW*0, PeopleH*3, PeopleW*19, PeopleH*2, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*1, PeopleH*1, PeopleW*19, PeopleH*2, PeopleW, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*1, PeopleH*1, PeopleW*19, PeopleH*2, PeopleW, PeopleH*2);
//	masked_blit (character, background, PeopleW*0, PeopleH*3, PeopleW*19, PeopleH*2, PeopleW, PeopleH);

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (key[KEY_LEFT] &&  Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 864 - 16;
			return 3;//Road003
		}

		if (key[KEY_SPACE] &&  (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30))//BGR
		{//與生科對話
			if (*OUT == 8)
			{
				*OUT = 9;
				Even_09();
			}
			if (*OUT > 8 && *OUT < 10)
			{Even_LS01();}
			if (*OUT == 10)
			{
				*OUT = 11;
				Even_11();
			}
			if (*OUT > 10)
			{Even_LS02();}
		}
		
		if (*OUT == 11 && *X >= (background->w) - PeopleW/2)
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 100;
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,4,3);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,4,3,Music);}
	}
}