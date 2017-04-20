#include <iostream>
#include <string>

using namespace std;

int isContain(char *s1, char *s2);

int main() 
{
    // freopen("data", "r", stdin);
    // char str[10];
    // // 字符串的安全读入
    // cin.getline(str, sizeof(str));
    // // gets(char buf[]); // 可能越界
    // cout << str << endl;
    cout << isContain("asdfg", "fg");
    return 0;
}

// 检测s1中是否包含s2 包含则返回第一次出现位置，否则返回-1
int isContain(char *s1, char *s2)
{
    if (s2 == 0)
        return 0;
    for (int i = 0; s1[i]; ++i) {
        int k = i, j = 0;
        for ( ; s2[j]; ++j, ++k) 
            if (s1[k] != s2[j])
                break;
        // 
            if (s2[j] == 0)
                return i;
    }
    return -1;
}