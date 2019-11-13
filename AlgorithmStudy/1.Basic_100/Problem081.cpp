#include <stdio.h>

int main()
{

	int b;
	scanf("%d", &b);

	int i;
	for (i = 1; i <= b; i++) //1부터 100까지 반복
	{
		if (i % 3 == 0) 
			printf("X ");
		else
			printf("%d ", i); //3또는 5의 배수인 경우 그 수 출력

	}


	return 0;
}


