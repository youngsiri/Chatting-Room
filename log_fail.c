#include "../include/message.h"

int log_fail(void)
{
    WINDOW * my_win;
    	
    int ch;
    int x;
    int y;
    my_win = newwin(10,25,10,50);

    box(my_win,0,0);

    keypad(my_win,TRUE);
                 
    mvwaddstr(my_win,1,5,"Log Fail!!!");		  
    
    mvwaddstr(my_win,5,3,"The name isn't regest!!");
   
 //   refresh();
    wrefresh(my_win);

    sleep(3);
    touchwin(my_win);
    wclear(my_win);
    wrefresh(my_win);
    delwin(my_win);
    endwin();
    
   // face(sockfd);
}
