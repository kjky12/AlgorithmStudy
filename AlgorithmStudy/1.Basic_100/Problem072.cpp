#include <stdio.h>

int main()
{

	int n, m;

	scanf("%d", &n);

reget: //���̺��� �ݷ�( : ) ���� ������.
	scanf("%d", &m);



	if (n-- != 0)
	{
		printf("%d\n", m);
		goto reget; //reget:���� �̵�, n�� �� 1��ŭ ����
	}


	return 0;
}


