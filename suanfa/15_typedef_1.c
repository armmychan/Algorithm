#include <stdio.h>
typedef int CHAN;

typedef struct Student
{
    int sid;
    char name[100];
    int age;
}ST;

int main()
{
    int i = 10;
    printf("int i = %d\n", i);
    CHAN j = 20;
    printf("CHAN i = %d\n", j);

    struct Student st;
    st.sid = 99;
    printf("st.sid = %d\n", st.sid);
    ST st2 = st;
    printf("st2.sid = %d\n", st2.sid);
}

