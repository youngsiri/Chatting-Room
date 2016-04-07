#include "../include/message.h"

int log_success(int sockfd,struct  message *  msg)
{
    WINDOW * my_win;
    	
    int ch;
    int x;
    int y;
    my_win = newwin(10,25,10,50);

    box(my_win,0,0);

    keypad(my_win,TRUE);
                 
    mvwaddstr(my_win,1,5,"Log Success!!!");		  
    
    mvwprintw(my_win,4,4,"The name : %s",msg->name);		  
 //   mvwprintw(my_win,5,3,"The ID is:%d",msg->id);
   
    refresh();
    wrefresh(my_win);

    sleep(3);
    wclear(my_win);
    wrefresh(my_win);
    delwin(my_win);
    endwin();
    
    system("clear");
    Log(sockfd,msg);

    return 0;
}
