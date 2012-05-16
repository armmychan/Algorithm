#include <stdio.h>

struct Arr
{
    int * pBase;
    int cnt;
    int len;
};
void init_arr(struct Arr *, int);
void show_arr(struct Arr *);
int is_empty(struct Arr *);

int main()
{
    struct Arr arr;
    init_arr(&arr, 6);
    show_arr(&arr);
    return 0;
}

void init_arr(struct Arr * pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if(pArr->pBase == NULL)
        printf("动态分配存储错误！\n");
    else
    {
        pArr->cnt = 0;
        pArr->len = length;
    }
}
void show_arr(struct Arr * pArr)
{
    int i;

    if(is_empty(pArr))
        printf("数组为空！\n");
    else
    {
        for(i = 0; i < pArr->cnt; i++)
            printf("%d ", pArr->pBase[i]);
    }
}
int is_empty(struct Arr * pArr)
{
    return pArr->cnt == 0;
}

