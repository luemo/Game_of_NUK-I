#include <allegro.h>
#include "Cfont.h"

void Even_EL01()
{
	BITMAP *face = load_bitmap ("image\\Face\\EL.bmp",NULL);//EL
	Print_words(face, 28);

	readkey();

	destroy_bitmap (face);
}

void Even_EL02()
{
	BITMAP *face = load_bitmap ("image\\Face\\EL.bmp",NULL);//EL
	Print_words(face, 178);

	readkey();

	destroy_bitmap (face);
}

void Even_TCCD()
{
	BITMAP *face = load_bitmap ("image\\Face\\TCCD.bmp",NULL);//TCCD

	Print_words(face, 177);

	readkey();

	destroy_bitmap (face);
}

void Even_DKHL01()
{
	BITMAP *face = load_bitmap ("image\\Face\\DKHL.bmp",NULL);//DKHL

	Print_words(face, 179);

	readkey();

	destroy_bitmap (face);
}
void Even_DKHL02()
{
	BITMAP *face = load_bitmap ("image\\Face\\DKHL.bmp",NULL);//DKHL

	Print_words(face, 180);

	readkey();

	destroy_bitmap (face);
}