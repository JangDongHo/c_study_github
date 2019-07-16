#include <stdio.h>

void f(int *p)
{
	static int data = 5;
	int *pp = &data;
	printf("%d", pp);
	p = pp;
}

int main(void)
{
	int *ip = NULL;
	f(ip);

	printf("%d", *ip);
}