#include "../include/message.h"

int help(void)
{
	
    WINDOW * help_win;

    int x ;
    int y ;
    int ch;

    help_win = newwin(10,14,2,75);
    box(help_win,0,0);

    keypad(help_win,TRUE);

    mvwaddstr(help_win,1,2,"Version");
    mvwaddstr(help_win,3,2,"Back");
    mvwaddstr(help_win,5,2,"Set");
    mvwaddstr(help_win,7,2,"Exit");
    mvwaddstr(help_win,1,1,"");

    refresh();
    wrefresh(help_win);
                     
    x = 3;
    y = 1;
    wmove(help_win,x,y);
    while((ch = getch())!= 27)
    {
	 switch(ch)
	 {
	     case '\n':
	     {    
	         if(x == 7 && y == 1)
		 {	
		     wclear(help_win);
		     wrefresh(help_win);
		     delwin(help_win);
		     endwin();

		     return 1;
		 }
	     }

	     case KEY_DOWN:
	     {
                 touchwin(help_win);
	         x++;
	         break;
	     }
	     case KEY_UP:
	     {
	         touchwin(help_win);
		 x--;
		 break;
	     }

	     case KEY_LEFT:
	     {
                 touchwin(help_win);
	         y++;
	         break;
	     }
	     case KEY_RIGHT:
	     {
	         touchwin(help_win);
		 y--;
		 break;
	     }	
	 } 
 	 wmove(help_win,x,y);
	 wrefresh(help_win);
    }
    wclear(help_win);
    wrefresh(help_win);
    delwin(help_win);
    endwin();

    return 0;
}
