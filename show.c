#include "../include/message.h"
int show(WINDOW * win,WINDOW * win1,char *str,struct message * msg)
{
    WINDOW * exp_win;
   // WINDOW * win1;

    int i;
    int c;
    int x ;
    int y ;

    i = 0;

    initscr();
  //  start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    
    exp_win = derwin(win,5,28,16,3);

    keypad(exp_win,TRUE);

    box(exp_win,0,0);

    mvwprintw(exp_win,1,2,"(^_^)");
    mvwprintw(exp_win,1,10,"(@_@)");
    mvwprintw(exp_win,1,18,"(>_<)");
    mvwprintw(exp_win,3,2,"(-_-#)");
    mvwprintw(exp_win,3,10,"(0_0)");
    mvwprintw(exp_win,3,18,"(?_?)");

    wrefresh(exp_win);
    refresh();

    x = 1;
    y = 2;
    
    touchwin(exp_win);
    wmove(exp_win,x,y);  
    wrefresh(exp_win);

    while((c = getch())!= 27)
    {
        switch(c)
        {
	    case '\n':
	    {         
                if(x == 1 && y == 1)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);


		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(^_^)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(^_^)");
		   	strcpy(msg->ems,"(^_^)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;

		}

                if(x == 1 && y == 9)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);

		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(@_@)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(@_@)");
		   	strcpy(msg->ems,"(@_@)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;
		}
                if(x == 1 && y == 17)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);

		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(>_<)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(>_<)");
		   	strcpy(msg->ems,"(>_<)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;
		}
                if(x == 3 && y == 1)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);

		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(-_-#)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(-_-#)");
		   	strcpy(msg->ems,"(-_-#)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;
		}
                if(x == 3 && y == 9)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);

		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(0_0)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(0_0)");
		   	strcpy(msg->ems,"(0_0)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;
		}
                if(x == 3 && y == 17)
		{
    		   wclear(exp_win);
    		   wrefresh(exp_win);
    		   delwin(exp_win);

	           touchwin(win1);

		   if((msg->ems[i]) != '\0')
		   {
		        while((msg->ems[i]) != '\0')
			{
		   	   i++;
			}
		         echo();
		  	 wmove(win1,1,i+1);
		   	 strcpy(str,"(?_?)");
		   	 strcat(msg->ems,str);
    		   	 mvwprintw(win1,1,1,msg->ems);
			 noecho();
		   }
		   else
		   {
		   	wmove(win1,1,1);
    		   	mvwprintw(win1,1,1,"(?_?)");
		   	strcpy(msg->ems,"(?_?)");
		   }	

    		   mvwhline(win,17,3,ACS_HLINE,28);
		   mvwaddstr(win,16,5,"Chat");
		   mvwaddstr(win,16,15,"Show");

		   wrefresh(win1);
		   wrefresh(win);
		
		   return 0;
		}
		break;
	    }

            case KEY_DOWN:
	    {
                 touchwin(exp_win);
		 x++;
		break;
	    }

	    case KEY_UP:
	    {
                 touchwin(exp_win);
		 x--;
		 break;
	    }

	    case KEY_LEFT:
	    {
                 touchwin(exp_win);
		 y--;
		 break;
	    }

	    case KEY_RIGHT:
	    {
	         touchwin(exp_win);
		 y++;
		 break;
	    }

	 }

	 touchwin(exp_win);;
	 wmove(exp_win,x,y);
	 wrefresh(exp_win);
    }

    wclear(exp_win);
    wrefresh(exp_win);
    delwin(exp_win);
    endwin();
    
    return 0;
}


