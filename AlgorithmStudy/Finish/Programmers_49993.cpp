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

https://programmers.co.kr/learn/courses/30/lessons/49993

문제 설명
선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.

예를 들어 선행 스킬 순서가 스파크 → 라이트닝 볼트 → 썬더일때, 썬더를 배우려면 먼저 라이트닝 볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 스파크 → 힐링 → 라이트닝 볼트 → 썬더와 같은 스킬트리는 가능하지만, 썬더 → 스파크나 라이트닝 볼트 → 스파크 → 힐링 → 썬더와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.

제한 조건
스킬은 알파벳 대문자로 표기하며, 모든 문자열은 알파벳 대문자로만 이루어져 있습니다.
스킬 순서와 스킬트리는 문자열로 표기합니다.
예를 들어, C → B → D 라면 CBD로 표기합니다
선행 스킬 순서 skill의 길이는 1 이상 26 이하이며, 스킬은 중복해 주어지지 않습니다.
skill_trees는 길이 1 이상 20 이하인 배열입니다.
skill_trees의 원소는 스킬을 나타내는 문자열입니다.
skill_trees의 원소는 길이가 2 이상 26 이하인 문자열이며, 스킬이 중복해 주어지지 않습니다.
입출력 예
skill	skill_trees	return
"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2
입출력 예 설명
BACDE: B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트립니다.
CBADF: 가능한 스킬트리입니다.
AECB: 가능한 스킬트리입니다.
BDA: B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트리입니다.



*/



//int solution(string skill, vector<string> skill_trees) {
//	int answer = 0;
//
//
//
//	for (size_t i = 0; i < skill_trees.size(); i++)
//	{
//		int naChk[26] = { -1, };
//		for (size_t i = 0; i < 26; i++)
//			naChk[i] = -1;
//
//		for (size_t j = 0; j < skill.length(); j++)
//		{
//			int nFindIdx = skill_trees[i].find(skill[j]);
//			
//			naChk[j] = nFindIdx;
//		}
//
//		//! 선행스킬과 연관이 없는경우
//		int nT = *max_element(naChk, naChk + skill.length());
//		if (nT == -1)
//		{
//			answer++;
//			break;
//		}
//
//		//! 앞뒤값을 비교하며 확인해야한다.
//		// 1. 앞에가 -1이 나오면 뒤에 숫자가 있는경우 실패
//		// 2. 마지막 값이 있는 곳 이후로는 쭉 -1이 나와도됌
//		// 3. 앞에 숫자가 뒤에 숫자보다 클수 없음
//
//		bool bFlag = true;
//		for (size_t j = 0; j < skill.length() - 1; j++)
//		{
//			//! 앞에가 -1이면 실패임
//			if (naChk[j] == -1)
//			{
//				bFlag = false;
//				break;
//			}
//
//
//			if (naChk[j] > naChk[j + 1])
//			{
//				//! 여기서 뒷부분이 전부 -1이면 괜찮음
//				int nT = *max_element(naChk + j + 1, naChk + skill.length() - 1 + 1);
//				if (nT == -1)
//				{
//					//answer++;
//					break;
//				}
//
//				bFlag = false;
//				break;
//			}
//
//		}
//
//		if(bFlag == true)
//			answer++;
//	}
//
//	//answer = skill_trees.size() - answer;
//	return answer;
//}

////////////////////////////////////////////////////////////
//참고 : https://dvpzeekke.tistory.com/43
int IsCanSkillBuild(string skill, string skillUnit)
{
	string strTemp = "";
	for (size_t i = 0; i < skillUnit.length(); i++)
	{
		int nFind = skill.find(skillUnit[i]);

		if (nFind >= 0)
		{
			strTemp += skillUnit[i];
		}
	}

	int nFind = skill.find(strTemp);

	if (nFind == 0)
		return 1;
	else
		return 0;
}


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (size_t i = 0; i < skill_trees.size(); i++)
	{
		answer += IsCanSkillBuild(skill, skill_trees[i]);
	}


	return answer;
}


int main()
{
	vector<string>	vecTemp;

	//const int nTmp1 = 1;
	//string strTmp1[nTmp1] = { "CEFD"};
	const int nTmp1 = 4;
	string strTmp1[nTmp1] = { "BACDE", "CBADF", "AECB", "BDA" };
	vecTemp.assign(strTmp1, strTmp1 + nTmp1);


	//solution("CBD", vecTemp);
	

	solution("CBD", vecTemp);


	return 0;
}
