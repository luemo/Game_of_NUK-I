#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"

int Road001(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\Road\\road001.bmp",NULL);//��X���k�|Road002
	BITMAP *Not = load_bitmap ("image\\Road\\road001RED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k

		if  (key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			return 2;//Road002
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,3);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,3,Music);}
	}
}