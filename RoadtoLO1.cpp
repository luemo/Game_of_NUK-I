#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "College.h"
#include "system.h"

void RoadtoLO1_01(int *X, int *Y, int *last, int *map_number, int *OUT)
{
	int i = 0;//出來後改變

	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\CO2\\RoadtoL01.bmp",NULL);//理院
	BITMAP *Not = load_bitmap ("image\\CO2\\RoadtoL01RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	while (i != 1)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			
			stop_sample(Music_Work);
			destroy_sample (Music_Work);

			*map_number = 1;
			*X = 16;
			*Y = *Y - 32 * (30 - 3);
			LO2_MO1(X,Y,last,map_number,OUT);//法管院
			i = 1;
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,101,101);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,101,101,Music_Work);}
	}
}

void RoadtoLO1_02(int *X, int *Y, int *last, int *map_number, int *OUT)
{
	int i = 0;//出來後改變

	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\CO2\\RoadtoL01.bmp",NULL);//理院
	BITMAP *Not = load_bitmap ("image\\CO2\\RoadtoL01RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	while(i != 1)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if  (key[KEY_UP] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);

			stop_sample(Music_Work);
			destroy_sample (Music_Work);

			*map_number = 1;
//			*X = 16;
			*Y = 1728 -16;
//			*OUT = 0;
			CO2(X,Y,last,map_number,OUT);//理院
			i = 1;
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,102,102);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,102,102,Music_Work);}
	}
}

void RoadtoLO1_03(int *X, int *Y, int *last, int *map_number, int *OUT)
{
	int i = 0;//出來後改變

	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\CO2\\RoadtoL01.bmp",NULL);//理院
	BITMAP *Not = load_bitmap ("image\\CO2\\RoadtoL01RED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	while(i != 1)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if  (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 30 && Not->line[*Y][*X*3+2] == 30)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);

			stop_sample(Music_Work);
			destroy_sample (Music_Work);

			*map_number = 1;
			*X = 1728 - 16;
//			*Y = 160 - 16;
//			*OUT = 22;
			LO1(X,Y,last,map_number,OUT);//圖資
			i = 1;
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,103,103);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,103,103,Music_Work);}
	}
}