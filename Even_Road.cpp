#include <allegro.h>
#include "Cfont.h"

void Even_09()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\LS.bmp",NULL);//LS
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 48);
	Print_words(face02, 49);
	Print_words(face01, 50);
	Print_words(face02, 51);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_10()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\chicken.bmp",NULL);//¤pÂû
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face02, 47);
	Print_words(face02, 52);
	Print_words(face01, 53);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_11()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\LS.bmp",NULL);//LS
	BITMAP *face03 = load_bitmap ("image\\Face\\chicken.bmp",NULL);//¤pÂû
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 54);
	Print_words(face03, 55);
	Print_words(face02, 56);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
}