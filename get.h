#include "mysql_manager.h"

MYSQL_ROW result_row; /*���з��صĲ�ѯ��Ϣ*/

int get()
{
    MYSQL_FIELD *field; /*�ֶνṹָ��*/
    printf("���ڼ����У����Ժ򡭡�");
    system("cls");
        char* sql;
        sql="SELECT * FROM dz_announce ORDER BY id DESC";
        query_sql(sql);
        if (res_opt)
        {
            /*��������Y��*/
            result_row = mysql_fetch_row(res_opt);
        }
        return 0;
}

