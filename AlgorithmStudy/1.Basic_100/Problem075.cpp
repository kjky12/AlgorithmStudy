#include <stdio.h>

int main()
{
	int n = 0; //처음 조건 검사를 넘어가기 위해 0이 아닌 값 입력
	scanf("%d", &n);

	while (n != 0)
	{
		n--;
		printf("%d\n", n);
	}


	return 0;
}


