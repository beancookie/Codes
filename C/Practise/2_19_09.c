#include <stdio.h>
#include <ctype.h>

enum boolean { false, true};

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

const char msg[] = "waring";
char str[] = "string";

int atoi(char s[]);

void my_strcat(char s[], char t[]);

void my_squeeze(char s[], char t[]);

int main(int argc, char const *argv[])
{
	printf("%d\n", atoi("1234asd131faf341"));
	printf("%c\n", tolower('W'));
	char s[] = "abc";
	char t[] = "def";
	my_strcat(s, t);
	printf("%s\n", s);
	printf("%d\n", 123 & 0117);
	printf("%d\n", 1<<2);
	int c = getchar();
	switch (c) {
		case 'a' : printf("this is a\n");
			break;
		default : printf("other\n");
	}
	return 0;
}

/* atoid: convert s to integer */
int atoi(char s[])
{
	int n = 0;
	for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

void my_strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

/* my_queeze: delete char what is in the t from s */
void my_squeeze(char s[], char t[])
{
	int i, j;
	i = 0;
	while (s[i] != '\0')
		for (int j = 0; t[j] != '\0'; ++j)
		{
			if (s[i] == t[j])
			{
				/* code */
			}
		}
}