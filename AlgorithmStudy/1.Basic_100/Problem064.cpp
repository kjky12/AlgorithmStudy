#include <stdio.h>

int main()
{

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int nT = a > b ? b : a;
	printf("%d", nT < c ? nT : c); //! ���� ���� ��!
	//printf("%d", (a > b ? a : b) > c ? (a>b ? a : b) : c); //���� ū��!

	return 0;
}


