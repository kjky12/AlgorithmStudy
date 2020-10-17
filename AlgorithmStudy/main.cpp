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

https://programmers.co.kr/learn/courses/30/lessons/42860

문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동
예를 들어 아래의 방법으로 JAZ를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
JEROEN	56
JAN	23

*/

char chCurrentPos = 'A';

//! 좌우 방향키만으로 움직여서 가는 개수 카운트
int GetLeftRightMoveCnt(char chTarget)
{
	int nStep = abs(chCurrentPos - chTarget);
	return nStep;
}


//! 오른쪽으로 붙어서 움직여서 가는 개수 카운트
int GetRightAndMoveCnt(char chTarget)
{
	int nStep = 0;
	if (chCurrentPos != 'Z')
		nStep++;

	nStep += abs('Z' - chTarget);

	return nStep;
}

//! 왼쪽으로 붙어서 움직여서 가는 개수 카운트
int GetLeftAndMoveCnt(char chTarget)
{
	int nStep = 0;
	if (chCurrentPos != 'A')
		nStep++;

	nStep += abs('A' - chTarget);

	return nStep;
}


int solution(string name) {
	
	chCurrentPos = 'A';
	int answer = 0;

	for (size_t i = 0; i < name.length(); i++)
	{
		int nMove1 = GetLeftRightMoveCnt(name[i]);
		int nMove2 = GetRightAndMoveCnt(name[i]);
		//int nMove3 = GetLeftAndMoveCnt(name[i]);

		int Min = min(nMove1, nMove2);
		//Min = min(Min, nMove3);

		answer += Min;
		chCurrentPos = name[i];
	}

	return answer;
}

int main()
{
	
	solution("JAZ");
	solution("JEROEN");
	solution("JAN");

	return 0;
}
