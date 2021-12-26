#include <allegro.h>
#include "people_work.h"
#include "Road.h"
#include "College.h"


void Road(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//事件發生數 + 出外可許:0~3 = 不可,4 = 可;//接綜合
//int BO1Road(int *X, int *Y, int *last, int *OUT)
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//Road001
	{
	//	*Y = 32*3+16;
		*map_number = Road001(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//Road002
	{
	//	*X = 16;
		*map_number = Road002(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 3)//Road003
	{
//		*X = 96+16;
//		*Y = 16;
		*map_number = Road003(X,Y,last,OUT,Music_Work);//96+16,302-16
	}
	else if ( *map_number == 4)//Road004
	{
//		*X = 16;
//		*Y = 288+16;
		*map_number = Road004(X,Y,last,OUT,Music_Work);//608+16  288+16
	}
	}while(*map_number != 100);

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

	*map_number = 101;
	//OUT = 8;
	*X = 16;
	*Y = *Y + 32 *(30 - 3);
	//last = 0;
	///////////OUT = 0;*/
//test//
/*	*map_number = 1;
	*OUT = 0;
	*X = 16;
	*Y = 864 - 16;
	//last = 0;
	///////////OUT = 0;*/

	RoadtoLO1_01(X, Y, last, map_number, OUT);

}