#include <stdio.h>

int main()
{

	int w, h, b = 0;
	scanf("%d %d %d", &w, &h, &b);
	printf("%.2f MB", (float)w * (float)h * (float)b / 1024.0 / 1024.0 / 8.0);


	return 0;
}


