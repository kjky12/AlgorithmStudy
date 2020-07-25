#include <stdio.h>

int main()
{

	int n, s = 1;
	int i = 0;
	scanf("%d", &n);

	while (n > i)
	{
		i += s;

		s++;
	}

	printf("%d", i);

	return 0;
}


