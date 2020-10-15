//! 출력 사용
#include <iostream>

//! 문자열 사용
#include "string"
//! 문자열 함수 사용
#include "string.h"

#include "algorithm"

//! 백터 사용
#include <vector>

using namespace std;


/*
https://programmers.co.kr/learn/courses/30/lessons/43165
*

문제 설명
n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.
입출력 예
numbers	target	return
[1, 1, 1, 1, 1]	3	5
입출력 예 설명

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
