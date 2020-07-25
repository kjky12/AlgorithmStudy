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
URL : https://programmers.co.kr/learn/courses/30/lessons/42576

문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

participant
[leo, kiki, eden]
[marina, josipa, nikola, vinko, filipa]
[mislav, stanko, mislav, ana]

completion
[eden, kiki]
[josipa, filipa, marina, nikola]
[stanko, ana, mislav]


입출력 예 설명
예제 #1
leo는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2
vinko는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3
mislav는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.



*/

int main()
{
	vector<string> participant;

	vector<string> completion;




	///////////////////////////////////////////////
	//Case 1
	// const int nTmp1 = 3;
	// string strTmp1[nTmp1] = {"leo", "kiki", "eden"};
	// participant.assign(strTmp1, strTmp1+nTmp1);

	// const int nTmp2 = 2;
	// string strTmp2[nTmp2] = {"eden", "kiki"};
	// completion.assign(strTmp2, strTmp2+nTmp2);

	////////////////////////////////////////////////
	//Case 2
/*     const int nTmp1 = 5;
	string strTmp1[nTmp1] = {"marina", "josipa", "nikola", "vinko", "filipa"};
	participant.assign(strTmp1, strTmp1+nTmp1);

	const int nTmp2 = 4;
	string strTmp2[nTmp2] = {"josipa", "filipa", "marina", "nikola"};
	completion.assign(strTmp2, strTmp2+nTmp2);
 */

 ////////////////////////////////////////////////
 //Case 2
	const int nTmp1 = 4;
	string strTmp1[nTmp1] = { "mislav", "stanko", "mislav", "ana" };
	participant.assign(strTmp1, strTmp1 + nTmp1);

	const int nTmp2 = 3;
	string strTmp2[nTmp2] = { "stanko", "ana", "mislav" };
	completion.assign(strTmp2, strTmp2 + nTmp2);

	////////////////////////////////////////////////
	////////////////////////////////////////////////
/*     for (size_t i = 0; i < participant.size(); i++)
	{
		cout << participant[i] << endl;

	} */


	////////////////////////////////////////////////
	////////////////////////////////////////////////
	////////////////////////////////////////////////
	////////////////////////////////////////////////

	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());


	int nIdx = 0;
	for (vector<string>::const_iterator iterParti = participant.begin(); iterParti != participant.end(); iterParti++)
	{
		bool bFlag = false;

		vector<string>::const_iterator itercompl = completion.begin() + nIdx;
		while (itercompl != completion.end())
		{
			nIdx++;

			if (*iterParti == *itercompl)
			{
				bFlag = true;

				break;
			}

			itercompl++;
		}

		if (bFlag == false)
		{
			answer = *iterParti;
			break;
		}
	}


	cout << answer << endl;

	return 0;
}