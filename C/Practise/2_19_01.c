#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0;		// 下限pa
	upper = 300;	// 上限
	step = 20;		// 步长
	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d \t %d\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}