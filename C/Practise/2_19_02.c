#include <stdio.h>

int main(int argc, char const *argv[])
{
	float fahr, celsius;
	float lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("%s\n", "华氏度摄氏度对照表");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}