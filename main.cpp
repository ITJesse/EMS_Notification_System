#include <stdio.h>
#include "get.h"

int main()
{
    int i,r;
    char a;
    printf("****************************************\n");
    printf("*        ��ӭʹ��֪ͨϵͳ�ͻ���        *\n");
    printf("****************************************\n\n");
    printf("���ڳ��Ե�1���������ӣ����Ժ򡭡�\n\n");
    for(i=2;init_mysql()&&i<4;i++)
        printf("���ڳ��Ե�%d���������ӣ����Ժ򡭡�\n\n",i);
    if(i>3) goto End;
    get();
    a=*result_row[0];
    system("cls");
    printf("����������ǣ�  \n");
    printf("%s \n", result_row[2]);
    printf("�������ڣ�  \n");
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
            printf("\n����ʱ��%10s\n", result_row[5]);
        }
    Sleep(30000);
    }
End:r = MessageBox(NULL,TEXT("�޷����ӣ��������硭��"),TEXT("����"),MB_OK);;
}

