#include <stdio.h>

void test(const int *n);

int main(int argc, char const *argv[])
{	
	// 字符数组
	char *a[] = {"13213", "asdasd", "adasfafgsdgsdg"};
	printf("%s\n", *a);
	printf("%s\n", a[1]);
	// 结构体
	struct date
	{
		int month;
		int day;
		int year;
	};
	struct 
	{
		int x;
		int y;
	} x, y;

	struct point
	{
		int x;
		int y;
	} _x, _y;
	struct date today;
	struct point p = {.x = 1, .y = 2};
	today.year = 2017;
	printf("%d\n", today.year);
	printf("day = %d\n", today.day);
	printf("%d\n", p.x);
	printf("%d\n", p.y);
	printf("%d\n", _x.x);
	printf("%d\n", _y.y);
	printf("---------------\n");
	int n[] = {1,2,3,4,5,};
	test(n);
	printf("%d\n", n[0]);
	return 0;
}

void test(const int *n) {
}