#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int MO1(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\M01.bmp",NULL);//�ް|
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\M01RED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;

	character= load_bitmap ("image\\character\\ECON.bmp",NULL);//���g
	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*5, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*5, PeopleW*1, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*5, PeopleW*1, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*1, PeopleW*52, PeopleH*5, PeopleW, PeopleH);

	character= load_bitmap ("image\\character\\IM.bmp",NULL);//���
	masked_blit (character, background, PeopleW*1, PeopleH*2, PeopleW*51, PeopleH*5, PeopleW, PeopleH);
	blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*50, PeopleH*5, PeopleW*2, PeopleH*2);
//test//
//	blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*50, PeopleH*5, PeopleW*2, PeopleH*2);
//	masked_blit (character, background, PeopleW*1, PeopleH*2, PeopleW*51, PeopleH*5, PeopleW, PeopleH);
	
	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if (key[KEY_LEFT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 32 * 22 - 16;
			*Y = *Y;
			return 3;//L02toM01road
		}
		if (key[KEY_SPACE] && ((*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20) || (*last == 3 && Not->line[*Y][*X*3] == 30 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 30)))//BGR
		{//�P���g�M��޹��(�԰�)
			if (*OUT == 18)
			{
				*OUT = 19;
				Even_19(Music);
			}
			if (*OUT > 18)
			{Even_IM_ECON();}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,4,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,4,4,Music);}
	}
}