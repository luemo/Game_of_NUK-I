#include <allegro.h>
#include "Fighting.h"

int Choose_Our_Skill(struct Fighting_All_Character FAC, BITMAP *butter2,int P, int O[4][4])//P為我方第幾個戰鬥人
{
	int n = 0,a = 0;	//暫存某人的HPMP + 回傳直(需+1)，回傳哪一技能
	int i = 0;	//技能選項的X貼點(哪一個人做選擇)
	int mp,hp;	//血量數字
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	BITMAP *Face = create_bitmap (FAC.character1.Skills_menu->w, FAC.character1.Skills_menu->h);
	BITMAP *Face2 = create_bitmap (FAC.character1.Skills_menu2->w, FAC.character1.Skills_menu2->h);
	BITMAP *HPMPList = load_bitmap ("image\\Fighting\\HP.MP.bmp",NULL);//血量表
	BITMAP *HPMP = create_bitmap (HPW*11, HPH);
	BITMAP *HPMP1 = create_bitmap (HPW*11, HPH);
	BITMAP *HPMP2 = create_bitmap (HPW*11, HPH);
	BITMAP *HPMP3 = create_bitmap (HPW*11, HPH);
	BITMAP *HPMP4 = create_bitmap (HPW*11, HPH);

	if (P == 0)
	{
		i = Our_FFX_01;
		Face = FAC.character1.Skills_menu;
		Face2 = FAC.character1.Skills_menu2;
	}
	else if (P == 1)
	{
		i = Our_FFX_02;
		Face = FAC.character2.Skills_menu;
		Face2 = FAC.character2.Skills_menu2;
	}
	else if (P == 2)
	{
		i = Our_FFX_03;
		Face = FAC.character3.Skills_menu;
		Face2 = FAC.character3.Skills_menu2;
	}
	else if (P == 3)
	{
		i = Our_FFX_04;
		Face = FAC.character4.Skills_menu;
		Face2 = FAC.character4.Skills_menu2;
	}
	for (n = 0; n <= FAC.Number ; n = n + 1)
	{
		hp = O[n][0] /10;
		blit (HPMPList, HPMP, HPW*hp, HPH, HPW*0, 0, HPW, HPH);//血量十
		hp = O[n][0] %10;
		blit (HPMPList, HPMP, HPW*hp, HPH, HPW*1, 0, HPW, HPH);//血量個
		blit (HPMPList, HPMP, HPW*12, HPH, HPW*2, 0, HPW, HPH);//"/"
		hp = O[n][2] /10;
		blit (HPMPList, HPMP, HPW*hp, HPH, HPW*3, 0, HPW, HPH);//最大血量十
		hp = O[n][2] %10;
		blit (HPMPList, HPMP, HPW*hp, HPH, HPW*4, 0, HPW, HPH);//最大血量個
		blit (HPMPList, HPMP, HPW*13, HPH, HPW*5, 0, HPW, HPH);//空格
		mp = O[n][1] /10;
		blit (HPMPList, HPMP, MPW*mp, MPH*2, MPW*6, 0, MPW, MPH);//MP十
		mp = O[n][1] %10;
		blit (HPMPList, HPMP, MPW*mp, MPH*2, MPW*7, 0, MPW, MPH);//MP個
		blit (HPMPList, HPMP, MPW*12, MPH*2, MPW*8, 0, MPW, MPH);//"/"
		mp = O[n][3] /10;
		blit (HPMPList, HPMP, MPW*mp, MPH*2, MPW*9, 0, MPW, MPH);//最大MP十
		mp = O[n][3] %10;
		blit (HPMPList, HPMP, MPW*mp, MPH*2, MPW*10, 0, MPW, MPH);//最大MP個

		if (n == 3)
		{blit (HPMP, HPMP4, 0, 0, 0, 0, HPMP->w, HPMP->h);}
		if (n == 2)
		{blit (HPMP, HPMP3, 0, 0, 0, 0, HPMP->w, HPMP->h);}
		if (n == 1)
		{blit (HPMP, HPMP2, 0, 0, 0, 0, HPMP->w, HPMP->h);}
		if (n == 0)
		{blit (HPMP, HPMP1, 0, 0, 0, 0, HPMP->w, HPMP->h);}
	}
	for (n = FAC.Number; n < 4 ; n = n + 1)
	{
		for (a = 0 ; a <= 11 ; a++)
		{
			blit (HPMPList, HPMP, HPW*13, HPH, HPW*a, 0, HPW, HPH);//空格
		}

		if (n == 3)
		{blit (HPMP, HPMP4, 0, 0, 0, 0, HPMP->w, HPMP->h);}
		if (n == 2)
		{blit (HPMP, HPMP3, 0, 0, 0, 0, HPMP->w, HPMP->h);}
		if (n == 1)
		{blit (HPMP, HPMP2, 0, 0, 0, 0, HPMP->w, HPMP->h);}
//		if (n == 0)
//		{blit (HPMP, HPMP1, 0, 0, 0, 0, HPMP->w, HPMP->h);}
	}

	n = 0;

	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	masked_blit (Face, butter, 0, 0, i, Our_FSY, FSW, FSH);
	masked_blit (Face2, butter, 0, Our_SY*n+10, i, Our_FSY + Our_SY*n+10, FSW, Our_SY);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	while (!key[KEY_SPACE])		//上下選技能
	{
		if (key[KEY_UP])
		{
			n = n - 1;
			if (n < 0)
			{n = 0;}
		}
		if (key[KEY_DOWN])
		{
			n = n + 1;
			if (n > 3)
			{n = 3;}
		}
		blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		masked_blit (Face, butter, 0, 0, i, Our_FSY, FSW, FSH);
		masked_blit (Face2, butter, 0, Our_SY*n+10, i, Our_FSY + Our_SY*n+10, FSW, Our_SY);
		masked_blit (HPMP1, butter, 0, 0, Our_FFX_01 + 16, SCREEN_H - HPMP1->h, HPMP1->w, HPMP1->h);
		masked_blit (HPMP2, butter, 0, 0, Our_FFX_02 + 16, SCREEN_H - HPMP2->h, HPMP2->w, HPMP2->h);
		masked_blit (HPMP3, butter, 0, 0, Our_FFX_03 + 16, SCREEN_H - HPMP3->h, HPMP3->w, HPMP3->h);
		masked_blit (HPMP4, butter, 0, 0, Our_FFX_04 + 16, SCREEN_H - HPMP4->h, HPMP4->w, HPMP4->h);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
				rest (50);
	}

//	destroy_bitmap (butter);
//	destroy_bitmap (Face);
//	destroy_bitmap (Face2);
//	destroy_bitmap (HPMPList);
//	destroy_bitmap (HPMP);
//	destroy_bitmap (HPMP1);
//	destroy_bitmap (HPMP2);
//	destroy_bitmap (HPMP3);
//	destroy_bitmap (HPMP4);
	return n + 1;
}
int Choose_Monster(struct Monster_All Boss, BITMAP *butter2, int M[3][2])
{
	int n = 0;	//回傳直，選擇打哪隻怪物
	int j = 0;	//若有兩隻怪物，則為選擇怪物的X貼點
	struct Monster No;
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	BITMAP *BossNo = load_bitmap ("image\\Monster\\MonsterChoose.bmp",NULL);//怪物圖
	BITMAP *BossNow =create_bitmap (BossNo->w, BossNo->h);//怪物圖
	No.character = BossNo;

	blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	if (Boss.Number == 1)	//一隻怪物
	{		
		while (!key[KEY_SPACE])
		{
			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			masked_blit (No.character, butter, 0, 0, One_MonsterW, 0, MonsterW, MonsterH);
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	//		rest (200);
			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			masked_blit (Boss.One.character, butter, 0, 0, One_MonsterW, 0, MonsterW, MonsterH);
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	//		rest (200);
		}
		n = 1;
	}
	else if (Boss.Number == 2)	//兩隻怪物，左邊為2，右邊為3(預設為2)
	{
		BossNow = Boss.Two.character;
		j = Two_Monster1W;
		n = 2;

		if (M[1][0] <= 0)
		{
			BossNow = Boss.Three.character;
			j = Two_Monster2W;
			n = 3;
		}
		while (!key[KEY_SPACE])
		{
			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			masked_blit (No.character, butter, 0, 0, j, 0, MonsterW, MonsterH);
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			//rest (200);
			blit (butter2, butter, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			masked_blit (BossNow, butter, 0, 0, j, 0, MonsterW, MonsterH);
			blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
			//rest (200);
			if (key[KEY_LEFT] && M[1][0] > 0)
			{
				BossNow = Boss.Two.character;
				j = Two_Monster1W;
				n = 2;
			}
			if (key[KEY_RIGHT] && M[2][0] > 0)
			{
				BossNow = Boss.Three.character;
				j = Two_Monster2W;
				n = 3;
			}
		}
	}
//	destroy_bitmap (butter);
//	destroy_bitmap (BossNo);
	return n - 1;
}
