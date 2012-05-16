#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};

void f(struct Student * pst);
void g(struct Student st);
void g2(struct Student * pst);
int main()
{
    struct Student st;  //已经分配了内存
    f(&st);    
    g(st);
    g2(&st);
    return 0;
}
void g2(struct Student * pst)
{
    printf("%d %s %d\n", pst->sid, pst->name, pst->age);
}
void g(struct Student st)
{
    printf("%d %s %d\n", st.sid, st.name, st.age);
}

void f(struct Student * pst)
{
    (*pst).sid = 00;
    strcpy(pst->name, "chen");
    pst->age = 25;
}

