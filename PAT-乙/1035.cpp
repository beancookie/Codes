#include <iostream>
using namespace std;

int N;
bool isMerage = false;
bool isInsert = false;

void insert(int *a, int n, int *b)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j] > a[i])
				swap(a[i], a[j]);	
		}	
		if (isInsert)
		{
            cout << "Insertion Sort\n";
            cout << a[0];
			for (int i = 1; i < n; ++i)
				cout << " " << a[i];
			break;
		}
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] != b[i])
				flag = false;
		}
		if (flag)
			isInsert = true;
	}
}

void merage(int *a, int left, int right)
{
	int mid = left + (right - left) / 2;
	int pl = left;
	int pr = mid + 1;
	int p = 0;
	int tmp[N];
	while (pl <= mid && pr <= right)
	{
		if (a[pl] < a[pr])
			tmp[p++] = a[pl++];
		else
			tmp[p++] = a[pr++];
	}
	while (pl <= mid)
		tmp[p++] = a[pl++];
	while (pr <= right)
		tmp[p++] = a[pr++];
		
	for (int i = 0; i < right - left + 1; ++i)
		a[left + i] = tmp[i];
    
}

void merageSort(int *a, int left, int right, int *b)
{
	if (isMerage) return;
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merageSort(a, left, mid, b);
		merageSort(a, mid + 1, right, b);
		merage(a, left, right);
		cout << "Merge Sort\n";
		cout << a[0];
		for (int i = 1; i < N; ++i)
			cout << " " << a[i];
	}
}

int main()
{
	freopen("1035.in", "r", stdin);
	cin >> N;
	int a[N], b[N], c[N], tmp[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		c[i] = a[i];
	}
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	
	insert(a, N, b);
    if (!isInsert)
		merageSort(c, 0, N-1, tmp);		 
	return 0;
}