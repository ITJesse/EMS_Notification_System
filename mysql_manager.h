#include "winsock2.h"
#include "./include/mysql.h"
#include "mysql_config.h"
#include "windows.h"

MYSQL my_connection; /*这是一个数据库连接*/
MYSQL_RES *res_opt; /*指向查询结果的指针*/

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
    mysql_query(&my_connection, "set names gbk");
    for(;mysql_query(&my_connection, dz_sql);)
    {
        mysql_close(&my_connection);
        printf("\nError: 获取数据失败!\n\n正在重新获取，请稍候……\n");
        for(;mysql_query(&my_connection, dz_sql);)
            Sleep(3000);
    }
    res_opt = mysql_store_result(&my_connection);
}

