#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"
#include "Even_Speak.h"
#include "Even_Speak_01.h"

int LO102(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\LO1\\L012f.bmp",NULL);//��X���k�|Road003
	BITMAP *Not = load_bitmap ("image\\LO1\\L012fRED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;
	if (*OUT <= 25)
	{
		character= load_bitmap ("image\\character\\APIBM.bmp",NULL);//�Ȥ�
		masked_blit (character, background, PeopleW*0, PeopleH*1, PeopleW*4, PeopleH*3, PeopleW, PeopleH);
		blit (Not2, Not, PeopleW*0, PeopleH*1, PeopleW*3, PeopleH*3, PeopleW*2, PeopleH*1);
	//test//
//		blit (Not2, background, PeopleW*0, PeopleH*1, PeopleW*3, PeopleH*3, PeopleW*2, PeopleH*1);
//		masked_blit (character, background, PeopleW*0, PeopleH*1, PeopleW*4, PeopleH*3, PeopleW, PeopleH);
	}

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if (key[KEY_RIGHT] &&  Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 896 + 16;
			*Y = *Y - 32 * 6;
			return 1;//�ϸ�@��
		}
		if  (*OUT == 26 && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
//			*X = 16;
			*Y = *Y + 32 * 1;
			*last = 0;
			return 3;//�ϸ꤭��
		}
		if (key[KEY_SPACE] && (*last == 2 && Not->line[*Y][*X*3] == 20 && Not->line[*Y][*X*3+1] == 255 && Not->line[*Y][*X*3+2] == 20))//BGR
		{//�P�Ȥӹ��(���)
			if (*OUT < 25)
			{Even_APIBM();}
			if (*OUT == 25)
			{
				*OUT = 26;
				Even_26(Music);
				
				destroy_bitmap (character);
				destroy_bitmap (background);
				destroy_bitmap (Not);
				destroy_bitmap (Not2);
				return 2;
			}
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,2,6);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,2,6,Music);}
	}
}