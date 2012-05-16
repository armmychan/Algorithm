/*
   冒泡排序，从小到大的排序
 */
#include <iostream>

using namespace std;
int main()
{
    const int n = 5;
    int a[n] = {2, 3, 1, 5, 4};

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n - 1 - i; j++)
            if(a[j] > a[j + 1]){
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
