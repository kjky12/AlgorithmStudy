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
URL : https://programmers.co.kr/learn/courses/30/lessons/42748


문제 설명
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
2에서 나온 배열의 3번째 숫자는 5입니다.
배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
array의 길이는 1 이상 100 이하입니다.
array의 각 원소는 1 이상 100 이하입니다.
commands의 길이는 1 이상 50 이하입니다.
commands의 각 원소는 길이가 3입니다.
입출력 예
array	                commands	                        return
[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
입출력 예 설명
[1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
[1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
[1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.



*/

int main()
{

	vector<int> array;
	vector<vector<int>> commands;




	///////////////////////////////////////////////
	//Case 1
	const int nTmp1 = 7;
	int strTmp1[nTmp1] = { 1, 5, 2, 6, 3, 7, 4 };
	array.assign(strTmp1, strTmp1 + nTmp1);

	vector<int> vecTmp;
	const int nTmp2 = 3;
	int strTmp2[nTmp2] = { 2, 5, 3 };
	vecTmp.assign(strTmp2, strTmp2 + nTmp2);
	commands.push_back(vecTmp);

	int strTmp3[nTmp2] = { 4, 4, 1 };
	vecTmp.assign(strTmp3, strTmp3 + nTmp2);
	commands.push_back(vecTmp);

	int strTmp4[nTmp2] = { 1, 7, 3 };
	vecTmp.assign(strTmp4, strTmp4 + nTmp2);
	commands.push_back(vecTmp);

	//////////////////////////////////////////
	vector<int> answer;
	for (size_t i = 0; i < commands.size(); i++)
	{
		if (commands[i].size() == 3)
		{
			int nStartIdx = commands[i][0];
			int nEndIdx = commands[i][1];
			int nPosIdx = commands[i][2];

			vector<int> vecTemp(array.begin() + nStartIdx - 1, array.begin() + nEndIdx);

			sort(vecTemp.begin(), vecTemp.end(), less<int>());

			answer.push_back(vecTemp[nPosIdx -1 ]);


			//commands[i][]


		}



	}







	//cout << answer << endl;

	return 0;
}