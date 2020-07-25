#include <stdio.h>

int main()
{

	int a, b, c = 0;
	scanf("%d %d %d", &a, &b, &c);

	int nCnt = a;
	for (int i = a; i < c; i++)
	{
		nCnt += b;
	}

	printf("%d ", nCnt);


	return 0;
}


