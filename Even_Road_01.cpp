#include <allegro.h>
#include "Cfont.h"

void Even_LS01()
{
	BITMAP *face = load_bitmap ("image\\Face\\LS.bmp",NULL);//LS

	Print_words(face, 181);

	readkey();

	destroy_bitmap (face);
}

void Even_LS02()
{
	BITMAP *face = load_bitmap ("image\\Face\\LS.bmp",NULL);//LS

	Print_words(face, 182);

	readkey();

	destroy_bitmap (face);
}

void Even_Chicken()
{
	BITMAP *face = load_bitmap ("image\\Face\\chicken.bmp",NULL);//¤pÂû

	Print_words(face, 47);

	readkey();

	destroy_bitmap (face);
}
