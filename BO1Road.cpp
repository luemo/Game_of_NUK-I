#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"

int BO1Road(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\BO1\\road_all.bmp",NULL);//�u�|�M��X�����D��
	BITMAP *Not = load_bitmap ("image\\BO1\\road_allRED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);


	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if  (key[KEY_DOWN] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 0 && Not->line[*Y][*X*3+2] == 0)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*Y = 16;
			return 2;//��X
		}
		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,2);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,2,Music);}
	}
}