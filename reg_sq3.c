#include "../include/message.h"

int reg_sqlite(struct message *msg)
{
    sqlite3 *db ;
    sqlite3_stmt *stmt;
    char **result = NULL;
    char *errmsg = NULL;
    const char *tail;

    char sql[100];
    char temp[3][20];
    
    int i;
    int nrow;  //hang
    int ncolumn;  //lie

  //  *(msg->id) = rand()  ;

    int ret = sqlite3_open("reg_usr.db",&db);

    if(ret != SQLITE_OK)
    {
    	printf("sqlite open erroe!\n");
	exit(1);
    }

    memset(sql,0,sizeof(sql));

    sprintf(sql,"select * from reg_usr where name = '%s';",msg->name);
    ret = sqlite3_prepare(db,sql,strlen(sql),&stmt,&tail);

    if(ret != SQLITE_OK)
    {
    	fprintf(stderr,"SQL error:%s \n",sqlite3_errmsg(db));
    }
    // zhixing
    ret = sqlite3_step(stmt);
    sqlite3_column_count(stmt);
    while(ret == SQLITE_ROW)
    {
    	ret = sqlite3_step(stmt);
	sqlite3_finalize(stmt);

     //   sqlite3_free_table(result);
	sqlite3_close(db);
	return -3;
    }

    msg->id = rand();
 
    //destoey
    sqlite3_finalize(stmt);

    memset(sql,0,sizeof(sql));

    sprintf(sql,"insert into reg_usr(id,name,passwd,question,answer) values(%d,'%s','%s','%s','%s')",(msg->id),msg->name,msg->passwd,msg->question,msg->answer);

    sqlite3_exec(db,sql,NULL,NULL,&errmsg);

  //  sqlite3_free_table(result);

    sqlite3_close(db);

    return 3;
}
