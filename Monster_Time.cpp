#include <allegro.h>
#include "Fighting.h"
#include<time.h>

void Monster_Time(BITMAP *butter2, int n, int O[4][4], int M[3][2], int MonsterAct)
{
	int i = 1;	//�H�y��m
	int j = 0;	//���ĴX�ӤH
	int k = 0;	//�˲���m
//	int m = 0;	//�ĴX�Ǫ�������
	int a = 0;	//���H�����H�O�_���즺�H:0 = �O;1 = �_

//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��
//	BITMAP *Attack_our = load_bitmap ("image\\Fighting\\FaceACT.bmp",NULL);//�Ǫ�������
	BITMAP *Attack_our = load_bitmap ("image\\Fighting\\enemyattack.bmp",NULL);//�Ǫ�������

//	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	while ( m < M )
//	{
	while ( a == 0 )
	{
		if (n == 1)			//�Ĥ@�ӤH			//�Q�Ǫ���������m
		{j = 1;
		 a = 1;}						//���D�I
		else if (n == 2)	//�ĤG�ӤH
		{j = rand() % 2 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		else if (n == 3)	//�ĤT�ӤH
		{j = rand() % 3 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		else if (n == 4)	//�ĤT�ӤH
		{j = rand() % 4 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		if (O[0][0] <= 0  && O[1][0] <= 0 && O[2][0] <= 0 && O[3][0] <= 0)
		{j = 1;
		 a = 1;}
	}
		if (j == 1)			//�Ĥ@�ӤH
		{i  = Our_FFX_01;					//�Q�Ǫ���������m
		O[0][0] = O[0][0] - M[MonsterAct][1];/**/
			if (O[0][0] <= 0)
			{O[0][0] = 0;}
		}
		else if (j == 2)	//�ĤG�ӤH
		{i  = Our_FFX_02;
		O[1][0] = O[1][0] - M[MonsterAct][1];
			if (O[1][0] <= 0)
			{O[1][0] = 0;}
		}
		else if (j == 3)	//�ĤT�ӤH
		{i  = Our_FFX_03;
		O[2][0] = O[2][0] - M[MonsterAct][1];
			if (O[2][0] <= 0)
			{O[2][0] = 0;}
		}
		else if (j == 4)	//�ĤT�ӤH
		{i  = Our_FFX_04;
		O[3][0] = O[3][0] - M[MonsterAct][1];
			if (O[3][0] <= 0)
			{O[3][0] = 0;}
		}

//			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			blit (butter2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

		for ( k = 0 ; k <= FFH + 10 ; k = k + 5)//�Ǫ�����
		{
				rest (10);
			masked_blit (Attack_our, screen, 0, 0, i, Our_FFY, FFW, k);
		}
				rest (100);
//		m = m + 1;
//	}

//	destroy_bitmap (butter);
//	destroy_bitmap (Attack_M);
//	return m;
}