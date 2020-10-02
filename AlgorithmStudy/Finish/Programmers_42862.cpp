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
https://programmers.co.kr/learn/courses/30/lessons/42862
*
���� ����
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. �л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. �̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
����� ��
n	lost	reserve	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
����� �� ����
���� #1
1�� �л��� 2�� �л����� ü������ �����ְ�, 3�� �л��̳� 5�� �л��� 4�� �л����� ü������ �����ָ� �л� 5���� ü�������� ���� �� �ֽ��ϴ�.

���� #2
3�� �л��� 2�� �л��̳� 4�� �л����� ü������ �����ָ� �л� 4���� ü�������� ���� �� �ֽ��ϴ�.





*/

int solution(int n, vector<int> lost, vector<int> reserve) {

	//! ���� ü������ ������ �л��� ü������ ���� ���� ��ó��
	for (size_t i = 0; i < lost.size(); i++)
	{
		size_t j = 0;
		for (j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i--;
				j--;

				break;
			}

		}

	}

	for (size_t i = 0; i < lost.size(); i++)
	{
		bool bFlag = false;
		size_t j = 0;
		for (j = 0; j < reserve.size(); j++)
		{
			////! ���� ü������ ������ �л��� ü������ ����
			//if (lost[i] == reserve[j])
			//{
			//	bFlag = true;
			//	break;
			//}

			if (lost[i] + 1 >= reserve[j] && lost[i] - 1 <= reserve[j])
			{
				bFlag = true;
				break;
			}
		}

		if (bFlag)
		{
			lost.erase(lost.begin() + i);
			reserve.erase(reserve.begin() + j);
			i--;
			j--;
		}

	}

	int answer = n - lost.size();



	return answer;
}

int main()
{
	int n = 5;
	vector<int> lost;
	vector<int> reserve;

	const int nTmp1 = 2;
	int naTmp1[nTmp1] = { 2, 4 };
	lost.assign(naTmp1, naTmp1 + nTmp1);

	const int nTmp2 = 3;
	int naTmp2[nTmp2] = { 1, 3, 5 };
	reserve.assign(naTmp2, naTmp2 + nTmp2);


	solution(n, lost, reserve);


	return 0;
}
