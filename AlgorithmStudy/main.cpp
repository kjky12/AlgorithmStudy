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
https://programmers.co.kr/learn/courses/30/lessons/43105
*
���� ����
��ũ���� 2018-09-14 ���� 5.44.19.png

���� ���� �ﰢ���� ����⿡�� �ٴڱ��� �̾����� ��� ��, ���İ� ������ ���� ���� ū ��츦 ã�ƺ����� �մϴ�. �Ʒ� ĭ���� �̵��� ���� �밢�� �������� �� ĭ ������ �Ǵ� �������θ� �̵� �����մϴ�. ���� ��� 3������ �� �Ʒ�ĭ�� 8 �Ǵ� 1�θ� �̵��� �����մϴ�.

�ﰢ���� ������ ��� �迭 triangle�� �Ű������� �־��� ��, ���İ� ������ �ִ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
�ﰢ���� ���̴� 1 �̻� 500 �����Դϴ�.
�ﰢ���� �̷�� �ִ� ���ڴ� 0 �̻� 9,999 ������ �����Դϴ�.
����� ��
triangle	result
[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	30

*/

int solution(vector<vector<int>> triangle) 
{
	int answer = 0;

	vector<vector<int>> dp(triangle.size());
	for (size_t i = 0; i < triangle.size(); i++)	//! �������� �������� �κ��̴ϱ� ������ �ʿ� ����
	{
		if(i == 0)
			dp[i].resize(1);
		else
			dp[i].resize((triangle[i - 1].size()) * 2);
	}

	dp[0][0] = triangle[0][0];
	
	for (int i = 0; i < triangle.size() - 1; i++) 
	{
		for (int j = 0; j < triangle[i].size(); j++) 
		{
			int nIdx = j * 2;
			dp[i + 1][nIdx] = dp[i][j] + triangle[i + 1][j];
			dp[i + 1][nIdx + 1] = dp[i][j] + triangle[i + 1][j + 1];
		}
	}

	
	answer = *max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());

	return answer;
}

int main()
{
	int n = 5;
	vector<vector<int>> triangle;

	vector<int>	vecTemp;

	const int nTmp1 = 1;
	int naTmp1[nTmp1] = { 7 };
	vecTemp.assign(naTmp1, naTmp1 + nTmp1);
	triangle.push_back(vecTemp);

	const int nTmp2 = 2;
	int naTmp2[nTmp2] = { 3, 8 };
	vecTemp.assign(naTmp2, naTmp2 + nTmp2);
	triangle.push_back(vecTemp);

	const int nTmp3 = 3;
	int naTmp3[nTmp3] = { 8, 1, 0 };
	vecTemp.assign(naTmp3, naTmp3 + nTmp3);
	triangle.push_back(vecTemp);

	const int nTmp4 = 4;
	int naTmp4[nTmp4] = { 2, 7, 4, 4 };
	vecTemp.assign(naTmp4, naTmp4 + nTmp4);
	triangle.push_back(vecTemp);

	const int nTmp5 = 5;
	int naTmp5[nTmp5] = { 4, 5, 2, 6, 5 };
	vecTemp.assign(naTmp5, naTmp5 + nTmp5);
	triangle.push_back(vecTemp);


	solution(triangle);


	return 0;
}
