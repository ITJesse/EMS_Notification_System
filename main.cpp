#include "stdio.h"
#include "get.h"
#include "string.h"

int main()
{
    int i,r;
    char a[100];
    system("color 0F");
    printf("****************************************\n");
    printf("*        欢迎使用通知系统客户端        *\n");
    printf("****************************************\n\n");
    printf("正在尝试第1次网络连接，请稍候……\n\n");
    for(i=2;init_mysql()&&i<4;i++)
        printf("正在尝试第%d次网络连接，请稍候……\n\n",i);
    if(i>4) goto End;
    get();
    for(i=0;*result_row[0]!='\0';i++,result_row[0]++)
        a[i]=*result_row[0];
    system("cls");
    printf("今天的任务是：  \n\n");
    printf("%s \n", result_row[3]);
    printf("\n发布日期：  \n");
    printf("%s", result_row[5]);
    printf("\n\n正在刷新请稍候……\a");
    Sleep(10000);
    for(;;)
    {
        get();
        system("cls");
        int FLAG=0;
        for(i=0;*result_row[0]!='\0';result_row[0]++,i++)
        if(*result_row[0]!=a[i]) FLAG=1;
        for(;i!=0;result_row[0]--,i--);
        if(FLAG)
        {
            printf("\a");
            r = MessageBox(NULL,result_row[3],result_row[2],MB_OK|MB_ICONEXCLAMATION|MB_SYSTEMMODAL);
            for(i=0;*result_row[0]!='\0';i++,result_row[0]++)
                 a[i]=*result_row[0];
        }
        printf("现在的任务是：\n");
        printf("\n%s\n", result_row[3]);
        printf("\n发布时间%s\n", result_row[5]);
        printf("\n正在刷新请稍候……\n");
        Sleep(10000);
    }
End:r = MessageBox(NULL,TEXT("无法连接，请检查网络……"),TEXT("报错"),MB_OK|MB_ICONHAND|MB_SYSTEMMODAL);
}

