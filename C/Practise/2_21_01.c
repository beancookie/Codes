#include <stdio.h>
/*
 * printf and scanf
 */
int main(int argc, char const *argv[])
{
	int a, b, c;
	char cc[10];
	printf("%-10.3d*\n", 213);
	// %* 跳过
	// scanf("%*d%d", &a);
	// scanf("%i", &a);
	// scanf("%i", &b);
	// [^*] 读到*为止 不包括*
	// scanf("%[^;]", cc);
	printf("我是输出文本");
	return 0;
}