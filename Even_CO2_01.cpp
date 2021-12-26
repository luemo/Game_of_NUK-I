#include <allegro.h>
#include "Cfont.h"

void Even_AP()
{
	BITMAP *face = load_bitmap ("image\\Face\\AP.bmp",NULL);//AP

	Print_words(face, 194);

	readkey();

	destroy_bitmap (face);
}

void Even_AC01()
{
	BITMAP *face = load_bitmap ("image\\Face\\AC.bmp",NULL);//AC

	Print_words(face, 195);

	readkey();

	destroy_bitmap (face);
}

void Even_AC02()
{
	BITMAP *face = load_bitmap ("image\\Face\\AC.bmp",NULL);//AC

	Print_words(face, 196);

	readkey();

	destroy_bitmap (face);
}