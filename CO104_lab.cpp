#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int CO104_lab(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
	BITMAP *background = load_bitmap ("image\\CO1\\c014flab.bmp",NULL);//工院老師辦公室
	BITMAP *Not = load_bitmap ("image\\CO1\\c014flabRED.bmp",NULL);//障礙物
	BITMAP *character;

	character =  load_bitmap ("image\\character\\EE.bmp",NULL);
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *butter2 = create_bitmap (SCREEN_W, SCREEN_H);

//	blit (background, butter, 0, 0, SCREEN_W/2 - background->w/2-16, SCREEN_H/2 - background->h/2, background->w, background->h);
//	blit (Not, butter2, 0, 0, SCREEN_W/2 - background->w/2-16, SCREEN_H/2 - background->h/2, background->w, background->h);
	blit (background, butter, 0, 0, 0, 0, background->w, background->h);
	blit (Not, butter2, 0, 0, 0, 0, background->w, background->h);

	for(;;)
	{
		walking (X, Y, last, character, butter, butter2);//3上0下1左2右
		if (key[KEY_DOWN] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)
		{
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (butter);
			destroy_bitmap (butter2);
			*X = 608+16;
			*Y = 288+16;
			return 2;//四樓教室出口
		}
		if (*last == 3 && key[KEY_SPACE] && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10)
		{
			if (*OUT < 3)
			{Even_Wu01();}
			if (*OUT == 3)
			{
				*OUT = 4;
				Even_04();
			}
			if (*OUT > 3)
			{Even_Wu02();}
		}
		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,3,1);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,3,1,Music);}
	}
}