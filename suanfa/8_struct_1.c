#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};

int main()
{
    struct Student st = {00, "chen", 25};
    //printf("%d %s %d", st); //ERROR
    printf("%d %s %d\n", st.sid, st.name, st.age);//OK

    st.sid = 99;
    //st.name = "jun";// ERROR
    strcpy(st.name, "jun");
    printf("%d %s %d", st.sid, st.name, st.age);//OK

    return 0;
}

