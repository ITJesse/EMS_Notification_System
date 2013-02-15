#include "mysql_manager.h"

MYSQL_ROW result_row; /*按行返回的查询信息*/

int get()
{
    MYSQL_FIELD *field; /*字段结构指针*/
    printf("正在检索中，请稍候……");
    system("cls");
        char* sql;
        sql="SELECT * FROM dz_announce ORDER BY id DESC";
        query_sql(sql);
        if (res_opt)
        {
            /*按行输出結果*/
            result_row = mysql_fetch_row(res_opt);
        }
        return 0;
}

