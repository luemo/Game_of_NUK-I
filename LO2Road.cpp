#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"

int LO2Road(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//���V�^�ǭȪ�����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��

	BITMAP *background = load_bitmap ("image\\LO2_MO1\\L02road.bmp",NULL);//LO2Road �i�J�k�|�e���D��
	BITMAP *Not = load_bitmap ("image\\LO2_MO1\\L02roadRED.bmp",NULL);//��ê��
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//��ê��
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3�W0�U1��2�k
		if (*OUT >= 20 && key[KEY_RIGHT] && Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			//*Y = 16;
			return 5;//RoadUP
		}
		if  (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			*X = 16;
			*Y = *Y - 32 * (32 - 5);
			return 2;//LO2
		}
		if (*OUT == 20 && key[KEY_LEFT] && *X <= PeopleW/2)
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
			return 100;
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,1,4);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,1,4,Music);}
	}
}