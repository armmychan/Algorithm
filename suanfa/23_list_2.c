#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, * PNODE;

PNODE create_list();
void traverse_list(PNODE pHead);
int is_empty(PNODE);
int length(PNODE);

int main()
{
    int len;
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);
    if( is_empty(pHead) )
        printf("列表为空！\n");
    else
        printf("列表非空！\n");
    printf("列表长度为：%d\n", length(pHead));
    

    return 0;
}

PNODE create_list()
{
    int len;
    int val;
    int i;
    PNODE pHead = NULL;
    PNODE pNew = NULL;
    PNODE pTail = NULL;

    printf("输入需要创建节点数 len = ");
    scanf("%d", &len);
    pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("内存分配失败，退出程序!\n");
        exit(-1);
    }
    pHead->pNext = NULL;
    pTail = pHead;

    for(i = 0; i < len; ++i)
    {
        printf("输入第 %d 个节点的数据：", i);
        scanf("%d", &val);
        pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pHead)
        {
            printf("内存分配失败，退出程序!\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pTail->pNext;
    }

    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    while(NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return;
}

int is_empty(PNODE pHead)
{
    return NULL == pHead->pNext;
}

int length(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int cnt=0;

    while(NULL != p)
    {
        ++cnt;
        p = p->pNext;
    }

    return cnt;
}

