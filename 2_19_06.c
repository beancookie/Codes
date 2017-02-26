#include <stdio.h>

// 统计数字
int main(int argc, char const *argv[])
{
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;
	for (int i = 0; i < 10; ++i)
	{
		ndigit[i] = 0;
	}
	while ((c = getchar()) != EOF) 
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	printf("digits =");
	for (int i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
		 nwhite, nother);
	return 0;
}