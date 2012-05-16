#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Arr
{
    int len;//���鳤��
    int cnt;//������Ч����
    int * pBase;    //����ָ��
}ARR,* PARR;

void init_arr(PARR pArr,int len);   //�����ʼ��
void traverse_arr(PARR); //��������
void append_arr(PARR pArr, int val);   //����ĩβ����Ԫ��
void insert_arr(PARR, int pos, int val);    //�ڵ�pos��Ԫ��ǰ����val
void delete_arr(PARR, int pos, int * pVal); //ɾ����pos��Ԫ�أ�������ɾ��Ԫ��
void sort_arr(PARR);    //���������򣬴�С����
void inversion_arr(PARR);   //��������
int is_empty(PARR);
int is_full(PARR);


int main()
{
    int val;
    PARR pArr= (PARR)malloc(sizeof(ARR));
    init_arr(pArr, 6);
    printf("��ʼ�����飺\n");
    traverse_arr(pArr);
    append_arr(pArr, 0);
    printf("����ĩβ��� 0��\n");
    traverse_arr(pArr);
    insert_arr(pArr, 1, 0);
    printf("����� 1 ��Ԫ��ǰ����0��\n");
    traverse_arr(pArr);
    delete_arr(pArr, 1, &val);
    printf("���� 1 ��Ԫ��ɾ��,ɾ����Ԫ���ǣ�%d\n", val);
    traverse_arr(pArr);
    sort_arr(pArr);
    printf("��С��������\n");
    traverse_arr(pArr);
    inversion_arr(pArr);
    printf("�������飺\n");
    traverse_arr(pArr);

    return 0;
}

void init_arr(PARR pArr, int len)
{
    int cnt;
    int i;
    pArr->len = len;
    pArr->pBase = (int *)malloc(sizeof(int) * len);
    printf("����Ԫ�ظ�����");
    scanf("%d",&cnt);
    if(cnt < 0 || cnt > 6)
    {
        printf("������ЧԪ�ز��ڷ�Χ�ڣ�\n");
        exit(-1);
    }
    pArr->cnt = cnt;

    for(i = 0; i < cnt; ++i)
    {
        printf("������� %d ��Ԫ��:", i + 1);
        scanf("%d", &pArr->pBase[i]);
    }

    return;
}

void traverse_arr(PARR pArr)
{
    if(is_empty(pArr))
        printf("����Ϊ��!\n");
    int i;

    for(i = 0; i < pArr->cnt; ++i)
        printf("%d ", pArr->pBase[i]);
    printf("\n");
}

void append_arr(PARR pArr, int val)
{
    if( is_full(pArr) )
    {
        printf("��������!\n");
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
        printf("��������!\n");
        return;
    }
    if( pos > pArr->len + 1 || pos < 1)
    {
        printf("����λ�ò��ڷ�Χ�ڣ�\n");
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

