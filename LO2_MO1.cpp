#include <allegro.h>
#include "people_work.h"
#include "LO2_MO1.h"
#include "College.h"

void LO2_MO1(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//�ƥ�o�ͼ� + �X�~�i�\:0~3 = ���i,4 = �i;//����X
//int BO1Road(int *X, int *Y, int *last, int *OUT)
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//LO2Road �i�J�k�|�e���D��
	{
	//	*Y = 32*3+16;
		*map_number = LO2Road(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//LO2
	{
//		*X = 16;
//		*Y = 32*5+16;
		*map_number = LO2(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 3)//L02toM01road �k�ް|�����D��
	{
		*map_number = LO2toMO1road(X,Y,last,OUT,Music_Work);//96+16,302-16
	}
	else if ( *map_number == 4)//MO1
	{
//		*X = 16;
//		*Y = 288+16;
		*map_number = MO1(X,Y,last,OUT,Music_Work);//608+16  288+16
	}
	else if ( *map_number == 5)//RoadUP �k�ް|�����W�誺�D��
	{
//		*X = 16;
//		*Y = 288+16;
		*map_number = RoadUP(X,Y,last,OUT,Music_Work);//608+16  288+16
	}
	else if ( *map_number == 6)//�k�|�Z��
	{
//		*X = 16;
//		*Y = 288+16;
		*map_number = Restroom(X,Y,last,OUT,Music_Work);//608+16  288+16
	}
	else if ( *map_number == 7)//�k�|�Ы�
	{
//		*X = 16;
//		*Y = 288+16;
		*map_number = 	LO2_classroom(X,Y,last,OUT,Music_Work);//608+16  288+16
	}
	}while(*map_number != 100);

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

	*map_number = 102;
	//OUT = 20;
	*X = 864 - 16;
	*Y = *Y + 32 * (30 - 3);
	//last = 0;
//test//
/*	*map_number = 1;
	*OUT = 20;
	*X = 864 - 16;
	*Y = 32*53;
	//last = 0;
	///////////OUT = 0;*/

	RoadtoLO1_02(X, Y, last, map_number, OUT);

}