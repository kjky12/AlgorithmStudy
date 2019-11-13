#include <stdio.h>

int main()
{

	int a;
	scanf("%d", &a);

	if (a <= 100 && a >= 90)
		printf("A");
	else if (a <= 89 && a >= 70)
		printf("B");
	else if (a <= 69 && a >= 40)
		printf("C");
	else// if (a <= 39 && a >= 0)
		printf("D");


	return 0;
}


