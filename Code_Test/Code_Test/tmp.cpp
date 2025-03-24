#include <stdio.h>
#include <stdlib.h>

void func1(int param)
{
	int a = 10;
	param = param + a;
}

void func2(int* param)
{
	int a = 20;
	*param = *param + a;
}

int main(int argc, char* argv[])
{
	int a = 5;

	func1(a);
	func2(&a);

	printf("%d\n", a);

	return 0;
}