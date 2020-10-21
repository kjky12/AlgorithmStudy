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

https://programmers.co.kr/learn/courses/30/lessons/42883

문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	k	return
1924	2	94
1231234	3	3234
4177252841	4	775841

*/
using namespace std;

//[10/21/2020 kjky12] 접근 방향은 맞는듯 하나 중간에 if문이 들어가서 효율성이 안되고 중간중간 erase를 해주니 느림...
// -> 추가적으로 인덱스를 통해 값을 추출하여야 할듯하다
string solution(string number, int k) {
	string answer = "";

	//! 정답의 길이!
	int nAnswerCnt = number.length() - k;

	while (true)
	{
		int nSize = number.length();
		for (size_t i = 0; i < nSize - 1; i++)
		{

			for (size_t j = i + 1; j < nSize; j++)
			{
				if (number[i] < number[j])
				{
					int nDelCnt = j - i;
					if (number.length() - nDelCnt < nAnswerCnt)
						break;

					number.erase(i, nDelCnt);
					k -= (j - i);
					break;
				}

			}

			if (number.length() != nSize)
			{
				cout << number << endl;

				//nSize = number.length();
				break;
			}

		}

		if (number.length() == nAnswerCnt)
			break;
	}

	answer = number;
	return answer;
}


int main()
{
	//solution("1924", 2);
	//solution("1231234", 3);
	solution("4177252841", 4);

	return 0;
}
