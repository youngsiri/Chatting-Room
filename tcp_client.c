#include "../include/message.h"

void * read_msg(void *arg)
{
    int new_fd = *((int *)arg);
    
    int ret;

    struct online *new;

    struct message *msg = (struct message *)malloc(sizeof(struct message));

    while(1)
    {
        ret = recv(new_fd,msg,sizeof(struct message),0);

	if(ret == -1)
	{
	    perror("recv message error!");
	    pthread_exit(NULL);
	}

	if(ret == 0)
	{
	    perror("404 NOT FOUND!\n");
	    pthread_exit(NULL);
	}

	switch(msg->action)
	{
             case 5:
	     {
		// system("clear");
		 
	         chat_s(new_fd,msg);

		 break;

	     }

	     case 11:
	     {   
	         system("clear");
	     	 reg_success(new_fd,msg->id);
		 break;
	     }
	     case 12:
	     {
	         system("clear");
		 log_success(new_fd,msg);
		 
	 	 break;
	     }
	     case 13:
	     {
	        // system("clear");
	         online(new_fd,msg);
		// refresh();
		 break;
	     }

	     case 14:
	     {
	         chat_s(new_fd,msg);

		 break;
	     }

	     case 15:
	     {
              /*
	         touchwin(send_win);
	         mvwprintw(send_win,5,5,"%s",msg->ems);
		 wrefresh(send_win);
		 refresh();
              */
	         news(new_fd,msg);

		 break;
	     }

             case 404:
	     {
	    // 	online_no();
		break;
	     }

	     case -1:
	     {
	         system("clear");
		 reg_fail();
		 system("clear");
		 reg(new_fd);
		 break;

	     }

	     case -2:
	     {
	        system("clear");
		log_fail();
		system("clear");
                face(new_fd);
		break;

	     }
	     case -3:
	     {
	     	system("clear");
		log_wrong();
		system("clear");
		face(new_fd);
		break;
	     }

	}

	

    }
}


int main(int argc, char *argv[]) 
{ 
	int sockfd; 
	char buffer[1024]; 
        char cmd[10];
	struct sockaddr_in server_addr; 
	struct hostent *host; 
	int nbytes; 

	struct message msg = {0};

	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
		exit(1); 
	} 


	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:Internet;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	bzero(&server_addr,sizeof(server_addr)); 
	server_addr.sin_family=AF_INET;          
	server_addr.sin_port=htons(portnumber);  
	server_addr.sin_addr.s_addr=inet_addr(argv[1]); 
	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

        pthread_t id;

	pthread_create(&id,NULL,read_msg,(void *)&sockfd);

       int cd = face(sockfd); 

       while(cd > 0)
       {
	    
	    while(1);
	    /*
	    printf("Please input cmd:\n");

	    scanf("%s",cmd);


            if(strcmp(cmd,"log") == 0)
	    {
	        msg.action = 1;

		printf("Please input name:\n");
		scanf("%s",msg.name);

		printf("Please input passwd:\n");
		scanf("%s",msg.passwd);

		write(sockfd,&msg,sizeof(struct message));
	    }


            if(strcmp(cmd,"chat") == 0)
	    {
	        msg.action = 2;
		
		printf("Please input toname:\n");
		scanf("%s",msg.toname);

		printf("Please input msg:\n");
		scanf("%s",msg.msg);
		
		write(sockfd,&msg,sizeof(struct message));
	    }
            */
	}
 
	close(sockfd);  
	return 0;
} 
