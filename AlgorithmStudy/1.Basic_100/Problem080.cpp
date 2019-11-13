#include <stdio.h>

int main()
{

	int a;
	scanf("%d", &a);

	int nIdx = 1;
	int nSum = 0;
	while (a > nSum)
	{
		nSum += nIdx++;
	}

	printf("%d", nIdx - 1);

	return 0;
}


