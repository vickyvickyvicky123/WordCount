#include <stdio.h>
#include <string.h>
#define Len 300
int main(int acount, char* a[])
{
    FILE* file;
    int count = 0; // 统计数

    //设置为只允许读文件
    if ((file = fopen(a[2], "rt")) == NULL)
    {
        printf("文件读取有误或文件内容为空!\n");
        return 0;
    }
// 111
    if (a[1][1] == 'w')
    {
        char s[Len];
        while (fscanf(file, "%s", s) != EOF)
        {
            count++;
            for (int i = 1; i < strlen(s) - 1; i++)
            {
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',')
                {
                    count++;
                }
            }
        }
        printf("单词数=%d\n", count);
    }

    if (a[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(file)) != EOF)
        {
            count++;
        }
        printf("字符数=%d", count);
    }
    fclose(file);
    return 0;
}