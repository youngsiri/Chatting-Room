#include "../include/message.h"
#include <time.h>

int chat(int sockfd,int pos,struct message * msg)
{
    WINDOW *send_win;
    WINDOW * win1;

    int i;
    int c;
    int x ;
    int y ;
    int temp;
    i = 0;
    char str[1023] = {0};
    char ptr[1024] = {0};

    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    send_win = newwin(25,60,4,20);
    win1 = derwin(send_win,4,40,18,3);
    
    keypad(send_win,TRUE);

    box(send_win,0,0);
   
    mvwaddstr(send_win,1,2,"Name:");
    mvwprintw(send_win,1,10,"%s",(msg->online)[pos]);
    mvwaddstr(send_win,23,40,"Send:");
    mvwaddstr(send_win,16,5,"Chat");
    mvwaddstr(send_win,16,15,"Show");
    mvwaddstr(send_win,0,59,"X");

    mvwaddch(send_win,2,0,ACS_LTEE);
    mvwhline(send_win,2,1,ACS_HLINE,60);
    mvwaddch(send_win,2,59,ACS_RTEE);   

    mvwaddch(send_win,15,0,ACS_LTEE);
    mvwhline(send_win,15,1,ACS_HLINE,60);
    mvwaddch(send_win,15,59,ACS_RTEE);   

    mvwaddch(send_win,17,0,ACS_LTEE);
    mvwhline(send_win,17,1,ACS_HLINE,60);
    mvwaddch(send_win,17,59,ACS_RTEE);   
    mvwaddstr(send_win,16,4,"");

    refresh();
    wrefresh(send_win);
    
    memset(msg->ems,0,100);
   
    x = 16;
    y = 3;
    
    touchwin(send_win);
    wmove(send_win,x,y);


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
		        msg->action = 4;    //??????

			strcpy(msg->toname,(msg->online)[pos]);

			if(send(sockfd,msg,sizeof(struct message),0) == -1)
			{
			    perror("send error!\n");
			    pthread_exit(NULL);
			}
			touchwin(send_win);

                        mvwprintw(send_win,7,40,"                   ");
			mvwprintw(send_win,6,40,"%d:%d %s",local->tm_hour,local->tm_min,"I:");
                        mvwprintw(send_win,7,40,"%s",msg->ems);
			
    			memset(msg->ems,0,100);

			touchwin(win1);
			wclear(win1);
			wrefresh(win1);
			delwin(win1);
                        win1 = derwin(send_win,4,40,18,3);
                     //   box(win1,0,0);

			wrefresh(send_win);
			refresh();

		//	return 0;	
				
			break;	

		    }
		    else
		    {
                        touchwin(send_win);
			mvwprintw(send_win,3,15,"Please input your word!");
			wrefresh(send_win);
			sleep(2);
                        wclear(send_win);
                        delwin(send_win);
			refresh();

                        chat(sockfd,pos,msg); 

			return 0;
		    }

		}

		else if(x == 16 && y == 14)
		{
		  show(send_win,win1,str,msg);
		  touchwin(send_win);
		  wrefresh(send_win);
		  refresh();
		  break;

		}

		else if(x == 0 && y == 58)
		{
		    wclear(send_win);
		    wrefresh(send_win);
		    delwin(send_win);
		    endwin();
                    
		    return 0;
		}

		touchwin(send_win);
		wmove(send_win,23,39);
		wrefresh(send_win);

		break;
	    }

            case KEY_DOWN:
	    {
                 touchwin(send_win);
		 x++;
		 break;
	    }

	    case KEY_UP:
	    {
                 touchwin(send_win);
		 x--;
		 break;
	    }

	    case KEY_LEFT:
	    {
                 touchwin(send_win);
		 y--;
		 break;
	    }

	    case KEY_RIGHT:
	    {
	         touchwin(send_win);
		 y++;
		 break;
	    }

	 }

	 touchwin(send_win);;
	 wmove(send_win,x,y);
	 wrefresh(send_win);
    }

    wclear(send_win);
    wrefresh(send_win);
    delwin(send_win);
    endwin();
    system("clear");
    
    return 0;
}


