#include <stdio.h>

typedef int * CHEN,JUN;

typedef struct Student
{
    int sid;
    char name[100];
    int age;
}* PSTU, STU;

int main()
{
    int i = 10;
    printf("int i = %d\n", i);
    CHEN pi = &i;
    printf("CHEN pi = %d\n", *pi);
    JUN j = 20;
    printf("JUN j = %d\n", j);
    STU st;
    st.sid = 99;
    printf("st.sid = %d\n", st.sid);
    PSTU pst = &st;
    printf("pst->sid = %d\n", pst->sid);

    return 0;
}

