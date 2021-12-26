#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO2(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\L02.bmp",NULL);//法院
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\L02RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character= load_bitmap ("image\\character\\GL.bmp",NULL);//政法
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*11, PeopleH*14, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*1, PeopleH*0, PeopleW*11, PeopleH*13, PeopleW*1, PeopleH*3);
//test//
//	blit (Not2, background, PeopleW*1, PeopleH*0, PeopleW*11, PeopleH*13, PeopleW*1, PeopleH*3);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*11, PeopleH*14, PeopleW, PeopleH);

	character= load_bitmap ("image\\character\\EFL.bmp",NULL);//財法
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*52, PeopleH*19, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*19, PeopleW*1, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*19, PeopleW, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*52, PeopleH*19, PeopleW, PeopleH);

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (*OUT >= 17 && key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32 * 5 + 16;
			//*Y = *Y;
			return 3;//L02toM01road
		}
		if  (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32 * 24 - 16;
			*Y = *Y + 32 * (32 - 5);
			return 1;//L02road
		}
		if  (key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 30 && Not->line[*Y][*X*3+2] == 30)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			*Y = *Y + 32 * (16 - 3);
			return 6;//法院廁所
		}
		if  (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 40 && Not->line[*Y][*X*3+2] == 40)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32 * 13 + 16;
			*Y = 32 * 24 - 16;
			return 7;//法院教室
		}
		if (key[KEY_SPACE] && *X <= PeopleW*23 && ((*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//與政法對話
			if (*OUT == 11)
			{
				*OUT = 12;
				Even_12();
			}
			if (*OUT > 11)
			{Even_GL();}
		}
		if (key[KEY_SPACE] && *X >= PeopleW*23 && (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30))//BGR
		{//與財法對話
			if (*OUT < 16)
			{Even_FEL01();}
			if (*OUT == 16)
			{
				*OUT = 17;
				Even_17();
			}
			if (*OUT > 16)
			{Even_FEL02();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,2,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,2,4,Music);}
	}
}