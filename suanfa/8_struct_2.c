#include <stdio.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};  //分号不能省略
int main()
{
    struct Student st = {00, "chen", 25};
    struct Student * pst = &st;

    st.sid = 01;//第一种访问成员的方式
    printf("%d %s %d\n", st.sid, st.name, st.age);
    pst->sid = 02;
    printf("%d %s %d", pst->sid, pst->name, pst->age);
    return 0;
}

