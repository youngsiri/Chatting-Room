#include "../include/message.h"
#include <time.h>

int news(int sockfd,struct message * msg)
{
    WINDOW * lwin;
    WINDOW * lwin1;
    WINDOW * chat_win;
    WINDOW * win1;
   
    int x;
    int y;
    int c;
    int i;
    char str[100] = {0};

    i = 0;


    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    chat_win = newwin(25,60,4,20);
    win1 = derwin(chat_win,4,40,18,3);

    lwin = newwin(32,28,2,90);
    lwin1 = derwin(lwin,5,12,3,3);
    
    box(lwin,0,0);
    box(lwin1,0,0);
    box(chat_win,0,0);
//    box(win1,0,0);

    mvwaddstr(lwin,1,3,"Echo");
    mvwaddstr(lwin,0,27,"X");
    mvwprintw(lwin,4,20,"%s",msg->name);
    mvwaddstr(lwin,9,2,"Group");
    mvwaddstr(lwin,11,2,"->I");
    mvwaddstr(lwin,12,2,"->online friend");
    mvwaddstr(lwin,30,3,"help");
    
    mvwaddch(lwin1,2,2,'(');
    mvwaddch(lwin1,2,4,'^');
    mvwaddch(lwin1,2,6,'_');
    mvwaddch(lwin1,2,8,'^');
    mvwaddch(lwin1,2,10,')');

    mvwaddch(lwin,2,0,ACS_LTEE);
    mvwhline(lwin,2,1,ACS_HLINE,28);
    mvwaddch(lwin,2,27,ACS_RTEE);

    mvwaddch(lwin,8,0,ACS_LTEE);
    mvwhline(lwin,8,1,ACS_HLINE,28);
    mvwaddch(lwin,8,27,ACS_RTEE);
   
    mvwaddstr(chat_win,1,2,"Name:");
    mvwprintw(chat_win,1,10,"%s",msg->toname);
    mvwaddstr(chat_win,23,40,"Send:");
    mvwaddstr(chat_win,16,5,"Chat");
    mvwaddstr(chat_win,16,15,"Show");

    mvwaddstr(chat_win,0,59,"X");

    mvwaddch(chat_win,2,0,ACS_LTEE);
    mvwhline(chat_win,2,1,ACS_HLINE,60);
    mvwaddch(chat_win,2,59,ACS_RTEE);   

    mvwaddch(chat_win,15,0,ACS_LTEE);
    mvwhline(chat_win,15,1,ACS_HLINE,60);
    mvwaddch(chat_win,15,59,ACS_RTEE);   

    mvwaddch(chat_win,17,0,ACS_LTEE);
    mvwhline(chat_win,17,1,ACS_HLINE,60);
    mvwaddch(chat_win,17,59,ACS_RTEE);   
    mvwaddstr(chat_win,16,4,"");

    mvwprintw(chat_win,4,5,"%d:%d %s",local->tm_hour,local->tm_min,msg->toname);
    mvwprintw(chat_win,5,5,"%s",msg->ems);


    wrefresh(lwin);
    wrefresh(chat_win);
    refresh();

    memset(msg->ems,0,100);

    touchwin(chat_win);

    keypad(chat_win,TRUE);

    x = 16;
    y = 3;
    wmove(chat_win,16,3);

    while((c = getch())!= 27)
    {
        switch(c)
        {
	    case '\n':
	    {         
                if(x == 16 && y == 4)
		{
	            touchwin(win1);
		    echo();

		    if((msg->ems[0]) != '\0')
		    {
		    	 while((msg->ems[i]) != '\0')
			 {
			  i++;
			 }
			 wmove(win1,1,i+1);
		    	 mvwgetstr(win1,1,i+1,str);
			 strcat(msg->ems,str);
		    }

		    else
		    {
		        wmove(win1,1,1);
		        mvwgetstr(win1,1,1,msg->ems);
		    }	

		    wrefresh(win1);
		    noecho();

		    break;
		}
		
		else if(x == 23 && y == 39)
		{
		    if((msg->ems[0]) != '\0')
		    {
		        msg->action = 5;

			if(send(sockfd,msg,sizeof(struct message),0) == -1)
			{
			    perror("send error!\n");
			    pthread_exit(NULL);
			}
			touchwin(chat_win);
                        mvwprintw(chat_win,7,40,"                     ");
			mvwprintw(chat_win,6,40,"%d:%d %s",local->tm_hour,local->tm_min,"I:");
                        mvwprintw(chat_win,7,40,"%s",msg->ems);
		
		        memset(msg->ems,0,100);

			touchwin(win1);
			wclear(win1);
			wrefresh(win1);
			delwin(win1);
                        win1 = derwin(chat_win,4,40,18,3);
                     //   box(win1,0,0);

			wrefresh(chat_win);
			refresh();
			
		// 	return 0;

			break;
		    }
		    
		    else
		    {
                        touchwin(chat_win);
			mvwprintw(chat_win,3,15,"Please input your word!");
			wrefresh(chat_win);
			sleep(2);
                        wclear(chat_win);
                        delwin(chat_win);
			refresh();

                        news(sockfd,msg); 

			return 0;
		    }
		  
		}

		else if(x == 16 && y == 14)
		{
		  show(chat_win,win1,str,msg);
		  touchwin(chat_win);
		  wrefresh(chat_win);
		  refresh();
		  break;

		}


		else if(x == 0 && y == 58)
		{
		  
    		    wclear(chat_win);
    		    wrefresh(chat_win);
    		    delwin(chat_win);
    		    endwin();

		    Log(sockfd,msg);

		    return 0;
		}
	    }

            case KEY_DOWN:
	    {
                 touchwin(chat_win);
		 x++;
		 break;
	    }

	    case KEY_UP:
	    {
                 touchwin(chat_win);
		 x--;
		 break;
	    }

	    case KEY_LEFT:
	    {
                 touchwin(chat_win);
		 y--;
		 break;
	    }

	    case KEY_RIGHT:
	    {
	         touchwin(chat_win);
		 y++;
		 break;
	    }

	    case '/':
	    {
	    	
    		wclear(chat_win);
    		wrefresh(chat_win);
    		delwin(chat_win);
    		endwin();

		return 0;

	    }
	 }

	 touchwin(chat_win);;
	 wmove(chat_win,x,y);
	 wrefresh(chat_win);
    }

    wclear(chat_win);
    wrefresh(chat_win);
    delwin(chat_win);
    endwin();
    system("clear");
    
    return 0;
}

