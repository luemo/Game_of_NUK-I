#include <allegro.h>
#include "Cfont.h"

int Print_words(BITMAP *character_face, int line){
	BITMAP *Word=create_bitmap(400,100);		//////////////////////////////////
	BITMAP *Speak2 = create_bitmap ( 640 , 156 );
	BITMAP *Speak = load_bitmap ("image\\SPEAK.bmp" , NULL );
	clear_to_color(Word,makecol(0,0,0));		//////////////////////////////////
	/*print_cfont(BITMAP的指標,X位置,Y位置,字顏色的R,字顏色的G,字顏色的B,要顯示的列數編碼);*/
//	print_cfont(buffer,10,10,0,255,255,6);	//EX
	blit ( Speak, Speak2, 0, 0, 0, 0, Speak->w, Speak->h );
//	masked_blit ( character_face, Speak2, 0, 0, 35, 35, character_face->w, character_face->h );
	masked_blit ( character_face, Speak2, 0, 0, 0, 0, character_face->w, character_face->h );
	print_cfont(Speak2, 150, 30, 255, 255, 255, line);
	blit ( Speak2, screen, 0, 0, 0, 480 - 156, Speak->w, Speak->h );
//	masked_blit(buffer,screen,0,0,0,0,640,480);
	rest(250);
	while (!key[KEY_SPACE]){}
	destroy_bitmap (Speak);
	destroy_bitmap (Speak2);
	destroy_bitmap (Word);						//////////////////////////////////
	return 0;
}
