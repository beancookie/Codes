#include <iostream>
using namespace std;

void selectionSort(int *a, int size);
void insertionSort(int *a, int size);
void bubbleSort(int *a, int size);
int binarySearch(const int *a, int size, int p);
int lowerBound(const int *a, int size, int p);

int main() {
    int a[] = {4, 1, 2, 3, 6, 7, 8, 9, 10, 12, 11, 15, 23, 27};
    // selectionSort(a, sizeof(a) / sizeof(a[0]));
    // insertionSort(a, sizeof(a) / sizeof(a[0]));
    bubbleSort(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << binarySearch(a, sizeof(a) / sizeof(a[0]), 5) << endl;
    cout << binarySearch(a, sizeof(a) / sizeof(a[0]), 9) << endl;
    cout << lowerBound(a, sizeof(a) / sizeof(a[0]), 9) << endl;
}

// 选择排序
void selectionSort(int *a, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int tmpMin = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[tmpMin]) {
                tmpMin = a[j];
            }
        }
        int tmp  = a[i];
        a[i] = a[tmpMin];
        a[tmpMin] = tmp;
    }
}

// 插入排序
void insertionSort(int *a, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i]) {
                int tmp = a[i];
                for (int k = i; k > j; --k) 
                    a[k] = a[k - 1];
                a[j] = tmp;
                break;
            }
        }
    }
}

void bubbleSort(int *a, int size) {
    for (int i = size - 1; i >0; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
            }
        }
    }
}

// 二分查找
int binarySearch(const int *a, int size, int p) {
    int L = 0;  // 左端点
    int R = size - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (p == a[mid])
            return mid;
        else if (p > a[mid])
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}

// 查找比p小的最大元素下标
int lowerBound(const int *a, int size, int p) {
    int L = 0;
    int R = size - 1;
    int lastPos = -1;   // 当前最优解
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (a[mid] >= p) {
            R = mid - 1;
        } else {
            lastPos = mid;
            L = mid + 1;
        }
    }
    return lastPos;
}