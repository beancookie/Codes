#include <stdio.h>

double power(int m, int n);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 100; ++i)
	{
		printf("%d %10f %10f\n", i, power(2, i), power(-3, i));
	}
	return 0;
}

double power(int base, int n) 
{
	double p = 1;
	for (int i = 1; i <= n; ++i)
		p *= base;
	return p;
}