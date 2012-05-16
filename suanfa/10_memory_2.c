#include <stdio.h>
#include <malloc.h>

struct Student
{
    int sid;
    int age;
};

struct Student * CreatStudent();
void ShowStudent(struct Student * pst);
int main()
{
    struct Student *pst;
    pst = CreatStudent();
    ShowStudent(pst);

    return 0;
}
struct Student * CreatStudent()
{
    struct Student * pst = (struct Student *)malloc(sizeof(struct Student));
    pst->sid = 99;
    pst->age = 88;
    
    return pst;
}
void ShowStudent(struct Student * pst)
{
    printf("%d %d", pst->sid, pst->age);
}



