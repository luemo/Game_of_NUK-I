#include <allegro.h>
#include "Fighting.h"

void OUR_Time(BITMAP *butter2, int Q[4][2], int n, int O[4][4], int M[3][2])//n = 我方人數
{/*#define One_MonsterW SCREEN_W/2-210/2		//一隻怪物所在之x值
#define Two_Monster1W SCREEN_W/2-210*3/2	//兩隻怪物中第一隻所在之x值
#define Two_Monster2W SCREEN_W/2+210/2		//兩隻怪物中第二隻所在之x值
#define MonsterW 210						//怪物寬
#define MonsterH 210						//怪物高
#define HPX_01 					//
#define HPX_02 					//
#define HPX_03 					//
#define HPX_04 					//
#define HPY 					//
#define HPW 12					//HP寬
#define HPH 19					//HP高
#define MPW 12					//MP寬
#define MPH 19					//MP高*/
	int i = 0;	//怪物位置
	int a = 0,b = 0,c = 0;//HP X貼位置
	int j = 0;	//怪物血值
	int A = 0,B = 0,C = 0;//減十個位數的血
	int k = 0;	//傷痕位置

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	BITMAP *Attack_M = load_bitmap ("image\\Fighting\\Attack2.bmp",NULL);//怪物圖
	BITMAP *HPMPList = load_bitmap ("image\\Fighting\\HP.MP.bmp",NULL);//怪物圖

	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	if (Q[n][1] == 0)	//一隻怪物			//被攻擊怪物的位置
	{i  = One_MonsterW;}
	else if (Q[n][1] == 1)	//兩隻怪物中第一隻
	{i  = Two_Monster1W;}
	else if (Q[n][1] == 2)	//兩隻怪物中第二隻
	{i  = Two_Monster2W;}

	a = i + MonsterW/4;
	b = a + MonsterW/4;
	c = b + MonsterW/4;

	j = Our_Attack(Q, O, M, n);


	A = HPW * 11;
	B = HPW * ( j / 10 );
	C = HPW * ( j % 10 );

	if (j != 0)
	{
		for ( k = 0 ; k <= MonsterH + 20 ; k = k + 20)//怪物擊傷
		{
				rest (50);
			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			masked_blit (Attack_M, butter, 0, 0, i, 0, MonsterW, k);
			masked_blit (HPMPList, butter, A, HPH, a, MonsterH/10 - k/10 , HPW, HPH);
			masked_blit (HPMPList, butter, B, HPH, b, MonsterH/10 - k/10 , HPW, HPH);
			masked_blit (HPMPList, butter, C, HPH, c, MonsterH/10 - k/10 , HPW, HPH);
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		}
	}

//	destroy_bitmap (butter);
//	destroy_bitmap (Attack_M);
//	return j;
}

int Our_Attack(int Q[4][2], int O[4][4], int M[3][2], int n)
{
	int j = 0;
	if (n == 0)
	{
		if (O[n][0] <= 0)
		{Q[n][0] = 0;
		Q[n][1] = 0;}
		else if (Q[n][0] == 1)	//怪物減血量
		{
			j  = 13;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 2)	
		{
			j  = 24;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 3)	
		{
			j  = 33;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 4)	
		{
			j  = 50;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
	}
	else if (n == 1)
	{
		if (O[n][0] <= 0)
		{Q[n][0] = 0;
		Q[n][1] = 0;}
		else if (Q[n][0] == 1)	//怪物減血量
		{
			j  = 11;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 2)	
		{
			j  = 20;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 3)	
		{
			j  = 28;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 4)	
		{
			j  = 40;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
	}
	else if (n == 2)
	{
		if (O[n][0] <= 0)
		{Q[n][0] = 0;
		Q[n][1] = 0;}
		else if (Q[n][0] == 1)	//怪物減血量
		{
			j  = 25;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 2)	
		{
			j  = 31;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 3)	
		{
			j  = 48;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 4)	
		{
			j  = 61;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
	}
	else if (n == 3)
	{
		if (O[n][0] <= 0)
		{Q[n][0] = 0;
		Q[n][1] = 0;}
		else if (Q[n][0] == 1)	//怪物減血量
		{
			j  = 20;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 2)	
		{
			j  = 26;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 3)	
		{
			j  = 35;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
		else if (Q[n][0] == 4)	
		{
			j  = 42;
			M[Q[n][1]][0] = M[Q[n][1]][0] - j;
		}
	}
	return j;
}
