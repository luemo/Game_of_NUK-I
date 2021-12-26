#include <allegro.h>
#include "people_work.h"
#include "Save.h"
#include "system.h"

int CO104(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
	BITMAP *background = load_bitmap ("image\\CO1\\c014f.bmp",NULL);//�u�|�|��
	BITMAP *Not = load_bitmap ("image\\CO1\\c014fRED.bmp",NULL);//��ê��
	BITMAP *character;

	character =  load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)
		{
			destroy_bitmap (background);
			destroy_bitmap (Not);
			*Y = 32*3+16;
			*last = 0;
			return 1;//�@�ӹq��X�f
		}
		if (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)
		{
			destroy_bitmap (background);
			destroy_bitmap (Not);
			*X = 96+16;
			*Y = 302-16;
			return 3;//�|�ӱЫ�
		}
		
		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,2,1);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,2,1,Music);}
	}
}