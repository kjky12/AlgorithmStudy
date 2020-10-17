//! 출력 사용
#include <iostream>

//! 문자열 사용
#include "string"
//! 문자열 함수 사용
#include "string.h"

#include "algorithm"
#include "math.h"

//! 백터 사용
#include <vector>

using namespace std;


/*

https://programmers.co.kr/skill_checks/195475?challenge_id=849

문제 설명
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

10진법	124 나라	10진법	124 나라
1	1	6	14
2	2	7	21
3	4	8	22
4	11	9	24
5	12	10	41
자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.

제한사항
n은 500,000,000이하의 자연수 입니다.
입출력 예
n	result
1	1
2	2
3	4
4	11


*/
char chT[3] = { '1' , '2' , '4' };

char ConvertNmg(int nNmg)
{
	int nIdx = 0;
	if (nNmg == 0)
		nIdx = 2;
	else
		nIdx = nNmg - 1;
	return chT[nIdx];
}

string solution(int n) 
{
	string answer = "";

	int nDiv = n;

	while (nDiv > 0)
	{
		int nNmg = nDiv % 3;

		answer = ConvertNmg(nNmg ) + answer;

		cout << nDiv << "\t" << nNmg << "\t" << answer  << endl;

		//! 0이 제외되기때문에 경계에서는 한번 덜 처리해준다.
		if (nNmg == 0)
			nDiv = nDiv / 3 - 1;
		else
			nDiv = nDiv / 3;
	}

	return answer;
}


int main()
{
	solution(3);

	return 0;
}
