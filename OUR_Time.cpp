#include <allegro.h>
#include "Fighting.h"

void OUR_Time(BITMAP *butter2, int Q[4][2], int n, int O[4][4], int M[3][2])//n = �ڤ�H��
{/*#define One_MonsterW SCREEN_W/2-210/2		//�@���Ǫ��Ҧb��x��
#define Two_Monster1W SCREEN_W/2-210*3/2	//�Ⱖ�Ǫ����Ĥ@���Ҧb��x��
#define Two_Monster2W SCREEN_W/2+210/2		//�Ⱖ�Ǫ����ĤG���Ҧb��x��
#define MonsterW 210						//�Ǫ��e
#define MonsterH 210						//�Ǫ���
#define HPX_01 					//
#define HPX_02 					//
#define HPX_03 					//
#define HPX_04 					//
#define HPY 					//
#define HPW 12					//HP�e
#define HPH 19					//HP��
#define MPW 12					//MP�e
#define MPH 19					//MP��*/
	int i = 0;	//�Ǫ���m
	int a = 0,b = 0,c = 0;//HP X�K��m
	int j = 0;	//�Ǫ����
	int A = 0,B = 0,C = 0;//��Q�Ӧ�ƪ���
	int k = 0;	//�˲���m

	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//�ù��Ȧs��
	BITMAP *Attack_M = load_bitmap ("image\\Fighting\\Attack2.bmp",NULL);//�Ǫ���
	BITMAP *HPMPList = load_bitmap ("image\\Fighting\\HP.MP.bmp",NULL);//�Ǫ���

	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	if (Q[n][1] == 0)	//�@���Ǫ�			//�Q�����Ǫ�����m
	{i  = One_MonsterW;}
	else if (Q[n][1] == 1)	//�Ⱖ�Ǫ����Ĥ@��
	{i  = Two_Monster1W;}
	else if (Q[n][1] == 2)	//�Ⱖ�Ǫ����ĤG��
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
		for ( k = 0 ; k <= MonsterH + 20 ; k = k + 20)//�Ǫ�����
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
		else if (Q[n][0] == 1)	//�Ǫ����q
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
		else if (Q[n][0] == 1)	//�Ǫ����q
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
		else if (Q[n][0] == 1)	//�Ǫ����q
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
		else if (Q[n][0] == 1)	//�Ǫ����q
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
