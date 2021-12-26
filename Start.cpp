#include <allegro.h>
#include "people_work.h"
//#include "Even_Speak.h"
#include "Even_Speak_01.h"

int Start(int *X, int *Y, int *last, int *OUT)
{
	int i = 0,j = 0;//計數器
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	BITMAP *background = load_bitmap ("image\\CO1\\c014f.bmp",NULL);//工院四樓
	BITMAP *Not = load_bitmap ("image\\CO1\\c014fRED.bmp",NULL);//障礙物
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);
	blit (background, butter, background->w - SCREEN_W, PeopleH*2, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	for(i = 0;i <= 10000;i++)
	{
		for(j = 0;j <= 10000;j++){}
//		rest(50);
	}
	*X = 32 * 24 + 16;
	*Y = 32 * 9 + 16;
	*last = 1;
	blit (background, butter, background->w - SCREEN_W, PeopleH*2, 0, 0, SCREEN_W, SCREEN_H);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(0), 32 * 17, 32 * 7, PeopleW, PeopleH);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Even_Start01();

/*	for(i = 0;i <= 10000;i++)
	{
		for(j = 0;j <= 10000;j++){}
//		rest(50);
	}*/
	for(*X = 32 * 24 + 16; *X >= 32 * 19 +16; *X = *X - 32)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
	//	if (*Y >= 32*9 +16 )
	//	{*Y = *Y - 32;}
		rest(50);
//		if (key[KEY_ESC])
//		{Menu(*X,*Y,*last,*OUT,4,6);}
	}

	blit (background, butter, background->w - SCREEN_W, PeopleH*2, 0, 0, SCREEN_W, SCREEN_H);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(3), 32 * 12, 32 * 7, PeopleW, PeopleH);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Even_Start02();

	*last = 1;
	for(*X = 32 * 19 + 16; *X >= 32 * 2 +16; *X = *X - 32)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		rest(50);
	}

	*last = 3;
	for(*Y = 32 * 9 + 16; *Y >= 32 * 2 +16; *Y = *Y - 32)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		rest(50);
	}

	destroy_bitmap (character);
	destroy_bitmap (background);
	destroy_bitmap (Not);

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

			return 100;//END
}