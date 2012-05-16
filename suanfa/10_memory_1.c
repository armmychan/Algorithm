#include <stdio.h>

int f();

int main()
{
    int i = 10;
    i = f();
    printf("%d", i);
    return 0;
}

int f()
{
    int j = 20;
    return j;
}

