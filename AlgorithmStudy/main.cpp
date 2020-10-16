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
https://programmers.co.kr/learn/courses/30/lessons/43165
*

���� ����
n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.
����� ��
numbers	target	return
[1, 1, 1, 1, 1]	3	5
����� �� ����

*/
int nCnt = 0;
void dfs(const vector<int>& numbers, const int target, int nDepth, int nSum)
{
	
	if (nDepth == numbers.size())
	{
		if (nSum == target)
			nCnt++;
		return;
	}

	dfs(numbers, target, nDepth + 1, nSum + numbers[nDepth]);
	dfs(numbers, target, nDepth + 1, nSum + numbers[nDepth] * -1);


}

int solution(vector<int> numbers, int target) 
{
	int answer = 0;

	dfs(numbers, target, 0, 0);

	return answer;
}
int main()
{
	int n = 5;
	vector<vector<int>> triangle;

	vector<int>	vecTemp;

	const int nTmp1 = 5;
	int naTmp1[nTmp1] = { 1, 1, 1, 1, 1 };
	vecTemp.assign(naTmp1, naTmp1 + nTmp1);
	triangle.push_back(vecTemp);


	int ntarget = 3;
	solution(vecTemp, ntarget);


	return 0;
}
