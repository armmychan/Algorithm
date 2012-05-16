#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Arr
{
    int len;//数组长度
    int cnt;//数组有效个数
    int * pBase;    //数组指针
}ARR,* PARR;

void init_arr(PARR pArr,int len);   //数组初始化
void traverse_arr(PARR); //遍历数组
void append_arr(PARR pArr, int val);   //数组末尾加入元素
void insert_arr(PARR, int pos, int val);    //在地pos个元素前插入val
void delete_arr(PARR, int pos, int * pVal); //删除第pos个元素，并保存删除元素
void sort_arr(PARR);    //对数组排序，从小到大
void inversion_arr(PARR);   //倒置数组
int is_empty(PARR);
int is_full(PARR);


int main()
{
    int val;
    PARR pArr= (PARR)malloc(sizeof(ARR));
    init_arr(pArr, 6);
    printf("初始化数组：\n");
    traverse_arr(pArr);
    append_arr(pArr, 0);
    printf("数组末尾添加 0：\n");
    traverse_arr(pArr);
    insert_arr(pArr, 1, 0);
    printf("数组第 1 个元素前插入0：\n");
    traverse_arr(pArr);
    delete_arr(pArr, 1, &val);
    printf("将第 1 个元素删除,删除的元素是：%d\n", val);
    traverse_arr(pArr);
    sort_arr(pArr);
    printf("从小到大排序：\n");
    traverse_arr(pArr);
    inversion_arr(pArr);
    printf("倒置数组：\n");
    traverse_arr(pArr);

    return 0;
}

void init_arr(PARR pArr, int len)
{
    int cnt;
    int i;
    pArr->len = len;
    pArr->pBase = (int *)malloc(sizeof(int) * len);
    printf("输入元素个数：");
    scanf("%d",&cnt);
    if(cnt < 0 || cnt > 6)
    {
        printf("输入有效元素不在范围内！\n");
        exit(-1);
    }
    pArr->cnt = cnt;

    for(i = 0; i < cnt; ++i)
    {
        printf("请输入第 %d 个元素:", i + 1);
        scanf("%d", &pArr->pBase[i]);
    }

    return;
}

void traverse_arr(PARR pArr)
{
    if(is_empty(pArr))
        printf("数组为空!\n");
    int i;

    for(i = 0; i < pArr->cnt; ++i)
        printf("%d ", pArr->pBase[i]);
    printf("\n");
}

void append_arr(PARR pArr, int val)
{
    if( is_full(pArr) )
    {
        printf("数组已满!\n");
        return;
    }
    pArr->pBase[pArr->cnt] = val;
    ++pArr->cnt;
    return;
}

void insert_arr(PARR pArr, int pos, int val)
{
    if( is_full(pArr))
    {
        printf("数组已满!\n");
        return;
    }
    if( pos > pArr->len + 1 || pos < 1)
    {
        printf("插入位置不在范围内！\n");
        return;
    }

    int i;
    for(i = pArr->cnt; i > pos - 1; --i )
        pArr->pBase[i] = pArr->pBase[i - 1];
    pArr->pBase[pos - 1] = val;
    ++pArr->cnt;

    return;

}

void delete_arr(PARR pArr, int pos, int * pVal)
{
    int i;


    *pVal = pArr->pBase[pos - 1];
    for(i = pos - 1; i < pArr->cnt; ++i)
        pArr->pBase[i] = pArr->pBase[i + 1];
    --pArr->cnt;
    
   return; 
}
void sort_arr(PARR pArr)
{
    int i;
    int j;
    int t;

    for(i = 0; i < pArr->cnt; ++i)
        for(j = i + 1; j < pArr->cnt; ++j)
            if(pArr->pBase[i] > pArr->pBase[j] )
            {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
    return;
}

void inversion_arr(PARR pArr)
{
    int i;
    int j;
    int t;

    for(i = 0,j = pArr->cnt - 1; i < j; ++i, --j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
    }
    return;
}

int is_full(PARR pArr)
{
    return  pArr->len == pArr->cnt;
}

int is_empty(PARR pArr)
{
    return pArr->cnt == 0;
}

