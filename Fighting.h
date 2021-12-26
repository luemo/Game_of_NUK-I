#define One_MonsterW SCREEN_W/2-210/2		//一隻怪物所在之x值
#define Two_Monster1W SCREEN_W/2-210*3/2	//兩隻怪物中第一隻所在之x值
#define Two_Monster2W SCREEN_W/2+210/2		//兩隻怪物中第二隻所在之x值
#define MonsterW 210						//怪物寬
#define MonsterH 210						//怪物高
#define Our_FFX_01 160*0		//Our_Fighting_Face X座標
#define Our_FFX_02 160*1		//Our_Fighting_Face X座標
#define Our_FFX_03 160*2		//Our_Fighting_Face X座標
#define Our_FFX_04 160*3		//Our_Fighting_Face X座標
#define Our_FFY SCREEN_H-160	//Our_Fighting_Face Y座標
#define Our_FSY SCREEN_H-240	//Our_Fighting_Skills_menu Y座標
#define Our_SY 25				//Our_Fighting_Skills_menu2 Y座標
#define FFH 160					//臉圖高
#define FFW 160					//臉圖寬
#define FSH 300					//技能高
#define FSW 160					//技能寬
#define HPX_01 					//
#define HPX_02 					//
#define HPX_03 					//
#define HPX_04 					//
#define HPY 					//
#define HPW 12					//HP寬
#define HPH 19					//HP高
#define MPW 12					//MP寬
#define MPH 19					//MP高*/
//12*19(數字大小)

struct Fighting_Character {
	BITMAP *character;
	BITMAP *Skills_menu;
	BITMAP *Skills_menu2;
	int HP;
	int MP;
	int HPMAX;
	int MPMAX;
};
struct Fighting_All_Character {
	int Number;
	struct Fighting_Character character1;
	struct Fighting_Character character2;
	struct Fighting_Character character3;
	struct Fighting_Character character4;
};
struct Monster {
	BITMAP *character;
	int HP;
	int MP;
};
struct Monster_All {
	int Number;
	struct Monster One;
	struct Monster Two;
	struct Monster Three;
};

/*	struct Fighting_Character Character01;
	struct Fighting_Character Character02;
	struct Fighting_Character Character03;
	struct Fighting_Character Character04;
	struct Fighting_Character CharacterNo;
	struct Fighting_All_Character FAC;	//我方參戰人員

	struct Monster Boss01;
	struct Monster Boss02;
	struct Monster Boss03;
	struct Monster BossNo;
	struct Monster_All Boss;//怪物
*/
/***********************************************************************************/
int Fighting(struct Fighting_All_Character FAC, struct Monster_All Boss, BITMAP *butter2, int MonsterAct);
void Choose (BITMAP *butter,struct Fighting_All_Character FAC, struct Monster_All Boss, int Q[4][2],int O[4][4], int M[3][2]);
int Choose_Our_Skill(struct Fighting_All_Character FAC, BITMAP *butter2, int P, int O[4][4]);//P為我方第幾個戰鬥人
int Choose_Monster(struct Monster_All Boss, BITMAP *butter2, int M[3][2]);
void OUR_Time(BITMAP *butter2, int Q[4][2], int n, int O[4][4], int M[3][2]);
void Monster_Time(BITMAP *butter2, int n, int O[4][4], int M[3][2], int MonsterAct);
void Change_HP (struct Fighting_All_Character FAC, struct Monster_All Boss, int O[4][4], int M[3][2]);	//M[]怪物HP; O[][0] = 我們HP; O[][1] = 我們MP; O[][3] = 我們HPmax; O[][4] = 我們MPmax
int Our_Attack(int Q[4][2], int O[4][4], int M[3][2], int n);