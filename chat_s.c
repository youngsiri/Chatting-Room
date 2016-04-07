#include "../include/message.h"

int chat_s(int sockfd,struct message * msg)
{
    WINDOW * win;
    WINDOW * win1;
 //   WINDOW * win2;

    int c ;
    int x ;
    int y ;
    int p;
    int q;
    int ch;

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    win = newwin(32,28,2,90);
    win1 = derwin(win,5,12,3,3);

   // keypad(win,TRUE);
    
    box(win,0,0);
    box(win1,0,0);

    mvwaddstr(win,1,3,"Echo");
    mvwaddstr(win,0,27,"X");
    mvwprintw(win,4,20,"%s",msg->name);
    mvwaddstr(win,9,2,"Group");
    mvwaddstr(win,11,2,"->I");
    mvwaddstr(win,12,2,"->online friend");
    mvwaddstr(win,30,3,"help");

    mvwaddstr(win,10,2,"New messages!!!");
    
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

    keypad(win,TRUE);
    
    touchwin(win1);

    x = 9;
    y = 2;
    wmove(win1,x,y);

    while((c = getch()) != 27)
    {
        switch(c)
	{
	    case '\n':
	    {
                if(x == 12 && y == 1)   //online 
		{
		    msg->action = 3;
		    if(send(sockfd,msg,sizeof(struct message),0) == -1)
		    {
		        perror("send error !\n");
			pthread_exit(NULL);
		    }

		    wclear(win);
		    wrefresh(win);
		    delwin(win);
		    endwin();
		    system("clear");

		    return 0;
		
		}

		if(x == 10 && y == 1)
		{
		    
		    wclear(win);
		    wrefresh(win);
		    delwin(win);
		    endwin();
			
		    news(sockfd,msg);

		    return 0;
		//    chat_f(sockfd,msg);
                //    mvwaddstr(win,10,2,"            ");

	        //	    break;

		}
                
                if(x == 30 && y == 2)
		{
		    help();

		    wrefresh(win);
                   // system("clear");
		   // Log(sockfd,msg);
		    break;
		    
		}
                
                if(x == 0 && y == 26)
		{
		    msg->action = 11;
		    if(send(sockfd,msg,sizeof(struct message),0) == -1)
		    {
		        perror("send error !\n");
			pthread_exit(NULL);
		    }

		    wclear(win);
		    wrefresh(win);
		    delwin(win);
		    endwin();
		    system("clear");
                    exit(1);
		  //  return 0;
		}

	    }
            
	    case KEY_DOWN:
	    {
	        touchwin(win);
		x++;
		break;
	    }

	    case KEY_UP:
	    {
	        touchwin(win);
		x--;
		break;
	    }

	    case KEY_LEFT:
	    {
	        touchwin(win);
		y--;
		break;
	    }
	    case KEY_RIGHT:
	    {
	        touchwin(win);
		y++;
		break;
	    }
	}
	wmove(win,x,y);
	wrefresh(win);
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    endwin();
    system("clear");
    
    return 0;
}

