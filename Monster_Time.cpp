#include <allegro.h>
#include "Fighting.h"
#include<time.h>

void Monster_Time(BITMAP *butter2, int n, int O[4][4], int M[3][2], int MonsterAct)
{
	int i = 1;	//人臉位置
	int j = 0;	//打第幾個人
	int k = 0;	//傷痕位置
//	int m = 0;	//第幾怪物的攻擊
	int a = 0;	//怪隨機打人是否打到死人:0 = 是;1 = 否

//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
//	BITMAP *Attack_our = load_bitmap ("image\\Fighting\\FaceACT.bmp",NULL);//怪物攻擊圖
	BITMAP *Attack_our = load_bitmap ("image\\Fighting\\enemyattack.bmp",NULL);//怪物攻擊圖

//	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//	while ( m < M )
//	{
	while ( a == 0 )
	{
		if (n == 1)			//第一個人			//被怪物攻擊的位置
		{j = 1;
		 a = 1;}						//問題點
		else if (n == 2)	//第二個人
		{j = rand() % 2 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		else if (n == 3)	//第三個人
		{j = rand() % 3 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		else if (n == 4)	//第三個人
		{j = rand() % 4 +1;
			if (O[j-1][0] > 0)
			{a = 1;}
		}
		if (O[0][0] <= 0  && O[1][0] <= 0 && O[2][0] <= 0 && O[3][0] <= 0)
		{j = 1;
		 a = 1;}
	}
		if (j == 1)			//第一個人
		{i  = Our_FFX_01;					//被怪物攻擊的位置
		O[0][0] = O[0][0] - M[MonsterAct][1];/**/
			if (O[0][0] <= 0)
			{O[0][0] = 0;}
		}
		else if (j == 2)	//第二個人
		{i  = Our_FFX_02;
		O[1][0] = O[1][0] - M[MonsterAct][1];
			if (O[1][0] <= 0)
			{O[1][0] = 0;}
		}
		else if (j == 3)	//第三個人
		{i  = Our_FFX_03;
		O[2][0] = O[2][0] - M[MonsterAct][1];
			if (O[2][0] <= 0)
			{O[2][0] = 0;}
		}
		else if (j == 4)	//第三個人
		{i  = Our_FFX_04;
		O[3][0] = O[3][0] - M[MonsterAct][1];
			if (O[3][0] <= 0)
			{O[3][0] = 0;}
		}

//			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			blit (butter2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

		for ( k = 0 ; k <= FFH + 10 ; k = k + 5)//怪物擊傷
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