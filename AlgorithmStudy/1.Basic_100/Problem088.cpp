#include <stdio.h>

int main()
{

	int a;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) //1���� ������ n���� 1�� ������Ű�鼭 �ݺ��Ѵ�.
	{
		if (i % 3 == 0)
			continue; //¦�����? �Ʒ� �κ��� �ǳʶٰ�! ���~
		printf("%d ", i); //�ᱹ ¦���� �ƴ� ������ ��µȴ�.
	}



	return 0;
}


