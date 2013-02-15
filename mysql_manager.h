#include <winsock2.h>
#include "./include/mysql.h"
#include "mysql_config.h"
#include <windows.h>

MYSQL my_connection; /*这是一个数据库连接*/
MYSQL_RES *res_opt; /*指向查询结果的指针*/

/*测试修改*/

int init_mysql()
{
    mysql_init(&my_connection);
    if(!mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 3306, NULL, 0))
    {
        printf("连接MySQL失败！  请检查网络连接。\n\n");
        return 1;
    }
    else
    {
        printf("\n连接MySQL成功！\n");
        return 0;
    }
}

void query_sql(char* dz_sql)
{
    int res; /*执行sql語句后的返回标志*/
    mysql_query(&my_connection, "set names gbk");
    res = mysql_query(&my_connection, dz_sql);
    if (res)   /*执行失败*/
    {
        printf("Error： mysql_query !\n");


    }
    else     /*现在就代表执行成功了*/
    {
        /*将查询的結果给res_ptr*/
        res_opt = mysql_store_result(&my_connection);
        /*如果结果不为空，就把结果输出*/
    }
}

