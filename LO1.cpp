#include <allegro.h>
#include "people_work.h"
#include "LO1.h"
#include "system.h"

void LO1(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//事件發生數 + 出外可許:0~3 = 不可,4 = 可;//接綜合
//int BO1Road(int *X, int *Y, int *last, int *OUT)
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//圖資一樓
	{
	//	*Y = 32*3+16;
		*map_number = LO101(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//圖資二樓
	{
//		*X = 16;
//		*Y = 32*5+16;
		*map_number = LO102(X,Y,last,OUT, Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 3)//圖資五樓
	{
		*map_number = LO105(X,Y,last,OUT,Music_Work);//96+16,302-16
	}
	else if ( *map_number == 4)//PrincipleOffice
	{
		stop_sample(Music_Work);
		destroy_sample (Music_Work);

//		*X = 16;
//		*Y = 288+16;
		*map_number = PrincipleOffice(X,Y,last,OUT);//608+16  288+16
	}
	}while(*map_number != 100);

	Main_Menu();

}