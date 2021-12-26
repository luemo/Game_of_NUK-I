#include <allegro.h>
#include "people_work.h"
#include "BO1.h"
#include "College.h"

void BO1(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//事件發生數 + 出外可許:0~3 = 不可,4 = 可;//接綜合
//int BO1Road(int *X, int *Y, int *last, int *OUT)
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//工院和綜合間的道路
	{
	//	*Y = 32*3+16;
		*map_number = BO1Road(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//綜合
	{

		*map_number = BO101(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	}while(*map_number != 100);
	*map_number = 1;
	//OUT = 8;
	*X = 16;
	*Y = *Y - 32 * (58 - 4);
	//last = 0;
	///////////OUT = 0;
//test//
/*	*map_number = 1;
	*OUT = 8;
	*X = 16;
	*Y = 32*4;
	//last = 0;
	///////////OUT = 0;*/

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

	Road(X, Y, last, map_number, OUT);

}