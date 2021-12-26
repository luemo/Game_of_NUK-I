#include <allegro.h>
#include "Cfont.h"

void Even_05()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face03 = load_bitmap ("image\\Face\\EL.bmp",NULL);//EL
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face03, 28);
	Print_words(face02, 29);
	Print_words(face03, 30);
	Print_words(face02, 31);
	Print_words(face01, 32);
	Print_words(face02, 33);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
}

void Even_06()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face02 = load_bitmap ("image\\Face\\TCCD.bmp",NULL);//TCCD
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 34);
	Print_words(face02, 35);
	Print_words(face01, 36);
	Print_words(face02, 37);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_07()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face03 = load_bitmap ("image\\Face\\EL.bmp",NULL);//EL
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)
//
//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face02, 38);
	Print_words(face01, 39);
	Print_words(face03, 40);
	Print_words(face02, 41);
	Print_words(face03, 42);
	Print_words(face02, 43);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);}

void Even_08()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\DKHL.bmp",NULL);//DKHL
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 44);
	Print_words(face02, 45);
	Print_words(face01, 46);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}
