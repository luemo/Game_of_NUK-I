#include <allegro.h>
#include "Fighting.h"
#include "system.h"

int Fight_CEE(SAMPLE *Music)
{
	BITMAP *background = load_bitmap ("image\\Fighting\\break.bmp",NULL);//戰鬥背景

	BITMAP *butter2 = create_bitmap (SCREEN_W, SCREEN_H);//螢幕暫存器
	blit (background, butter2, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	blit (butter2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	int WIN = 0;//贏為0輸為1;

	struct Fighting_Character Character01;
	BITMAP *characterFace01 = load_bitmap ("image\\Face\\EE.bmp",NULL);//臉圖
	BITMAP *characterSkills01 = load_bitmap ("image\\Fighting\\EEattack1.bmp",NULL);//技能選單(黑)
	BITMAP *characterSkillschoose01 = load_bitmap ("image\\Fighting\\EEattack2.bmp",NULL);//技能選單(白)
	Character01.character = characterFace01;
	Character01.Skills_menu = characterSkills01;
	Character01.Skills_menu2 = characterSkillschoose01;

	struct Fighting_Character Character02;
	BITMAP *characterFace02 = load_bitmap ("image\\Face\\WL.bmp",NULL);//臉圖
	BITMAP *characterSkills02 = load_bitmap ("image\\Fighting\\WLattack1.bmp",NULL);//技能選單(黑)
	BITMAP *characterSkillschoose02 = load_bitmap ("image\\Fighting\\WLattack2.bmp",NULL);//技能選單(紅)
	Character02.character = characterFace02;
	Character02.Skills_menu = characterSkills02;
	Character02.Skills_menu2 = characterSkillschoose02;

	struct Fighting_Character Character03;
	BITMAP *characterFace03 = load_bitmap ("image\\Face\\LAW.bmp",NULL);//臉圖
	BITMAP *characterSkills03 = load_bitmap ("image\\Fighting\\LAWattack1.bmp",NULL);//技能選單(黑)
	BITMAP *characterSkillschoose03 = load_bitmap ("image\\Fighting\\LAWattack2.bmp",NULL);//技能選單(紅)
	Character03.character = characterFace03;
	Character03.Skills_menu = characterSkills03;
	Character03.Skills_menu2 = characterSkillschoose03;

	struct Fighting_Character Character04;
	BITMAP *characterFace04 = load_bitmap ("image\\Face\\AM.bmp",NULL);//臉圖
	BITMAP *characterSkills04 = load_bitmap ("image\\Fighting\\AMattack1.bmp",NULL);//技能選單(黑)
	BITMAP *characterSkillschoose04 = load_bitmap ("image\\Fighting\\AMattack2.bmp",NULL);//技能選單(紅)
	Character04.character = characterFace04;
	Character04.Skills_menu = characterSkills04;
	Character04.Skills_menu2 = characterSkillschoose04;

	struct Fighting_Character CharacterNo;
	BITMAP *characterFaceNo = load_bitmap ("image\\Face\\FaceNo.bmp",NULL);//臉圖

	CharacterNo.character = characterFaceNo;


	struct Fighting_All_Character FAC;	//我方參戰人員
	FAC.Number = 2;
	FAC.character1 = Character01;
	FAC.character1.HPMAX = 25;
	FAC.character1.HP = 25;
	FAC.character1.MPMAX = 23;
	FAC.character1.MP = 23;
	FAC.character2 = Character02;
	FAC.character2.HPMAX = 20;
	FAC.character2.HP = 20;
	FAC.character2.MPMAX = 17;
	FAC.character2.MP = 17;
	FAC.character3 = Character03;
	FAC.character3.HPMAX = 0;
	FAC.character3.HP = 0;
	FAC.character3.MPMAX = 0;
	FAC.character3.MP = 0;
	FAC.character4 = Character04;
	FAC.character4.HPMAX = 0;
	FAC.character4.HP = 0;
	FAC.character4.MPMAX = 0;
	FAC.character4.MP = 0;

	FAC.character3 = CharacterNo;
	FAC.character4 = CharacterNo;

/****************************************************************************************/

	struct Monster Boss01;
	BITMAP *BossBIT01 = load_bitmap ("image\\Monster\\CEEbattle.bmp",NULL);//怪物圖
	Boss01.character = BossBIT01;

	struct Monster Boss02;
	BITMAP *BossBIT02 = load_bitmap ("image\\Monster\\IMbattle.bmp",NULL);//怪物圖
	Boss02.character = BossBIT02;

	struct Monster Boss03;
	BITMAP *BossBIT03 = load_bitmap ("image\\Monster\\ECONbattle.bmp",NULL);//怪物圖
	Boss03.character = BossBIT03;

	struct Monster BossNo;
	BITMAP *BossBITNo = load_bitmap ("image\\Monster\\MonsterNO.bmp",NULL);//怪物圖
	BossNo.character = BossBITNo;

	struct Monster_All Boss;//怪物
	Boss.Number = 1;	//一隻怪物
	Boss.One = Boss01;
	Boss.Two = BossNo;
	Boss.Three = BossNo;
	Boss.One.HP = 350;
	Boss.Two.HP = 0;
	Boss.Three.HP = 0;
	Boss.One.MP = 9;
	Boss.Two.MP = 0;
	Boss.Three.MP = 0;

	WIN = Fighting(FAC, Boss, butter2,10);

	if (WIN == 1)
	{
		Death();
		stop_sample(Music);
		destroy_sample (Music);
		Main_Menu();
	}
/*	destroy_bitmap (background);
	destroy_bitmap (butter2);
	destroy_bitmap (characterFace01);
	destroy_bitmap (characterSkills01);
	destroy_bitmap (characterSkillschoose01);
	destroy_bitmap (characterFace02);
	destroy_bitmap (characterSkills02);
	destroy_bitmap (characterSkillschoose02);
	destroy_bitmap (characterFace03);
	destroy_bitmap (characterSkills03);
	destroy_bitmap (characterSkillschoose03);
	destroy_bitmap (characterFace04);
	destroy_bitmap (characterSkills04);
	destroy_bitmap (characterSkillschoose04);
	destroy_bitmap (characterFaceNo);
	destroy_bitmap (characterSkillsNo);
	destroy_bitmap (characterSkillschooseNo);
	destroy_bitmap (BossBIT01);
	destroy_bitmap (BossBITNo);
*/
	return 0;
}
