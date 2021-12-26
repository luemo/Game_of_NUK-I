#include <allegro.h>
#include <stdio.h>
#include "College.h"
#include "system.h"
#include "Save.h"

int Main_Menu()
{
	int Choose = 1;
	int College = 0;

	int map_number = 1;
	int OUT = 0;//事件發生數 + 出外可許:0~3 = 不可,4 = 可;//接綜合
	int X = 32+16,Y = 32*3+16,last = 0;
	SAMPLE *Music_Main;
	Music_Main = load_sample( "VOICE/02 - zero-project - 02 - Touch of serenity.wav"); 
	play_sample( Music_Main, 255, 0, 1000, 1);


	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *Menu_W = load_bitmap("image\\system\\NUK.bmp",NULL);
	BITMAP *Menu_R = load_bitmap("image\\system\\NUK02.bmp",NULL);
//	FILE *Check;
	

	blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (Menu_R, butter, 0, Main_menu, 0, Main_menu, SCREEN_W, Main_menu_choose);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	while (!key[KEY_SPACE])
	{
//		Check = fopen("Check01.txt","w");
		
		rest(100);
		if (key[KEY_UP])
		{
			Choose = Choose - 1;
			if (Choose < 1)
			{Choose = 1;}
		}
		if (key[KEY_DOWN])
		{
			Choose = Choose + 1;
			if (Choose > 3)
			{Choose = 3;}
		}

		blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		blit (Menu_R, butter, 0, Main_menu + Main_menu_choose * (Choose - 1), 0, Main_menu + Main_menu_choose * (Choose - 1), SCREEN_W, Main_menu_choose);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//		fprintf (Check,"%d",Choose);
//		fclose (Check);
	}
	stop_sample(Music_Main);
	destroy_sample (Music_Main);
	switch(Choose)
	{
		case 1:
			Start(&X, &Y, &last, &OUT);
			X = 32+16;
			Y = 32*3+16;
			last = 0;
			CO1(&X,&Y,&last,&map_number,&OUT);
			break;
		case 2:
			Load(&X,&Y,&last,&OUT,&map_number,&College);
			LOAD_GAME(X,Y,last,OUT,map_number,College);
			break;
		case 3:
		 	allegro_exit();
			break;

//			break;
	}

	return 0;
}
