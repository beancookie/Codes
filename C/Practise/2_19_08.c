#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);

void copy(char to[], char from[]);

int my_strlen(char s[]);

int main(int argc, char const *argv[])
{
	// int len;			// current line length
	// int max = 0;		// maxinum length seen so far
	// char line[MAXLINE];	// current input line
	// char longest[MAXLINE];	// longest line saved here
	// while ((len = my_getline(line, MAXLINE)) > 0)
	// 	if (len > max)
	// 	{
	// 		max = len;
	// 		copy(longest, line);
	// 	}
	// if (max > 0)	// there is a line
	// 	printf("%s", longest);
	printf("%d\n", strlen("sdsadsa"));
	return 0;
}

int my_getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;
	while((to[i] == from[i]) != '\0')
		++i;
}

int my_strlen(char s[])
{
	int i;
	while (s[i] != '\0')
		++i;
	return i;
}