#include "sims_public.h"

static char *mygetstring(char *pout,int size);
int display_mainui()
{
	int op = -1;

	printf("Please input your select:\n");
	printf("1: Admin Login\n");
	printf("2: Teacher Login\n");
	printf("3: Student Login\n");
	printf("0: Exit\n");
	scanf("%d",&op);

	while(getchar() != '\n')
	{
	}
	return op;
}

int display_adminui()
{
	int op = -1;

	printf("Please input your select:\n");
	printf("1: Modify Admin Password\n");
	printf("2: Add New Teacher\n");
	printf("3: Display All Teachers\n");
	printf("4: Delete A Teacher\n");
	printf("5: Modify A Teacher\n");
	printf("0: Back\n");
	scanf("%d",&op);

	while(getchar() != '\n')
	{
	}
	return op;
}

int input_string(char *p,int len,char *ptip)
{
	printf("%s",ptip);
	mygetstring(p,len);

	return 0;	
}

int display_message(char *pmsg)
{
	printf("%s",pmsg);
	return 0;
}


static char *mygetstring(char *pout,int size)
{
    int len = 0;

	/*将用户从命令行输入的字符串保存到pout指向的空间中，最多读size-1个字符
		1. 用户输入多于size - 1 字符,则pout指向空间只是获取到前size-1字符，剩余字符仍然留在标准输入里
		2. 用户输入小于等于size - 1字符，则pout指向空间获取到所有输入字符，其中包括最后输入的换行符'\n'
    */
    fgets(pout,size,stdin);

    len = strlen(pout);

    if(*(pout + len - 1) == '\n')//最后一个有效字符如果是'\n',则是第二种情况
    {
        *(pout + len - 1) = '\0';
    }
    else //最后一个有效字符如果不是'\n',则是第一种情况
    {
        while(getchar() != '\n')
        {
        }
    }

    return pout;
}
