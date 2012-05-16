#include <stdio.h>
#include <malloc.h>

int main()
{
    int a[5] = {1, 3, 5, 2, 4};

    int len;
    printf("len = ");
    scanf("%d", &len);
    int *pArr = (int *)malloc(sizeof(int) * len);
    *pArr = 4;
    pArr[1] = 10;
    printf("%d %d", *pArr, pArr[1]);

    int i;
    for(i = 0; i < len; i++)
        //scanf("%d ", &pArr[i]);    //"%d "后面的空格不能要
        scanf("%d", &pArr[i]);    //input
    for(i = 0; i < len; i++)
        printf("%d ", pArr[i]);     //output
    free(pArr);
    return 0;
}
