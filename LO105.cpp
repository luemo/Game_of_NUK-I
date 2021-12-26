#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "Save.h"
#include "system.h"

int LO105(int *X, int *Y, int *last, int *OUT, SAMPLE *Music)
{
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO1\\L015f.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\LO1\\L015fRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	for(;;)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		if (/*key[KEY_UP] &&*/ Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 10 && Not->line[*Y][*X*3+2] == 10)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
//			*X = 896 + 16;
			*Y = *Y + 32 * 1;
			*last = 0;
			return 2;//圖資二樓
		}
		if  (Not->line[*Y][*X*3] == 255 && Not->line[*Y][*X*3+1] == 20 && Not->line[*Y][*X*3+2] == 20)//BGR
		{
			destroy_bitmap (character);
			destroy_bitmap (background);
			destroy_bitmap (Not);
			destroy_bitmap (Not2);
//			*X = 16;
			*Y = 432 + 16;
			return 4;//校長辦公室
		}

		if (key[KEY_Q])
		{
		Save(*X,*Y,*last,*OUT,3,6);
		}
		if (key[KEY_ESC])
		{Menu(*X,*Y,*last,*OUT,3,6,Music);}
	}
}