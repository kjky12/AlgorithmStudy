#include <stdio.h>

int main()
{
	char n, m = 'a';
	scanf("%c", &n);

	do
	{
		printf("%c ", m);
		m++;
	} while (n >= m);


	return 0;
}


