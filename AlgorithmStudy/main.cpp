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

void dfs_recursion(vector<vector<int>>	*pvecPlusMinus, int nDepth)
{


	for (size_t i = 0; i < length; i++)
	{

	}

}

int solution(vector<int> numbers, int target) 
{
	vector<vector<int>>	vecPlusMinus(numbers.size(), vector<int>(2));
	for (size_t i = 0; i < vecPlusMinus.size(); i++)
	{
		vecPlusMinus[i][0] = +1;
		vecPlusMinus[i][1] = -1;
	}

	int answer = 0;

	vector<vector<int>>	vecResult(numbers.size() * 2, vector<int>(numbers.size()));

	for (size_t i = 0; i < 2; i++)
	{
		dfs_recursion(&vecPlusMinus, i);
	}
	


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
