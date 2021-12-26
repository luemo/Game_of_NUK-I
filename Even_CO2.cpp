#include <allegro.h>
#include "Cfont.h"

void Even_21()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\AP.bmp",NULL);//AP

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face01, 109);
	Print_words(face02, 110);
	Print_words(face01, 111);
	Print_words(face02, 112);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_22()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face03 = load_bitmap ("image\\Face\\LAW.bmp",NULL);//LAW
	BITMAP *face04 = load_bitmap ("image\\Face\\AC.bmp",NULL);//AC

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face01, 113);
	Print_words(face04, 114);
	Print_words(face01, 115);
	Print_words(face04, 116);
	Print_words(face01, 117);
	Print_words(face02, 118);
	Print_words(face03, 119);
	Print_words(face04, 120);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
	destroy_bitmap (face04);
}
