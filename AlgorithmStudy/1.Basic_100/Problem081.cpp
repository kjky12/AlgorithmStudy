#include <stdio.h>

int main()
{

	int b;
	scanf("%d", &b);

	int i;
	for (i = 1; i <= b; i++) //1���� 100���� �ݺ�
	{
		if (i % 3 == 0) 
			printf("X ");
		else
			printf("%d ", i); //3�Ǵ� 5�� ����� ��� �� �� ���

	}


	return 0;
}


