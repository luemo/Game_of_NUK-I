#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO101(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\LO1\\L011f.bmp",NULL);//��X���k�|Road003
	BITMAP *Not = load_bitmap ("image\\LO1\\L011fRED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;
	if (*OUT <= 23)
	{
		character= load_bitmap ("image\\ThingForAM.bmp",NULL);//���ƨƥ󪫫~
		masked_blit (character, background, 0, 0, PeopleW*8, PeopleH*2, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*7, PeopleH*2, PeopleW*2, PeopleH*1);
		blit (Not2, Not, PeopleW*1, PeopleH*2, PeopleW*8, PeopleH*3, PeopleW*1, PeopleH*1);
//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*7, PeopleH*2, PeopleW*2, PeopleH*1);
//		blit (Not2, background, PeopleW*1, PeopleH*2, PeopleW*8, PeopleH*3, PeopleW*1, PeopleH*1);
//		masked_blit (character, background, 0, 0, PeopleW*8, PeopleH*2, PeopleW, PeopleH);
	}
	if (*OUT <= 24)
	{
		character= load_bitmap ("image\\character\\AM.bmp",NULL);//����
		masked_blit (character, background, PeopleW*1, PeopleH*3, PeopleW*9, PeopleH*23, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*8, PeopleH*23, PeopleW*2, PeopleH*1);
	//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*8, PeopleH*23, PeopleW*2, PeopleH*1);
//		masked_blit (character, background, PeopleW*1, PeopleH*3, PeopleW*9, PeopleH*23, PeopleW, PeopleH);
	}
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if  (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 864 - 16;
			*Y = *Y + 32 * 6;
			return 2;//�ϸ�G��
		}
		if (key[KEY_SPACE] && *Y >= PeopleH*9 && (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20))//BGR
		{//�P���ƹ��
			if (*OUT == 22)
			{
				*OUT = 23;
				Even_23();
			}
			if (*OUT > 22 && *OUT < 24)
			{Even_AM();}
			if (*OUT == 24)
			{
			*OUT = 25;
			Even_25();
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 1;//�P���ƹ��
			}
		}
		if (*OUT == 23 && key[KEY_SPACE] && *Y <= PeopleH*9 &&  ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{
			*OUT = 24;
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 1;//�����ƨƥ󪫫~
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,6);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,6,Music);}
	}
}