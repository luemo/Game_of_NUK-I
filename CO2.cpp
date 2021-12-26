#include <allegro.h>
#include "people_work.h"
#include "CO2.h"
#include "Save.h"
#include "College.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

void CO2(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//�ƥ�o�ͼ� + �X�~�i�\:0~3 = ���i,4 = �i;//����X
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//�z�|
	{
		*map_number = CO201(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	}while(*map_number != 100);

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

	*map_number = 103;
	*X = *X;
	*Y = 16;
	//OUT = 22;
//test//
/*	*map_number = 1;
	*OUT = 22;
	*X = 16;
	*Y = 16;
	//last = 0;
	///////////OUT = 0;*/

	RoadtoLO1_03(X, Y, last, map_number, OUT);
}

int CO201(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\CO2\\C02.bmp",NULL);//�z�|
	BITMAP *Not = load_bitmap ("image\\CO2\\C02RED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;

	character= load_bitmap ("image\\character\\AP.bmp",NULL);//����
	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*50, PeopleH*43, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*0, PeopleH*0, PeopleW*49, PeopleH*42, Not2->w, Not2->h);
//test//
//	blit (Not2, background, PeopleW*0, PeopleH*0, PeopleW*49, PeopleH*42, Not2->w, Not2->h);
//	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*50, PeopleH*43, PeopleW, PeopleH);

	character= load_bitmap ("image\\character\\AC.bmp",NULL);//����
	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*36, PeopleH*7, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*0, PeopleH*0, PeopleW*35, PeopleH*6, Not2->w, Not2->h);
//test//
//	blit (Not2, background, PeopleW*0, PeopleH*0, PeopleW*35, PeopleH*6, Not2->w, Not2->h);
//	masked_blit (character, background, PeopleW*1, PeopleH*0, PeopleW*36, PeopleH*7, PeopleW, PeopleH);
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
 		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if (*OUT == 22 && key[KEY_DOWN] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);

			return 100;//�ϸ�e���D��
		}
		if (key[KEY_SPACE] && *Y >= PeopleH*24 && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{//�P�������

			if (*OUT == 20)
			{
				*OUT = 21;
				Even_21();
			}
			if (*OUT > 20)
			{Even_AP();}
		}
		if (key[KEY_SPACE] && *Y <= PeopleH*24 && ((*last == 1 && Not->line[*Y][*X*3] == 10 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 10) || (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30) || (*last == 0 && Not->line[*Y][*X*3] == 0 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 0)))//BGR
		{
			if (*OUT < 21)
			{Even_AC01();}
			if (*OUT == 21)
			{
				*OUT = 22;
				Even_22();
			}
			if (*OUT > 21)
			{Even_AC02();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,5);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,5,Music);}
	}
}
