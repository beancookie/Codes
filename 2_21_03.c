#include <stdio.h>
typedef struct student
{
	int age;
	char *name;
	double hight;
} Stu;


int main(int argc, char const *argv[])
{
	Stu s;
	Stu *ps = &s;
	s = (Stu){19, "李想", 160.5};
	printf("%d\n", s.age);
	printf("%s\n", s.name);
	printf("%.2f\n", s.hight);
	printf("%.2f\n", ps->hight);
	return 0;
}