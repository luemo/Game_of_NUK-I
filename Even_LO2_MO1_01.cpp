#include <allegro.h>
#include "Cfont.h"

void Even_GL()
{
	BITMAP *face = load_bitmap ("image\\Face\\GL.bmp",NULL);//GL

	Print_words(face, 183);

	readkey();
	destroy_bitmap (face);
}

void Even_LAW()
{
	BITMAP *face = load_bitmap ("image\\Face\\LAW.bmp",NULL);//LAW

	Print_words(face, 184);

	readkey();

	destroy_bitmap (face);
}

void Even_CS01()
{
	BITMAP *face = load_bitmap ("image\\Face\\CS.bmp",NULL);//CS

	Print_words(face, 185);

	readkey();

	destroy_bitmap (face);
}

void Even_CS02()
{
	BITMAP *face = load_bitmap ("image\\Face\\CS.bmp",NULL);//CS

	Print_words(face, 186);

	readkey();

	destroy_bitmap (face);
}

void Even_CS03()
{
	BITMAP *face = load_bitmap ("image\\Face\\CS.bmp",NULL);//CS

	Print_words(face, 187);

	readkey();

	destroy_bitmap (face);
}

void Even_FEL01()
{
	BITMAP *face = load_bitmap ("image\\Face\\FEL.bmp",NULL);//FEL

	Print_words(face, 188);

	readkey();

	destroy_bitmap (face);
}

void Even_FEL02()
{
	BITMAP *face = load_bitmap ("image\\Face\\FEL.bmp",NULL);//FEL

	Print_words(face, 189);

	readkey();

	destroy_bitmap (face);
}

void Even_FIN01()
{
	BITMAP *face = load_bitmap ("image\\Face\\FIN.bmp",NULL);//FIN

	Print_words(face, 190);

	readkey();

	destroy_bitmap (face);
}

void Even_FIN02()
{
	BITMAP *face = load_bitmap ("image\\Face\\FIN.bmp",NULL);//FIN

	Print_words(face, 191);

	readkey();

	destroy_bitmap (face);
}

void Even_IM_ECON()
{
	BITMAP *face01 = load_bitmap ("image\\Face\\IM.bmp",NULL);//IM
	BITMAP *face02 = load_bitmap ("image\\Face\\ECON.bmp",NULL);//ECON

	Print_words(face02, 192);
	Print_words(face01, 193);

	readkey();
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}