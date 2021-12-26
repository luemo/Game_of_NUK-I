#include <allegro.h>
#include <stdio.h>
#include "Save.h"
#include "system.h"

void Menu(int X, int Y, int last, int OUT, int Map, int College, SAMPLE *Music)
{
	int Choose = 1;
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	BITMAP *Menu_W = load_bitmap("image\\system\\menu.bmp",NULL);
	BITMAP *Menu_R = load_bitmap("image\\system\\menu02.bmp",NULL);
//	FILE *Check;
	

	blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (Menu_R, butter, 0, Sub_menu, 0, Sub_menu, SCREEN_W, Sub_menu_choose);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	while (!key[KEY_SPACE])
	{
//		Check = fopen("Check02.txt","w");

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
			if (Choose > 4)
			{Choose = 4;}
		}
		if (key[KEY_ESC])
		{
			Choose = 1;
			break;
		}

		blit (Menu_W, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		blit (Menu_R, butter, 0, Sub_menu + Sub_menu_choose * (Choose - 1), 0, Sub_menu + Sub_menu_choose * (Choose - 1), SCREEN_W, Sub_menu_choose);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//		fprintf (Check,"%d",Choose);
//		fclose (Check);
	}
//	if (key[KEY_ESC])
//	{//SUB_MAIN_CHOOSE = Menu();
		//switch(SUB_MAIN_CHOOSE)
		switch(Choose)
		{
			case 1:
				break;
			case 2:
				Save(X,Y,last,OUT,Map,College);
				break;
			case 3:
				stop_sample(Music);
				destroy_sample (Music);
				Load(&X,&Y,&last,&OUT,&Map,&College);
				LOAD_GAME(X,Y,last,OUT,Map,College);
//				break;
			case 4:
//				main();
				stop_sample(Music);
				destroy_sample (Music);
				rest(100);
				Main_Menu();
				break;
		}
//	}

//	return Choose;
}


