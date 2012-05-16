#include <stdio.h>

typedef struct Student
{
    int sid;
    char name[100];
    int age;
}* PST;

int main()
{
    struct Student stu;
    stu.sid = 99;
    printf("stu.sid = %d\n", stu.sid);

    PST pstu = &stu;
   printf("stu->sid = %d\n", pstu->sid); 

   return 0;
}

