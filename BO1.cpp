#include <allegro.h>
#include "people_work.h"
#include "BO1.h"
#include "College.h"

void BO1(int *X, int *Y, int *last, int *map_number, int *OUT)
{
//	int map_number = 1;
//	int OUT = 0;//�ƥ�o�ͼ� + �X�~�i�\:0~3 = ���i,4 = �i;//����X
//int BO1Road(int *X, int *Y, int *last, int *OUT)
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

	do
	{
	if ( *map_number == 1)//�u�|�M��X�����D��
	{
	//	*Y = 32*3+16;
		*map_number = BO1Road(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//��X
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