#include <stdio.h>

int main()
{

	int h, b, c, s = 0;
	scanf("%d %d %d %d", &h, &b, &c, &s);
	printf("%.1f MB", (float)h * (float)b * (float)c * (float)s / 1024.0 / 1024.0 / 8.0);
	

	return 0;
}


