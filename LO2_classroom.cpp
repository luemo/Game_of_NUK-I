#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO2_classroom(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\L02_classroom.bmp",NULL);//法院的教室
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\L02_classroomRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	if (*OUT <= 12)
	{	character= load_bitmap ("image\\character\\LAW.bmp",NULL);//法律
		masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*12, PeopleH*10, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*11, PeopleH*10, PeopleW*2, PeopleH*2);
//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*11, PeopleH*10, PeopleW*2, PeopleH*2);
//		masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*12, PeopleH*10, PeopleW, PeopleH);
	}

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (key[KEY_DOWN] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32 * 24 + 16;
			*Y = 32 * 5 + 16;
			return 2;//LO2
		}
		if (key[KEY_SPACE] && ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{//與法律對話
			if (*OUT == 12)
			{
				*OUT = 13;
				Even_13();
				destroy_bitmap (character);
				destroy_bitmap (background);
				destroy_bitmap (Not);
				destroy_bitmap (Not2);
				return 7;
			}
			else
			{Even_LAW();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,7,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,7,4,Music);}
	}
}