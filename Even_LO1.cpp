#include <allegro.h>
#include "Cfont.h"
#include "Fight.h"

void Even_23()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\AM.bmp",NULL);//AM

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face01, 121);
	Print_words(face02, 122);
	Print_words(face01, 123);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
}

void Even_25()
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\LAW.bmp",NULL);//LAW
	BITMAP *face03 = load_bitmap ("image\\Face\\AM.bmp",NULL);//AM

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face01, 124);
	Print_words(face03, 125);
	Print_words(face03, 126);
	Print_words(face02, 127);
	Print_words(face01, 128);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
}

void Even_26(SAMPLE *Music)
{
	SAMPLE *Music_Fighting;
	Music_Fighting = load_sample( "VOICE/02 - TITAN.wav"); 

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\LAW.bmp",NULL);//LAW
	BITMAP *face03 = load_bitmap ("image\\Face\\AM.bmp",NULL);//AM
	BITMAP *face04 = load_bitmap ("image\\Face\\APIBM.bmp",NULL);//APIBM

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face03, 129);
	Print_words(face04, 130);
	Print_words(face03, 131);
	Print_words(face04, 132);
	Print_words(face03, 133);
	Print_words(face04, 134);
	Print_words(face01, 135);
	Print_words(face04, 136);
	Print_words(face02, 137);
	Print_words(face04, 138);
///////////////////////////¾Ô°«//////////////////////////////////////////

	blit (screen, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	stop_sample(Music);
	play_sample( Music_Fighting, 255, 0, 1000, 1);

	Fight_APIBM(Music_Fighting);

	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	stop_sample(Music_Fighting);
	destroy_sample (Music_Fighting);
	play_sample( Music, 255, 0, 1000, 1);

///////////////////////////¾Ô°«//////////////////////////////////////////
	Print_words(face04, 139);

	readkey();
//	destroy_bitmap (back);
	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
	destroy_bitmap (face04);
}

void Even_27(BITMAP *butter, SAMPLE *Music)
{
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//¿Ã¹õ¼È¦s¾¹
	SAMPLE *Music_Fighting;
	Music_Fighting = load_sample( "VOICE/05 - AMAZONA.wav"); 

//	BITMAP *back = load_bitmap ("image\\break.bmp",NULL);//CG
	BITMAP *face01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//EE
	BITMAP *face02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//WL
	BITMAP *face03 = load_bitmap ("image\\Face\\LAW.bmp",NULL);//LAW
	BITMAP *face04 = load_bitmap ("image\\Face\\AM.bmp",NULL);//AM
	BITMAP *face05 = load_bitmap ("image\\Face\\Principle.bmp",NULL);//BOSS

//	BITMAP *butter2 = create_bitmap (back->w, back->h);//==background(­I´º)

//	blit (back, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face05, 140);
	Print_words(face01, 141);
	Print_words(face05, 142);
	Print_words(face03, 143);
	Print_words(face04, 144);
	Print_words(face02, 145);
	Print_words(face05, 146);
	Print_words(face05, 147);
	Print_words(face01, 148);
	Print_words(face05, 149);
	Print_words(face02, 150);
	Print_words(face05, 151);
	Print_words(face01, 152);
	Print_words(face05, 153);
///////////////////////////¾Ô°«//////////////////////////////////////////
	stop_sample(Music);
	play_sample( Music_Fighting, 255, 0, 1000, 1);
	Fight_BOSS(Music_Fighting);
	stop_sample(Music_Fighting);
	destroy_sample (Music_Fighting);
	play_sample( Music, 255, 0, 1000, 1);
///////////////////////////¾Ô°«//////////////////////////////////////////
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Print_words(face05, 154);
	Print_words(face01, 155);
	Print_words(face03, 156);
	Print_words(face04, 157);
	Print_words(face02, 158);

	readkey();
//	destroy_bitmap (back);
//	destroy_bitmap (butter);
//	destroy_bitmap (butter2);
	destroy_bitmap (face01);
	destroy_bitmap (face02);
	destroy_bitmap (face03);
	destroy_bitmap (face04);
	destroy_bitmap (face05);
}