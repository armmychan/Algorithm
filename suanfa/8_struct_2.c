#include <stdio.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};  //�ֺŲ���ʡ��
int main()
{
    struct Student st = {00, "chen", 25};
    struct Student * pst = &st;

    st.sid = 01;//��һ�ַ��ʳ�Ա�ķ�ʽ
    printf("%d %s %d\n", st.sid, st.name, st.age);
    pst->sid = 02;
    printf("%d %s %d", pst->sid, pst->name, pst->age);
    return 0;
}

