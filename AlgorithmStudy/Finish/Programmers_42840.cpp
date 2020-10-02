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
* https://programmers.co.kr/learn/courses/30/lessons/42840
* 
���� ����
�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.
����� ��
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
����� �� ����
����� �� #1

������ 1�� ��� ������ �������ϴ�.
������ 2�� ��� ������ Ʋ�Ƚ��ϴ�.
������ 3�� ��� ������ Ʋ�Ƚ��ϴ�.
���� ���� ������ ���� ���� ����� ������ 1�Դϴ�.

����� �� #2

��� ����� 2�������� ������ϴ�.


*/

////////////////////////////////
//! �������� ����Ҷ� �ݴ�� �ؼ� ������ �޾���.
////////////////////////////////



int main()
{
	vector<int> answers;

	const int nTmp1 = 5;
	int naTmp1[nTmp1] = { 1,2,3,4,5 };
	answers.assign(naTmp1, naTmp1 + nTmp1);


	//const int nTmp1 = 5;
	//string strTmp1[nTmp1] = { "1","3","2","4","2" };
	//answers.assign(strTmp1, strTmp1 + nTmp1);


	const int nPersonCnt = 3;
	const int nPattern[nPersonCnt] = { 5, 8, 10 };
	int naGiveUp[nPersonCnt][10] = { 
		{1,2,3,4,5},
		{2, 1, 2, 3, 2, 4, 2, 5},
		{3, 3, 1, 1, 2, 2, 4, 4, 5, 5},
	};
	vector<vector<int>>	vecGiveUpGroup(nPersonCnt);
	for (size_t i = 0; i < nPersonCnt; i++)
	{
		vector<int>	vecTmp(naGiveUp[i], naGiveUp[i] + nPattern[i]);

		vecGiveUpGroup[i] = vecTmp;
	}
	
	vector<int> answerCnt(nPersonCnt);
	for (size_t i = 0; i < nPersonCnt; i++)
	{
		for (size_t j = 0; j < answers.size(); j++)
		{
			int nIdx = j % nPattern[i];
			if (answers[j] == vecGiveUpGroup[i][nIdx])
			{
				answerCnt[i]++;
			}
		}
	}
	int nMax = *max_element(answerCnt.begin(), answerCnt.end());

	vector<int> answer;
	for (size_t i = 0; i < answerCnt.size(); i++)
	{
		if (answerCnt[i] == nMax)
			answer.push_back(i + 1);
	}


	return 0;
}

