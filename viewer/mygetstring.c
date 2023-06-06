#include <stdio.h>
#include <string.h>

char *mygetstring(char *pout,int size)
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
