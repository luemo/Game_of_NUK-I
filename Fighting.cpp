#include <allegro.h>
#include "Fighting.h"
#include <stdio.h>

//void Choose (BITMAP *butter,struct Fighting_All_Character FAC, struct Monster_All Boss, int Q[4][2],int O[4][4]);


int Fighting(struct Fighting_All_Character FAC, struct Monster_All Boss, BITMAP *butter2, int MonsterAct){
	int n = 0,i = 0;
	int Q[4][2] = {{0,0},{0,0},{0,0},{0,0}};//4為我方戰鬥人數最高4人;2為第幾技能(0)與哪隻怪物(1)
	int OurValue[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int MonsterValue[3][2] = {{0,0},{0,0},{0,0}};
	int WIN = 0;//贏為0輸為1
//	FILE *BBB;    
//	BBB=fopen("BBB.txt","a");
//	fprintf (BBB,"FAC.Number = (%d)\n",FAC.Number);
//	fclose(BBB);


	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	BITMAP *butter3 = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


	Change_HP (FAC, Boss, OurValue, MonsterValue);
	for (;;)
	{
		blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
//怪物貼圖
	masked_blit (Boss.One.character, butter, 0, 0, One_MonsterW, 0, MonsterW, MonsterH);
	masked_blit (Boss.Two.character, butter, 0, 0, Two_Monster1W, 0, MonsterW, MonsterH);
	masked_blit (Boss.Three.character, butter, 0, 0, Two_Monster2W, 0, MonsterW, MonsterH);
//人臉貼圖
	masked_blit (FAC.character1.character, butter, 0, 0, Our_FFX_01, Our_FFY, FFW, FFH);
	masked_blit (FAC.character2.character, butter, 0, 0, Our_FFX_02, Our_FFY, FFW, FFH);
	masked_blit (FAC.character3.character, butter, 0, 0, Our_FFX_03, Our_FFY, FFW, FFH);
	masked_blit (FAC.character4.character, butter, 0, 0, Our_FFX_04, Our_FFY, FFW, FFH);

	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	n = 0;

	Choose (butter,FAC,Boss,Q,OurValue, MonsterValue);	//決定技能&怪物

//		fprintf (BBB,"M[0] = (%d)\n",MonsterValue[0][0]);
//		fprintf (BBB,"M[1] = (%d)\n",MonsterValue[1][0]);
//		fprintf (BBB,"M[2] = (%d)\n",MonsterValue[2][0]);
//		fprintf (BBB,"\n");
	n = 0;
	while (n < FAC.Number)		//n必定小於參戰人數
	{
		OUR_Time(butter, Q, n,  OurValue, MonsterValue);	//我方攻擊
			rest (1000);
		i = Q[n][1];
		n = n + 1;
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	}
//			fprintf (BBB,"M[0] = (%d)\n",MonsterValue[0][0]);
//			fprintf (BBB,"M[1] = (%d)\n",MonsterValue[1][0]);
//			fprintf (BBB,"M[2] = (%d)\n",MonsterValue[2][0]);
	n = 0;
//			fclose(BBB);
//			fprintf (BBB,"\n");

	while (n < 3)		//n必定小於參戰怪物
	{
		if (MonsterValue[n][0] > 0)	//怪物死掉不可攻擊，當MonsterValue[n] < 0
		{
				rest (1000);
			Monster_Time(butter, FAC.Number, OurValue, MonsterValue, n);	//怪物攻擊
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		}
		n = n + 1;
	}
	if (MonsterValue[1][0] <= 0 && MonsterValue[0][0] == 0)
	{
		Boss.Two.character = Boss.One.character;
	}
	if (MonsterValue[2][0] <= 0 && MonsterValue[0][0] == 0)
	{
		Boss.Three.character = Boss.One.character;
	}
//	for(i=0;i<4;i++)
//	{
//		fprintf (BBB,"O[%d] = (%d,%d,%d,%d)\n",i,OurValue[i][0],OurValue[i][1],OurValue[i][2],OurValue[i][3]);
//	}
//		fprintf (BBB,"\n");
//	for(i=0;i<3;i++)
//	{
//		fprintf (BBB,"M[%d] = (%d)\n",i,MonsterValue[i][0]);
//	}
//		fprintf (BBB,"\n\n");
//		fclose(BBB);


 	if (OurValue[0][0]<=0 && OurValue[1][0]<=0 && OurValue[2][0]<=0 && OurValue[3][0]<=0 )
	{
//	fclose(BBB);
		WIN = 1;
		break;
	}
	if (MonsterValue[0][0]<=0 && MonsterValue[1][0]<=0 && MonsterValue[2][0]<=0)
	{
//	fclose(BBB);
		WIN = 0;
		break;
	}

	}
//	destroy_bitmap (butter);
//	destroy_bitmap (butter3);
	return 	WIN;
}

void Choose (BITMAP *butter,struct Fighting_All_Character FAC, struct Monster_All Boss, int Q[4][2],int O[4][4], int M[3][2])	//M[]怪物HP; O[][0] = 我們HP; O[][1] = 我們MP; O[][3] = 我們HPmax; O[][4] = 我們MPmax
{
//	FILE *AAA;    
//	AAA=fopen("AAA.txt","w");
//	fprintf (AAA,"FAC.Number = (%d)\n",FAC.Number);
//	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器

	int n = 0;
	if (FAC.Number >= 1 )		//n必定小於參戰人數
	{
		while (n == 0)
		{
			if (O[0][0] <= 0)
			{O[0][0] = 0;
			n = n + 1;
			continue;}
			Q[0][0] = Choose_Our_Skill(FAC, butter,n, O);	//決定技能
				rest (100);
			Q[0][1] = Choose_Monster(Boss, butter, M);		//決定怪物
			n = n + 1;
		}
				rest (100);
//		fprintf (AAA,"Q[0] = (%d,%d)\n",Q[0][0],Q[0][1]);
	}
	if (FAC.Number >= 2 )		//n必定小於參戰人數
	{
		while (n == 1)
		{
			if (O[1][0] <= 0)
			{O[1][0] = 0;
			n = n + 1;
			continue;}
			Q[1][0] = Choose_Our_Skill(FAC, butter,n, O);	//決定技能
				rest (100);
			Q[1][1] = Choose_Monster(Boss, butter, M);		//決定怪物
			n = n + 1;
		}
				rest (100);
//		fprintf (AAA,"Q[1] = (%d,%d)\n",Q[1][0],Q[1][1]);
	}
 	if (FAC.Number >= 3 )		//n必定小於參戰人數
	{
		while (n == 2)
		{
			if (O[2][0] <= 0)
			{O[2][0] = 0;
			n = n + 1;
			continue;}
			Q[2][0] = Choose_Our_Skill(FAC, butter,n, O);	//決定技能
				rest (100);
			Q[2][1] = Choose_Monster(Boss, butter, M);		//決定怪物
			n = n + 1;
		}
				rest (100);
//		fprintf (AAA,"Q[2] = (%d,%d)\n",Q[2][0],Q[2][1]);
	}
	if (FAC.Number >= 4 )		//n必定小於參戰人數
	{
		while (n == 3)
		{
			if (O[3][0] <= 0)
			{O[3][0] = 0;
			n = n + 1;
			continue;}
			Q[3][0] = Choose_Our_Skill(FAC, butter,n, O);	//決定技能
				rest (100);
			Q[3][1] = Choose_Monster(Boss, butter, M);		//決定怪物
			n = n + 1;
		}
				rest (100);
//		fprintf (AAA,"Q[3] = (%d,%d)\n",Q[3][0],Q[3][1]);
	}	
	
//	fclose(AAA);
//	destroy_bitmap (butter);

}






void Change_HP (struct Fighting_All_Character FAC, struct Monster_All Boss, int O[4][4], int M[3][2])	//M[]怪物HP; O[][0] = 我們HP; O[][1] = 我們MP; O[][3] = 我們HPmax; O[][4] = 我們MPmax
{
//	FILE *Input;    
//	Input=fopen("Output.txt","w");
	int i = 0;

	M[0][0] = Boss.One.HP;
	M[0][1] = Boss.One.MP;
	O[0][0] = FAC.character1.HP;
	O[0][1] = FAC.character1.MP;
	O[0][2] = FAC.character1.HPMAX;
	O[0][3] = FAC.character1.MPMAX;

	M[1][0] = Boss.Two.HP;
	M[1][1] = Boss.Two.MP;
	O[1][0] = FAC.character2.HP;
	O[1][1] = FAC.character2.MP;
	O[1][2] = FAC.character2.HPMAX;
	O[1][3] = FAC.character2.MPMAX;

	M[2][0] = Boss.Three.HP;
	M[2][1] = Boss.Three.MP;
	O[2][0] = FAC.character3.HP;
	O[2][1] = FAC.character3.MP;
	O[2][2] = FAC.character3.HPMAX;
	O[2][3] = FAC.character3.MPMAX;

	O[3][0] = FAC.character4.HP;
	O[3][1] = FAC.character4.MP;
	O[3][2] = FAC.character4.HPMAX;
	O[3][3] = FAC.character4.MPMAX;
//	for(i=0;i<4;i++)
//	{
//		fprintf (Input,"O[%d] = (%d,%d,%d,%d)\n",i,O[i][0],O[i][1],O[i][2],O[i][3]);
//	}
//	for(i=0;i<3;i++)
//	{
//		fprintf (Input,"M[%d] = (%d)\n",i,M[i][0]);
//	}
//	fclose(Input);
}


