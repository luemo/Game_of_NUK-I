#include <allegro.h>
//#include "CO1.h"
//#include "BO1.h"
//#include "Road.h"
//#include "LO2_MO1.h"
//#include "LO1.h"
#include "College.h"
#include "system.h"
#include "Save.h"
#include "Cfont.h"
#include "Even_Speak.h"

volatile int close_button_pressed = FALSE;
void close_button_handler(void)
      {
         close_button_pressed = TRUE;
      } //    END_OF_FUNCTION(close_button_handler)

int main()
{
	allegro_init();
	install_keyboard();
	install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );

	init_Cfont();/*¤å¦r¨t²Î*/
///

	LOCK_FUNCTION(close_button_handler);
	set_close_button_callback(close_button_handler);
///
	set_window_title("NUK RPG");
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
   //  while (!close_button_pressed)
	// {
	int MAIN_CHOOSE = 1;
//while (close_button_pressed == FALSE)
//{
	MAIN_CHOOSE = Main_Menu();
//} 

readkey();
//	 }//END OF while (!close_button_pressed)
	close_Cfont();
	allegro_exit();

	 return 0;
}
END_OF_MAIN();
