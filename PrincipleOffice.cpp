#include <allegro.h>
#include "people_work.h"
//#include "LO2_MO1.h"
//#include "Save.h"
//#include "system.h"
#include "Even_Speak.h"

int PrincipleOffice(int *X, int *Y, int *last, int *OUT)
{
	SAMPLE *Music_Speak;
	Music_Speak = load_sample( "VOICE/10 - THE FALL OF GILEAD.wav"); 
	play_sample( Music_Speak, 255, 0, 1000, 1);
//	int i = 0;//面向回傳值的控制
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	BITMAP *background = load_bitmap ("image\\LO1\\principleOffice.bmp",NULL);//綜合往法院Road003
	BITMAP *Not = load_bitmap ("image\\LO1\\principleOfficeRED.bmp",NULL);//障礙物
	BITMAP *Not2 = load_bitmap ("image\\NOT.bmp",NULL);//障礙物
	BITMAP *character;

	character = load_bitmap ("image\\character\\EE.bmp",NULL);

	*X = 32 * 15 - 16;
	*Y = 32 * 23 + 16;

	for(*Y = 32 * 23 + 16; *Y >= 32 * 8 +16; *Y = *Y - 32)
	{
		walking (X, Y, last, character, background, Not);//3上0下1左2右
		rest(50);
	}

	blit (screen, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(*last), 32 * 10 - 16, 32 * 7, PeopleW, PeopleH);
	character = load_bitmap ("image\\character\\WL.bmp",NULL);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(*last), 32 * 10 - 16, 32 * 8, PeopleW, PeopleH);
	character = load_bitmap ("image\\character\\LAW.bmp",NULL);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(*last), 32 * 9 - 16, 32 * 8, PeopleW, PeopleH);
	character = load_bitmap ("image\\character\\AM.bmp",NULL);
	masked_blit (character, butter, PeopleW*(1%3), PeopleH*(*last), 32 * 11 - 16, 32 * 8, PeopleW, PeopleH);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	Even_27(butter, Music_Speak);

	destroy_bitmap (character);
	destroy_bitmap (background);
	destroy_bitmap (Not);
	destroy_bitmap (Not2);

	stop_sample(Music_Speak);
	destroy_sample (Music_Speak);

	return 100;//END
}