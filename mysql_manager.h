#include <winsock2.h>
#include "./include/mysql.h"
#include "mysql_config.h"
#include <windows.h>

MYSQL my_connection; /*����һ�����ݿ�����*/
MYSQL_RES *res_opt; /*ָ���ѯ�����ָ��*/

int init_mysql()
{
    mysql_init(&my_connection);
    if(!mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 3306, NULL, 0))
    {
        printf("����MySQLʧ�ܣ�  �����������ӡ�\n\n");
        return 1;
    }
    else
    {
        printf("\n����MySQL�ɹ���\n");
        return 0;
    }
}

void query_sql(char* dz_sql)
{
    int res; /*ִ��sql�Z���ķ��ر�־*/
    mysql_query(&my_connection, "set names gbk");
    res = mysql_query(&my_connection, dz_sql);
    if (res)   /*ִ��ʧ��*/
    {
        printf("Error�� mysql_query !\n");


    }
    else     /*���ھʹ���ִ�гɹ���*/
    {
        /*����ѯ�ĽY����res_ptr*/
        res_opt = mysql_store_result(&my_connection);
        /*��������Ϊ�գ��Ͱѽ�����*/
    }
}

