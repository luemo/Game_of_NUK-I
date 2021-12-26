#include <allegro.h>
#include "Cfont.h"
#include "Fight.h"

void Even_01()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 2);
	Print_words(face01, 3);
	Print_words(face02, 4);
	Print_words(face01, 5);
	Print_words(face02, 6);
	Print_words(face01, 7);
	Print_words(face02, 8);
	Print_words(face01, 9);
	Print_words(face02, 10);
	
	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}
void Even_02(SAMPLE *Music)
{
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹
	SAMPLE *Music_Fighting;
	Music_Fighting = load_sample( "VOICE/02 - TITAN.wav"); 

//	BITMAP *back = load_bitmap ("image\\break2.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face03 = load_bitmap ("image\\Face\\CEE.bmp",NULL);//CEE
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face01, 11);
	Print_words(face03, 12);
	Print_words(face01, 13);
	Print_words(face03, 14);
	Print_words(face02, 15);
	Print_words(face03, 16);
	Print_words(face02, 17);

	stop_sample(Music);
	play_sample( Music_Fighting, 255, 0, 1000, 1);
	blit (screen, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Fight_CEE(Music_Fighting);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	stop_sample(Music_Fighting);
	destroy_sample (Music_Fighting);

	readkey();
//	destroy_bitmap (back);
	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
}

void Even_03()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\CM.bmp",NULL);//CM
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face01, 18);
	Print_words(face02, 19);
	Print_words(face01, 20);
	Print_words(face02, 21);
	Print_words(face01, 22);
	Print_words(face02, 23);
	Print_words(face01, 24);
	
	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_04()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\teacher.bmp",NULL);//teacker
	
//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	Print_words(face02, 25);
	Print_words(face01, 26);
	Print_words(face02, 27);
	
	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}