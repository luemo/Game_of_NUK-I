#include <allegro.h>
#include "Cfont.h"

void Even_Start01()
{
	BITMAP *face = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	
	Print_words(face, 0);

	readkey();

	destroy_bitmap (face);
}

void Even_Start02()
{
	BITMAP *face = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	
	Print_words(face, 1);

	readkey();

	destroy_bitmap (face);
}

void Even_CEE01()
{
	BITMAP *face = load_bitmap ("image\\Face\\CEE.bmp",NULL);//CEE
	
	Print_words(face, 171);

	readkey();

	destroy_bitmap (face);
}
void Even_CEE02()
{
	BITMAP *face = load_bitmap ("image\\Face\\CEE.bmp",NULL);//CEE
	
	Print_words(face, 172);

	readkey();

	destroy_bitmap (face);
}

void Even_CM01()
{
	BITMAP *face = load_bitmap ("image\\Face\\CM.bmp",NULL);//CM

	Print_words(face, 173);

	readkey();

	destroy_bitmap (face);
}
void Even_CM02()
{
	BITMAP *face = load_bitmap ("image\\Face\\CM.bmp",NULL);//CM

	Print_words(face, 174);

	readkey();

	destroy_bitmap (face);
}
void Even_Wu01()
{
	BITMAP *face = load_bitmap ("image\\Face\\teacher.bmp",NULL);//teacker

	Print_words(face, 175);

	readkey();

	destroy_bitmap (face);
}

void Even_Wu02()
{
	BITMAP *face = load_bitmap ("image\\Face\\teacher.bmp",NULL);//teacker

	Print_words(face, 176);

	readkey();

	destroy_bitmap (face);
}