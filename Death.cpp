#include <allegro.h>

void Death()
{
	int i = 0,j = 0;
	BITMAP *Die;
	Die = load_bitmap ("image\\Fighting\\Death.bmp",NULL);
	blit (Die, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	for(i = 0;i <= 10000;i++)
	{
		for(j = 0;j <= 10000;j++){}
//		rest(50);
	}
	rest(150);
	if (!key[KEY_SPACE])
	{}
	rest(150);
}