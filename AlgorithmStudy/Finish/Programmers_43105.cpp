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
https://programmers.co.kr/learn/courses/30/lessons/43105
*
문제 설명
스크린샷 2018-09-14 오후 5.44.19.png

위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

제한사항
삼각형의 높이는 1 이상 500 이하입니다.
삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
입출력 예
triangle	result
[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	30

*/




int solution(vector<vector<int>> triangle) 
{
	int answer = 0;

	//! 아래 노드의 2개의 값과 더해줘야 하기 때문에 하단 결과 입력 메모리를 2배로 만들어줌
	vector<vector<int>> dp(triangle.size());
	for (size_t i = 0; i < triangle.size(); i++)
	{
		//! 처음꺼도 계산해야하므로 처음껀 1개만 입력!
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
			//! 다음 영역 메모리에 값을 더해줌
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
