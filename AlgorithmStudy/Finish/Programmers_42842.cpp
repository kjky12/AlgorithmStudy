//! ��� ���
#include <iostream>

//! ���ڿ� ���
#include "string"
//! ���ڿ� �Լ� ���
#include "string.h"

#include "algorithm"

//! ���� ���
#include <vector>

using namespace std;


/*
https://programmers.co.kr/learn/courses/30/lessons/42842
*
���� ����
Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.

carpet.png

Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.
����� ��
brown	yellow	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
��ó

�� ���� - 2020�� 2�� 3�� �׽�Ʈ���̽��� �߰��Ǿ����ϴ�.
�� ���� - 2020�� 5�� 11�� �����ټ��� ����Ͽ� �������� ��������� �����Ͽ����ϴ�.



*/

////////////////////////////////
//! �������� ����Ҷ� �ݴ�� �ؼ� ������ �޾���.
////////////////////////////////



int main()
{
	int brown = 10;
	int yellow = 2;
	
	//int brown = 8;
	//int yellow = 1;
	//int brown = 24;
	//int yellow = 24;

	/*
	�� ������ ������ ���̰� ���κ��� ũ�ų� ���ƾ��Ѵ�.
	BROWON = x*2 + (y-2) *2
	YELLOW = (x - 2)*2 + (y-2) *2
	�� ������ �����Ǿ���ϸ�

	�׷��� x��, ���� ������ �Է��ϰ� ��� y���� �����ϴ� for���� �������Ѵ�.

	*/ 

	vector<int> answer;

	int nMaxWidth = (brown - 2) / 2; //! �ּ� ��ĭ�� �ִٴ� ����

	for (int i = nMaxWidth; i >= 0; i--)
	{
		bool bFlag = false;
		int nHeight = 1;
		while (true)
		{
			int nBrownCnt = (i * 2) + (nHeight * 2);

			int nYelloCnt = (i - 2) * (nHeight);


			//! ������ ������ �÷��׸� �ٲ۴�
			if (nBrownCnt == brown && nYelloCnt == yellow)
			{
				bFlag = true;
				break;
			}

			if (nBrownCnt > brown || nYelloCnt > yellow)
				break;

			nHeight++;
		}

		if (bFlag == true)
		{
			answer.push_back(i);
			answer.push_back(nHeight + 2);
			break;
		}

	}




	return 0;
}

