#include <allegro.h>
#include "people_work.h"
#include "CO1.h"
#include "College.h"

void CO1(int *X, int *Y, int *last, int *map_number, int *OUT)
{
	SAMPLE *Music_Work;
	Music_Work = load_sample( "VOICE/09 - CREO EN TI.wav" ); 
	play_sample( Music_Work, 255, 0, 1000, 1);

//	int map_number = 1;
//	int OUT = 0;//�ƥ�o�ͼ� + �X�~�i�\:0~3 = ���i,4 = �i;//����X
//Start(X, Y, last, OUT);
	
//	map_number = 1;
//	OUT = 0;//�ƥ�o�ͼ� + �X�~�i�\:0~3 = ���i,4 = �i;//����X

	do
	{
	if ( *map_number == 1)//�@��
	{
		*map_number = CO101(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 2)//�|��
	{
		*map_number = CO104(X,Y,last,OUT,Music_Work);//32+16  32*3+16
	}
	else if ( *map_number == 3)//�|�ӱЫ�
	{
		*map_number = CO104_lab(X,Y,last,OUT,Music_Work);//96+16,302-16
	}
	else if ( *map_number == 5)//�a�U�Ǽӱ�
	{
		*map_number = CO1b01(X,Y,last,OUT,Music_Work);//1216+16,768-16
	}
	}while(*map_number != 100);

	stop_sample(Music_Work);
	destroy_sample (Music_Work);

	*map_number = 1;
	//OUT = 4;
	//X = 16;
	*Y = 16;
	//last = 0;

//test//
/*	*map_number = 100;
	*OUT = 4;
	//X = 16;
	//*Y = 16;
	//last = 0;*/


	BO1(X, Y, last, map_number, OUT);
}