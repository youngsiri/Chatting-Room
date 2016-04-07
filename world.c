#include "../include/message.h"

int face(int sockfd)
{
    WINDOW * my_win;
    WINDOW * my_win1;
    WINDOW * win1;
    WINDOW * win2;
    WINDOW * win3;
    WINDOW * win4;
    WINDOW * win5;

    struct message *usr = (struct message *)malloc(sizeof(struct message));

    memset(usr,0,sizeof(struct message));

    int i;
    int c;
    int x ;
    int y ;
    int temp;
    char str[1023] = {0};
    char ptr[1024] = {0};

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

loop:   my_win = newwin(25,60,4,25);
    win1 = derwin(my_win,3,20,5,24);
    win2 = derwin(my_win,3,20,8,24);

    keypad(my_win,TRUE);

    box(my_win,0,0);
    box(win1,0,0);
    box(win2,0,0);
   
    mvwaddstr(my_win,6,11,"Name:");
    mvwaddstr(my_win,9,11,"Password:");
    mvwaddstr(my_win,1,25,"Chatting Room");
    mvwaddstr(my_win,18,9,"Logo");
    mvwaddstr(my_win,18,19," | ");
    mvwaddstr(my_win,18,25,"Register");
    mvwaddstr(my_win,18,36," |");
    mvwaddstr(my_win,18,44,"Exit");

    mvwaddch(my_win,2,0,ACS_LTEE);
    mvwhline(my_win,2,1,ACS_HLINE,60);
    mvwaddch(my_win,2,59,ACS_RTEE);   
    mvwaddstr(my_win,6,10,"");

    refresh();
    wrefresh(my_win);

    x = 6;
    y = 10;

    wmove(my_win,x,y);  

    while((c = getch())!= 27)
    {
        switch(c)
        {
	    case '\n':
	    {         
                if(x == 6 && y == 10)
		{
	            wrefresh(my_win);
	            echo();

	            wmove(win1,1,1); 
	            mvwgetstr(win1,1,1,usr->name);
		    wrefresh(win1);
		    noecho();

	            wmove(win2,1,1);
		    echo();
	            mvwgetstr(win2,1,1,usr->passwd);
		    wrefresh(win2);
		    noecho();
                 
		    touchwin(my_win);
		    wmove(my_win,18,7);
		    wrefresh(my_win);

		    break;
                
		}

		else if(x == 18 && y == 8)
		{
		    if(usr->name[0] != '\0')
		    {
		    	usr->action = 2;
			if(send(sockfd,usr,sizeof(struct message),0) == -1)
			{
			   perror("send error!\n");
			   pthread_exit(NULL);
			}
			touchwin(my_win);
			wclear(my_win);
			wrefresh(my_win);
			delwin(my_win);
			endwin();
			system("clear");

			return 1;
			
		    }
		    else
		    {
		    	touchwin(my_win);
			mvwprintw(my_win,4,15,"Please input name!");
			wrefresh(my_win);
			sleep(3);
			wclear(my_win);
			delwin(my_win);
		//	endwin();
			refresh();
		   goto loop;
		    }
		}
                
                else if(x == 18 && y == 24)
		{	    
                    reg(sockfd);
       
		    wclear(my_win);
		    wrefresh(my_win);
		    delwin(my_win);
		    
		    endwin();
      		    system("clear");
		  
		    return 1;
		}

		else if(x == 18 && y == 43)
		{
                    wclear(my_win);
		    wrefresh(my_win);
		    delwin(my_win);
		    endwin();
		    system("clear");
		    exit(0);
                   // return -1;
		}

	     }
     
             case KEY_DOWN:
	     {
                 touchwin(my_win);
		 x++;
		 break;
	     }

	     case KEY_UP:
	     {
                 touchwin(my_win);
		 x--;
		 break;
	     }

	     case KEY_LEFT:
	     {
                 touchwin(my_win);
		 y--;
		 break;
	     }

	     case KEY_RIGHT:
	     {
	         touchwin(my_win);
		 y++;
		 break;
	     }
   
	 } 
        touchwin(my_win);
        wmove(my_win,x,y); 
        wrefresh(my_win);  
    }
    wclear(my_win);
    wrefresh(my_win);
    delwin(my_win);
    endwin();
    system("clear");
    
    return 0;
}


