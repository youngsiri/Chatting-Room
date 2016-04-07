#include "../include/message.h"

int reg(int sockfd)
{
    WINDOW * my_win;
    WINDOW * win1;
    WINDOW * win2;
    WINDOW * win3;
    WINDOW * win4;
    WINDOW * win5;
 
    struct message *new = (struct message *)malloc(sizeof(struct message));
     
    memset(new,0,sizeof(struct message));

   	
    int x ;
    int y ;
    int c ;
    int ret;

    char num1[1023] = {0};
    char num2[1024] = {0};
    char num3[1024] = {0};
    char num4[1024] = {0};
    char num5[1024] = {0};

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);

    my_win = newwin(25,60,4,25);
    win1 = derwin(my_win,3,20,5,21);
    win2 = derwin(my_win,3,20,8,21);
    win3 = derwin(my_win,3,20,11,21);
    win4 = derwin(my_win,3,20,14,26);
    win5 = derwin(my_win,3,20,17,26);

    box(my_win,0,0);
    box(win1,0,0);
    box(win2,0,0);
    box(win3,0,0);
    box(win4,0,0);
    box(win5,0,0);
                  
    mvwaddstr(my_win,1,25,"Register");		  
    mvwaddstr(my_win,6,5,"Name:");
    mvwaddstr(my_win,9,5,"Password:");
    mvwaddstr(my_win,12,5,"Passwd Sure:");
    mvwaddstr(my_win,15,5,"The Safety question:");
    mvwaddstr(my_win,18,5,"The Safety answer:");
    mvwaddstr(my_win,21,13,"OK");
    mvwaddstr(my_win,21,44,"Exit");

    mvwaddch(my_win,2,0,ACS_LTEE);
    mvwhline(my_win,2,1,ACS_HLINE,60);
    mvwaddch(my_win,2,59,ACS_RTEE);   
    mvwaddstr(my_win,6,4,"");

    refresh();
    wrefresh(my_win);

    x = 6;
    y = 4;
    wmove(my_win,x,y);

    while((c = getch()) != 27)
    {
        switch(c)
	{
	    case '\n':
	    {
                if(x == 6 && y == 4)
		{
		    wrefresh(my_win);
		    echo();
		    
		    wmove(win1,1,1);
		    mvwgetstr(win1,1,1,new->name);
		    wrefresh(win1);
		    noecho();

		    wmove(win2,1,1);
		    echo();
		    mvwgetstr(win2,1,1,new->passwd);
		    wrefresh(win2);
		    noecho();

		    wmove(win3,1,1);
		    echo();
		    mvwgetstr(win3,1,1,new->passwd1);
		    wrefresh(win3);
		    noecho();

		    wmove(win4,1,1);
		    echo();
		    mvwgetstr(win4,1,1,new->question);
		    wrefresh(win4);
		    noecho();

		    wmove(win5,1,1);
		    echo();
		    mvwgetstr(win5,1,1,new->answer);
		    wrefresh(win5);
		    noecho();	  

		    touchwin(my_win);
 		    wmove(my_win,21,10);
		    wrefresh(my_win);
		}

		else if(x == 21 && y ==  12)
		{
		    	
                    if(new->name[0] != '\0')
                    {
                        while(strcmp(new->passwd,new->passwd1) != 0)
                        { 
			    touchwin(my_win);
                            mvwprintw(my_win,4,15,"the passwords are different!");
			    wrefresh(my_win);
			    sleep(3);
			    reg(sockfd);
	                }
		        new->action = 1;	
			if(send(sockfd,new,sizeof(struct message),0) == -1)
			{
			    perror("send error!\n");
			    pthread_exit(NULL);
			    //exit(1);
			}

                        wclear(my_win);
                        wrefresh(my_win);
			delwin(my_win);
			endwin();
	                system("clear");
		        //  write(sockfd,new,sizeof(struct regest));
	                return 0;
	            }
		    else
		    {	
		    	touchwin(my_win);
                        mvwprintw(my_win,4,15,"please input name!");
			wrefresh(my_win);
			sleep(3);
			wclear(my_win);
			delwin(my_win);
		//	endwin();
			refresh();
			reg(sockfd);
			
		//	return 0;
		    }

		}

		else if(x == 21 && y == 43)
		{   
		    wclear(my_win);
		    wrefresh(my_win);
		    delwin(my_win);
		    endwin();
		    system("clear");
		    face(sockfd);
                      
 		    return 0;
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

  //      wclear(my_win);
//	delwin(my_win);
//	endwin();
//	refresh();
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

