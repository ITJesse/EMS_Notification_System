#include <stdio.h>
#include "get.h"

int main()
{
    int i,r;
    char a;
    printf("****************************************\n");
    printf("*        欢迎使用通知系统客户端        *\n");
    printf("****************************************\n\n");
    printf("正在尝试第1次网络连接，请稍候……\n\n");
    for(i=2;init_mysql()&&i<4;i++)
        printf("正在尝试第%d次网络连接，请稍候……\n\n",i);
    if(i>3) goto End;
    get();
    a=*result_row[0];
    system("cls");
    printf("今天的任务是：  \n");
    printf("%s \n", result_row[2]);
    printf("发布日期：  \n");
    printf("%s", result_row[4]);
    printf("\n\a");
    Sleep(30000);
    for(;;)
    {
        get();
        if(*result_row[0]!=a)
        {
            printf("\a");
            r = MessageBox(NULL,TEXT(result_row[3]),TEXT(result_row[2]),MB_OK);
            a =*result_row[0];
            printf("\n%9s\n", result_row[3]);
            printf("\n发布时间%10s\n", result_row[5]);
        }
    Sleep(30000);
    }
End:r = MessageBox(NULL,TEXT("无法连接，请检查网络……"),TEXT("报错"),MB_OK);;
}

