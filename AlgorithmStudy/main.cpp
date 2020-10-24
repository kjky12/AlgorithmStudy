//! 출력 사용
#include <iostream>
#include <fstream>

#include "string"
//! 문자열 함수 사용
#include "string.h"

#include "algorithm"
#include "math.h"

//! 백터 사용
#include <vector>

using namespace std;


/*

문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

입출력 예
numbers	return
17	3
011	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.


*/
using namespace std;

int solution(string numbers) 
{
	//http://dumpsys.blogspot.com/2015/03/algorithm-binary-counting-power-set.html
	int nSize = numbers.length();
	
	/////////////////////////////////////////////////
	//! 3자리 비트마스크 조합 -> 비트마스크로 조합을 가진다.!!
	int n = nSize;
	vector<string>	vecNum;
	for (int i = 0; i < (1 << (n)); i++)
	{
		string	strTemp;
		for (int j = 0; j < n; j++) 
		{
			if (i & (1 << j))
			{
				//printf("%c ", numbers[j]);
				strTemp += numbers[j];
			}
		}
		//printf("\n");

		if(strTemp.length() > 0)
			vecNum.push_back(strTemp);
	}

	sort(vecNum.begin(), vecNum.end());
	vecNum.erase(unique(vecNum.begin(), vecNum.end()), vecNum.end());


	vector<int>	vecAllNum;
	for (size_t i = 0; i < vecNum.size(); i++)
	{
		string	strTemp = vecNum[i];
		//! 소팅을 해주고 순열을 구해야지 전체 순열이 제대로 얻어와 진다!!
		sort(strTemp.begin(), strTemp.end());

		do {
			int nValue = atoi(strTemp.c_str());

			vecAllNum.push_back(nValue);

		} while (next_permutation(strTemp.begin(), strTemp.end()));

	}
	int answer = 0;

	sort(vecAllNum.begin(), vecAllNum.end());
	vecAllNum.erase(unique(vecAllNum.begin(), vecAllNum.end()), vecAllNum.end());

	for (size_t i = 0; i < vecAllNum.size(); i++)
	{
		bool bflag = true;
		int nValue = vecAllNum[i];

		if (nValue < 2)
			continue;

		for (int j = 2; j < nValue / 2 + 1; j++)
		{
			if (nValue % j == 0)
			{
				bflag = false;
				break;
			}
		}

		if (bflag)
		{
			answer++;
		}

	}

	return answer;
}


int main()
{

	solution("48924");

	return 0;
}
