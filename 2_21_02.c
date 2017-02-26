#include <stdio.h>

// 文本读取和写入
int main(int argc, char const *argv[])
{
	FILE *f = fopen("text.txt", "r");
	// if (f) {
	// 	fprintf(f, "%s\n", "你好");
	// 	fclose(f);
	// } else {
	// 	printf("操作失败");
	// }
	if (f) {
		char a[10];
		fscanf(f, "%s", a);
		printf("%s\n", a);
		fclose(f);
	} else {
		printf("操作失败");
	}
	return 0;
}