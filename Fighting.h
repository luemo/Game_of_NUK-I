#define One_MonsterW SCREEN_W/2-210/2		//�@���Ǫ��Ҧb��x��
#define Two_Monster1W SCREEN_W/2-210*3/2	//�Ⱖ�Ǫ����Ĥ@���Ҧb��x��
#define Two_Monster2W SCREEN_W/2+210/2		//�Ⱖ�Ǫ����ĤG���Ҧb��x��
#define MonsterW 210						//�Ǫ��e
#define MonsterH 210						//�Ǫ���
#define Our_FFX_01 160*0		//Our_Fighting_Face X�y��
#define Our_FFX_02 160*1		//Our_Fighting_Face X�y��
#define Our_FFX_03 160*2		//Our_Fighting_Face X�y��
#define Our_FFX_04 160*3		//Our_Fighting_Face X�y��
#define Our_FFY SCREEN_H-160	//Our_Fighting_Face Y�y��
#define Our_FSY SCREEN_H-240	//Our_Fighting_Skills_menu Y�y��
#define Our_SY 25				//Our_Fighting_Skills_menu2 Y�y��
#define FFH 160					//�y�ϰ�
#define FFW 160					//�y�ϼe
#define FSH 300					//�ޯప
#define FSW 160					//�ޯ�e
#define HPX_01 					//
#define HPX_02 					//
#define HPX_03 					//
#define HPX_04 					//
#define HPY 					//
#define HPW 12					//HP�e
#define HPH 19					//HP��
#define MPW 12					//MP�e
#define MPH 19					//MP��*/
//12*19(�Ʀr�j�p)

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
	struct Fighting_All_Character FAC;	//�ڤ�ѾԤH��

	struct Monster Boss01;
	struct Monster Boss02;
	struct Monster Boss03;
	struct Monster BossNo;
	struct Monster_All Boss;//�Ǫ�
*/
/***********************************************************************************/
int Fighting(struct Fighting_All_Character FAC, struct Monster_All Boss, BITMAP *butter2, int MonsterAct);
void Choose (BITMAP *butter,struct Fighting_All_Character FAC, struct Monster_All Boss, int Q[4][2],int O[4][4], int M[3][2]);
int Choose_Our_Skill(struct Fighting_All_Character FAC, BITMAP *butter2, int P, int O[4][4]);//P���ڤ�ĴX�Ӿ԰��H
int Choose_Monster(struct Monster_All Boss, BITMAP *butter2, int M[3][2]);
void OUR_Time(BITMAP *butter2, int Q[4][2], int n, int O[4][4], int M[3][2]);
void Monster_Time(BITMAP *butter2, int n, int O[4][4], int M[3][2], int MonsterAct);
void Change_HP (struct Fighting_All_Character FAC, struct Monster_All Boss, int O[4][4], int M[3][2]);	//M[]�Ǫ�HP; O[][0] = �ڭ�HP; O[][1] = �ڭ�MP; O[][3] = �ڭ�HPmax; O[][4] = �ڭ�MPmax
int Our_Attack(int Q[4][2], int O[4][4], int M[3][2], int n);