#include <allegro.h>
#include "Cfont.h"

void Even_AM()
{
	BITMAP *face = load_bitmap ("image\\Face\\AM.bmp",NULL);//AM

	Print_words(face, 197);

	readkey();

	destroy_bitmap (face);
}

void Even_APIBM()
{
	BITMAP *face = load_bitmap ("image\\Face\\APIBM.bmp",NULL);//APIBM

	Print_words(face, 198);

	readkey();

	destroy_bitmap (face);
}
