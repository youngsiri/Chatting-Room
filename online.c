#include "../include/message.h"

int online(int sockfd,struct message * msg)
{
    WINDOW *on_win;
    WINDOW *win;
    WINDOW *win1;

    	
    int ch;
    int x;
    int y;
    int i;

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    win = newwin(32,28,2,90);
    win1 = derwin(win,5,12,3,3);
    on_win = derwin(win,17,21,12,3);
    

    box(win,0,0);
    box(win1,0,0);
    box(on_win,0,0);

    keypad(on_win,TRUE);
                 
    mvwaddstr(win,1,3,"Echo");
    mvwaddstr(win,0,27,"X");
    mvwprintw(win,4,20,"%s",msg->name);
    mvwaddstr(win,9,2,"Group");
    mvwaddstr(win,11,2,"->I");
    //mvwaddstr(win,12,2,"->online friend");
    mvwaddstr(win,30,3,"help");
    
    mvwaddch(win1,2,2,'(');
    mvwaddch(win1,2,4,'^');
    mvwaddch(win1,2,6,'_');
    mvwaddch(win1,2,8,'^');
    mvwaddch(win1,2,10,')');

    mvwaddch(win,2,0,ACS_LTEE);
    mvwhline(win,2,1,ACS_HLINE,28);
    mvwaddch(win,2,27,ACS_RTEE);

    mvwaddch(win,8,0,ACS_LTEE);
    mvwhline(win,8,1,ACS_HLINE,28);
    mvwaddch(win,8,27,ACS_RTEE);
    mvwaddstr(win,9,1,"");

    refresh();
    wrefresh(win);
    
    touchwin(on_win);
    mvwaddstr(on_win,0,3,"online frined");
    mvwaddstr(on_win,15,2,"close");
    
   // while((msg->online)[i] != '\0')
   // {
      
       mvwprintw(on_win,2,3,"%s",(msg->online)[1]);
       mvwprintw(on_win,3,3,"%s",(msg->online)[2]);
       mvwprintw(on_win,4,3,"%s",(msg->online)[3]);
       mvwprintw(on_win,5,3,"%s",(msg->online)[4]);
       mvwprintw(on_win,6,3,"%s",(msg->online)[5]);
       mvwprintw(on_win,7,3,"%s",(msg->online)[6]);
    //i++;

    refresh();
    wrefresh(on_win);

    touchwin(on_win);

    i = 1;
    x = 1;
    y = 3;
    wmove(on_win,x,y);
    
    while((ch = getch())!= 27)
    {
	 switch(ch)
	 {
	     case '\n':
	     {    
	         if(x == 15 && y == 1)
		 {	
		     wclear(on_win);
		     wrefresh(on_win);
		     delwin(on_win);
		     endwin();
                     system("clear");
                      
		     Log(sockfd,msg);

		     return 0;

		 }
		 if(x == 2 && y == 2)
		 {
		     if((msg->online)[1] != '\0')
		     {
                         chat(sockfd,1,msg); 
			 touchwin(on_win);
			 wrefresh(on_win);

    			wclear(win);
    			wrefresh(win);
    			delwin(win);
    			endwin();

			return 0;

		//	new_s(sockfd,msg);
		     }
		   //  return 0;  
		     break;
		 }
		 if(x == 3 && y == 2)
		 {
		     if((msg->online)[2] != '\0')
		     {
		         chat(sockfd,2,msg);
			 wrefresh(on_win);
			 touchwin(on_win);

			 return 0;
		     } 

		    // chat_s(sockfd,msg);
		     break;
		 }

		 break;
	     }

	     case KEY_DOWN:
	     {
                 touchwin(on_win);
	         x++;
	         break;
	     }
	     case KEY_UP:
	     {
	         touchwin(on_win);
		 x--;
		 break;
	     }

	     case KEY_LEFT:
	     {
                 touchwin(on_win);
	         y--;
	         break;
	     }
	     case KEY_RIGHT:
	     {
	         touchwin(on_win);
		 y++;
		 break;
	     }	

	     case '/':
	     {
	     	wclear(on_win);
    		wrefresh(on_win);
    		delwin(on_win);
    		endwin();

		return 0;
	     }
	     
	 } 
	 touchwin(on_win);
 	 wmove(on_win,x,y);
	 wrefresh(on_win);

    } 

    wclear(win);
    wrefresh(win);
    delwin(win);
    endwin();
    system("clear");
    
    return 0;
}

