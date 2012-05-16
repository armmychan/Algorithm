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
void sort_list(PNODE pHead);
int insert_list(PNODE,int,int);
int delete_list(PNODE,int,int*);
int is_empty(PNODE);
int length(PNODE);

int main()
{
    int len;
    int val;
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);
    if( is_empty(pHead) )
        printf("�б�Ϊ�գ�\n");
    else
        printf("�б�ǿգ�\n");
    printf("�б���Ϊ��%d\n", length(pHead));
    sort_list(pHead);
    printf("����֮��\n");
    traverse_list(pHead);
    insert_list(pHead, 2, 0);
    traverse_list(pHead);
    delete_list(pHead, 4, &val);
    printf("ɾ����Ԫ��Ϊ��%d\n", val);
    traverse_list(pHead);
    

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

    printf("������Ҫ�����ڵ��� len = ");
    scanf("%d", &len);
    pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("�ڴ����ʧ�ܣ��˳�����!\n");
        exit(-1);
    }
    pHead->pNext = NULL;
    pTail = pHead;

    for(i = 0; i < len; ++i)
    {
        printf("����� %d ���ڵ�����ݣ�", i);
        scanf("%d", &val);
        pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pHead)
        {
            printf("�ڴ����ʧ�ܣ��˳�����!\n");
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

void sort_list(PNODE pHead)
{
    PNODE q = NULL;
    PNODE p = pHead->pNext;
    int t;

    while(NULL != p)
    {
        q = p->pNext;
        while(NULL != q)
        {
            if(p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
            q = q->pNext;
        }
        p = p->pNext;
    }

    return;
}

int insert_list(PNODE pHead,int pos,int val)
{
    int i;
    PNODE p = pHead;
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if( NULL == pNew)
    {
        printf("�ڴ����ʧ��!\n");
    }
    pNew->data = val;

    for(i = 0; i < pos - 1; ++i)
    {
        p = p->pNext;
    }
    pNew->pNext = p->pNext;
    p->pNext = pNew;

    return 1;
}
int delete_list(PNODE pHead,int pos,int * pVal)
{
    int i;
    PNODE p = pHead;
    PNODE q;

    for(i = 0; i < pos - 1; ++i)
    {
        p = p->pNext;
    }
    q = p->pNext;
    p->pNext = p->pNext->pNext;
    *pVal = q->data;
    free(q);
    
    return 1;

}

