#include <allegro.h>
#include "people_work.h"


void walking (int *X, int *Y, int *last, BITMAP *character, BITMAP *butter2, BITMAP *barrier)//3�W0�U1��2�k
{int A,i = 0,j = 0,k = 0,l = 0,n=1;//1.�N��Ӥj�a��(butter2)�����E�����A�H��ɨ�1/2�e�����ɽu����
				 //2.i = �j�a��(butter2)��X�K�I;j = �j�a��(butter2)��Y�K�I;k = �H��X�K�I;l = �H��Y�K�I;n = �H��(player.character)�������K�I����
	BITMAP *butter = create_bitmap (SCREEN_W, SCREEN_H);
	rest(50);
//	blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	if (key[KEY_UP] && *last == 3)		//PeopleH*3
	{
		*Y = *Y - PeopleH;
		l = *Y + PeopleH/2;
		for ( A = 0 ; A < PeopleH ; A++ )
		{
			if ((l-A) >= 0 && barrier->line[l-A][(*X) * 3 + 0] == 0 && barrier->line[l-A][(*X) * 3 + 1] == 0 && barrier->line[l-A][(*X) * 3 + 2] == 255)
			{*Y = *Y + PeopleH;
			 break;}
		}

		if (*Y < PeopleH/2)//�p�G�W�L�W��ɫh�]���̤W
		{
			*Y = PeopleH/2;
		}
	}	//end of key[KEY_UP]

	if (key[KEY_DOWN] && *last == 0)		//PeopleH*0
	{
		*Y = *Y + PeopleH;
		l = *Y - PeopleH/2;
		for ( A = 0 ; A < PeopleH ; A++ )
		{
			if ((l+A) < barrier->h && barrier->line[l+A][(*X) * 3 + 0] == 0 && barrier->line[l+A][(*X) * 3 + 1] == 0 && barrier->line[l+A][(*X) * 3 + 2] == 255)
			{*Y = *Y - PeopleH;
			 break;}
		}

		if (*Y > butter2->h - PeopleH/2)//�p�G�W�L�U��ɫh�]���̤U - �H����/2
		{
			*Y = butter2->h - PeopleH/2;
		}
	}	//end of key[KEY_DOWN]
	if (key[KEY_LEFT] && *last == 1)		//PeopleH*1
	{
		*X = *X - PeopleW;
		k = *X + PeopleW/2;
		for ( A = 0 ; A < PeopleW ; A++ )
		{
			if ((k-A) >= 0 && barrier->line[*Y][(k-A) * 3 + 0] == 0 && barrier->line[*Y][(k-A) * 3 + 1] == 0 && barrier->line[*Y][(k-A) * 3 + 2] == 255)
			{*X = *X + PeopleW;
			 break;}
		}


		if (*X < PeopleW/2)//�p�G�W�L����ɫh�]���̥�
		{
			*X = PeopleW/2;
		}
	}	//end of key[KEY_LEFT]
	if (key[KEY_RIGHT] && *last == 2)		//PeopleH*2
	{
		*X = *X + PeopleW;
		k = *X - PeopleW/2;
		for ( A = 0 ; A < PeopleW ; A++ )
		{
			if ((k+A) < barrier->w && barrier->line[*Y][(k+A) * 3 + 0] == 0 && barrier->line[*Y][(k+A) * 3 + 1] == 0 && barrier->line[*Y][(k+A) * 3 + 2] == 255)
			{*X = *X - PeopleW;
			 break;}
		}

		if (*X > butter2->w - PeopleW/2)//�p�G�W�L�k��ɫh�]���̥k - �H���e
		{
			*X = butter2->w - PeopleW/2;
		}

	}	//end of key[KEY_RIGHT]

	if (key[KEY_UP] && *last != 3)	//���V
	{*last = 3;}
	if (key[KEY_DOWN] && *last != 0)
	{*last = 0;}
	if (key[KEY_LEFT] && *last != 1)
	{*last = 1;}
	if (key[KEY_RIGHT] && *last != 2)
	{*last = 2;}



		if ((*Y) >= 0 && (*Y) <= SCREEN_H/2)			//���E��ӶK��(�����I���j�a����� - �����j�p/2)
		{	j = 0;
			l = (*Y) - PeopleH/2;}
		else if ((*Y) > SCREEN_H/2 && (*Y) < butter2->h - SCREEN_H/2)
		{	j = (*Y) - SCREEN_H/2;
			l = SCREEN_H/2 - PeopleH/2;}
		else if ((*Y) >= butter2->h - SCREEN_H/2 && (*Y) <= butter2->h)
		{	j = butter2->h - SCREEN_H;
			l = SCREEN_H - (butter2->h - (*Y)) - PeopleH/2;}
		if ((*X) >= 0 && (*X) <= SCREEN_W/2)
		{	i = 0;
			k = (*X) - PeopleW/2;}
		else if ((*X) > SCREEN_W/2 && (*X) < butter2->w - SCREEN_W/2)
		{	i = (*X) - SCREEN_W/2;
			k = SCREEN_W/2 - PeopleW/2;}
		else if ((*X) >= butter2->w - SCREEN_W/2 && (*X) <= butter2->w - PeopleW/2)
		{	i = butter2->w - SCREEN_W;
			k = SCREEN_W - (butter2->w - (*X)) - PeopleW/2;}


		blit (butter2, butter, i, j, 0, 0, SCREEN_W, SCREEN_H);
		masked_blit (character, butter, PeopleW*(n%3), PeopleH*(*last), k, l, PeopleW, PeopleH);
		blit (butter, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	destroy_bitmap (butter);
}


