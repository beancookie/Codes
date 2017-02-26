#include <stdio.h>

int main() 
{
	int c;
	long nc = 0;
	long lc = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
	 		++lc;
	 	else 
			++nc;
	}
	printf("nc : %ld\n", nc);
	printf("lc : %ld\n", lc);
	return 0;
}