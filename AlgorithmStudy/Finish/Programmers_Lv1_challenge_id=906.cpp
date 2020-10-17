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

https://programmers.co.kr/skill_checks/195469?challenge_id=906

문제 설명
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

제한 사항
str은 길이 1 이상인 문자열입니다.
입출력 예
s	return
Zbcdefg	gfedcbZ


*/

string solution(string s) 
{
	string sBig;
	string sSmall;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			sBig += s[i];
		else
			sSmall += s[i];
		
	}
	
	sort(sBig.begin(), sBig.end(), greater<int>());
	sort(sSmall.begin(), sSmall.end(), greater<int>());

	string answer = sSmall + sBig;
	return answer;
}


int main()
{
	solution("Zbcdefg");

	return 0;
}
