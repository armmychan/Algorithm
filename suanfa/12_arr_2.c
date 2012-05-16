#include <stdio.h>

struct Arr
{
    int * pBase;
    int cnt;
    int len;
};
void init_arr(struct Arr *, int);
void show_arr(struct Arr *);
int append_arr(struct Arr * pArr, int val);
int insert_arr(struct Arr * pArr, int pos, int val);
int delete_arr(struct Arr * pArr, int pos, int * pVal);
void inversion_arr(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
int is_empty(struct Arr *);
int is_full(struct Arr * pArr);

int main()
{
    int val;
    struct Arr arr;
    init_arr(&arr, 6);
    show_arr(&arr);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    printf("添加元素后：\n");
    show_arr(&arr);
    //append_arr(&arr, 6);
    if( insert_arr(&arr, 1, 2))
        printf("插入成功！\n");
    else
        printf("插入失败！\n");
    printf("插入元素后！\n");
    show_arr(&arr);
    if( delete_arr(&arr, 2, &val) )
    {
        printf("删除成功！\n");
        printf("删除元素为：%d\n", val);
    }
    else
    {
        printf("删除失败！\n");
    }
    show_arr(&arr);
    if(append_arr(&arr, 7)){
        printf("添加成功!\n");
    }
    else
    {
        printf("添加失败!\n");
    }
    show_arr(&arr);
    inversion_arr(&arr);
    printf("倒置之后：\n");
    show_arr(&arr);
    sort_arr(&arr);
    printf("排序之后：\n");
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
    printf("\n");
}
int is_empty(struct Arr * pArr)
{
    return pArr->cnt == 0;
}

int append_arr(struct Arr * pArr, int val)
{
    if(is_full(pArr))
        return 0;

    pArr->pBase[pArr->cnt++] = val;
    //pArr->cnt++;

    return 1;
}
int is_full(struct Arr * pArr)
{
    return pArr->cnt == pArr->len;
}

int insert_arr(struct Arr * pArr, int pos, int val)
{
    if( is_full(pArr) )
        return 0;
    if( pos < 1 || pos > pArr->len)
        return 0;

    int i;
    for(i = pArr->cnt; i > pos - 1; --i)
    {
        pArr->pBase[i] = pArr->pBase[i - 1];
    }
    pArr->pBase[pos - 1] = val;
    ++pArr->cnt;

    return 1;
}

int delete_arr(struct Arr * pArr, int pos, int * pVal)
{
    if( is_empty(pArr) )
        return 0;
    if(pos > pArr->len || pos < 1)
        return 0;

    int i;
    *pVal = pArr->pBase[pos - 1];
    for(i = pos; i < pArr->cnt; ++i)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    --pArr->cnt;

    return 1;
}
void inversion_arr(struct Arr * pArr)
{
    int i = 0;
    int j = pArr->cnt - 1;
    int t;
    
    while(i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    return;
}

void sort_arr(struct Arr * pArr)
{
    int i;
    int j;
    int t;

    for(i = 0; i < pArr->cnt-1; ++i)
        for(j = i + 1; j < pArr->cnt; ++j)
            if(pArr->pBase[i] > pArr->pBase[j])
            {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }

    return;
}

