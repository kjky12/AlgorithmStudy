#include <stdio.h>

int main()
{

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int nT = a > b ? b : a;
	printf("%d", nT < c ? nT : c); //! 가장 작은 값!
	//printf("%d", (a > b ? a : b) > c ? (a>b ? a : b) : c); //가장 큰값!

	return 0;
}


