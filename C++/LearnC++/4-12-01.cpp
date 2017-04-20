#include <iostream>
#include <cstring>
using namespace std;

void reverse(int *p, int size);

int main() {
    int a[][5] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
    };
    reverse(a[1], sizeof(a[1])/sizeof(a[1][0]));
    cout << a[1][0] << endl;
    int **pp;
    int *p;
    int n = 1234;
    p = &n;
    pp = &p;
    cout << **pp << endl;

    char s1[] = "My name is jok,mary hi\n";
    char *tok = strtok(s1, " ,");
    while (tok != NULL) {
        cout << tok << endl;
        tok = strtok(NULL, " ,");
    }

    struct Student {
        unsigned age;
        char name[10];
    };
    Student stu = {12, "张三"};
    Student *pStu = &stu;
    cout << stu.age << endl;
    cout << pStu->age << endl;

}


void reverse(int *p, int size) {
    for (int i=0; i<size/2; ++i) {
        int tmp = p[i];
        p[i] = p[size-1-i];
        p[size-1-i] = tmp;
    }
}