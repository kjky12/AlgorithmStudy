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
[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]

카카오는 하반기 경력 개발자 공개채용을 진행 중에 있으며 현재 지원서 접수와 코딩테스트가 종료되었습니다. 이번 채용에서 지원자는 지원서 작성 시 아래와 같이 4가지 항목을 반드시 선택하도록 하였습니다.

코딩테스트 참여 개발언어 항목에 cpp, java, python 중 하나를 선택해야 합니다.
지원 직군 항목에 backend와 frontend 중 하나를 선택해야 합니다.
지원 경력구분 항목에 junior와 senior 중 하나를 선택해야 합니다.
선호하는 소울푸드로 chicken과 pizza 중 하나를 선택해야 합니다.
인재영입팀에 근무하고 있는 니니즈는 코딩테스트 결과를 분석하여 채용에 참여한 개발팀들에 제공하기 위해 지원자들의 지원 조건을 선택하면 해당 조건에 맞는 지원자가 몇 명인 지 쉽게 알 수 있는 도구를 만들고 있습니다.
예를 들어, 개발팀에서 궁금해하는 문의사항은 다음과 같은 형태가 될 수 있습니다.
코딩테스트에 java로 참여했으며, backend 직군을 선택했고, junior 경력이면서, 소울푸드로 pizza를 선택한 사람 중 코딩테스트 점수를 50점 이상 받은 지원자는 몇 명인가?

물론 이 외에도 각 개발팀의 상황에 따라 아래와 같이 다양한 형태의 문의가 있을 수 있습니다.

코딩테스트에 python으로 참여했으며, frontend 직군을 선택했고, senior 경력이면서, 소울푸드로 chicken을 선택한 사람 중 코딩테스트 점수를 100점 이상 받은 사람은 모두 몇 명인가?
코딩테스트에 cpp로 참여했으며, senior 경력이면서, 소울푸드로 pizza를 선택한 사람 중 코딩테스트 점수를 100점 이상 받은 사람은 모두 몇 명인가?
backend 직군을 선택했고, senior 경력이면서 코딩테스트 점수를 200점 이상 받은 사람은 모두 몇 명인가?
소울푸드로 chicken을 선택한 사람 중 코딩테스트 점수를 250점 이상 받은 사람은 모두 몇 명인가?
코딩테스트 점수를 150점 이상 받은 사람은 모두 몇 명인가?
즉, 개발팀에서 궁금해하는 내용은 다음과 같은 형태를 갖습니다.

* [조건]을 만족하는 사람 중 코딩테스트 점수를 X점 이상 받은 사람은 모두 몇 명인가?
[문제]
지원자가 지원서에 입력한 4가지의 정보와 획득한 코딩테스트 점수를 하나의 문자열로 구성한 값의 배열 info, 개발팀이 궁금해하는 문의조건이 문자열 형태로 담긴 배열 query가 매개변수로 주어질 때,
각 문의조건에 해당하는 사람들의 숫자를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

[제한사항]
info 배열의 크기는 1 이상 50,000 이하입니다.
info 배열 각 원소의 값은 지원자가 지원서에 입력한 4가지 값과 코딩테스트 점수를 합친 개발언어 직군 경력 소울푸드 점수 형식입니다.
개발언어는 cpp, java, python 중 하나입니다.
직군은 backend, frontend 중 하나입니다.
경력은 junior, senior 중 하나입니다.
소울푸드는 chicken, pizza 중 하나입니다.
점수는 코딩테스트 점수를 의미하며, 1 이상 100,000 이하인 자연수입니다.
각 단어는 공백문자(스페이스 바) 하나로 구분되어 있습니다.
query 배열의 크기는 1 이상 100,000 이하입니다.
query의 각 문자열은 [조건] X 형식입니다.
[조건]은 개발언어 and 직군 and 경력 and 소울푸드 형식의 문자열입니다.
언어는 cpp, java, python, - 중 하나입니다.
직군은 backend, frontend, - 중 하나입니다.
경력은 junior, senior, - 중 하나입니다.
소울푸드는 chicken, pizza, - 중 하나입니다.
'-' 표시는 해당 조건을 고려하지 않겠다는 의미입니다.
X는 코딩테스트 점수를 의미하며 조건을 만족하는 사람 중 X점 이상 받은 사람은 모두 몇 명인 지를 의미합니다.
각 단어는 공백문자(스페이스 바) 하나로 구분되어 있습니다.
예를 들면, cpp and - and senior and pizza 500은 cpp로 코딩테스트를 봤으며, 경력은 senior 이면서 소울푸드로 pizza를 선택한 지원자 중 코딩테스트 점수를 500점 이상 받은 사람은 모두 몇 명인가?를 의미합니다.
[입출력 예]
info	query	result
["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]	["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]	[1,1,1,1,2,4]
입출력 예에 대한 설명
지원자 정보를 표로 나타내면 다음과 같습니다.

언어	직군	경력	소울 푸드	점수
java	backend	junior	pizza	150
python	frontend	senior	chicken	210
python	frontend	senior	chicken	150
cpp	backend	senior	pizza	260
java	backend	junior	chicken	80
python	backend	senior	chicken	50
"java and backend and junior and pizza 100" : java로 코딩테스트를 봤으며, backend 직군을 선택했고 junior 경력이면서 소울푸드로 pizza를 선택한 지원자 중 코딩테스트 점수를 100점 이상 받은 지원자는 1명 입니다.
"python and frontend and senior and chicken 200" : python으로 코딩테스트를 봤으며, frontend 직군을 선택했고, senior 경력이면서 소울 푸드로 chicken을 선택한 지원자 중 코딩테스트 점수를 200점 이상 받은 지원자는 1명 입니다.
"cpp and - and senior and pizza 250" : cpp로 코딩테스트를 봤으며, senior 경력이면서 소울푸드로 pizza를 선택한 지원자 중 코딩테스트 점수를 250점 이상 받은 지원자는 1명 입니다.
"- and backend and senior and - 150" : backend 직군을 선택했고, senior 경력인 지원자 중 코딩테스트 점수를 150점 이상 받은 지원자는 1명 입니다.
"- and - and - and chicken 100" : 소울푸드로 chicken을 선택한 지원자 중 코딩테스트 점수를 100점 이상을 받은 지원자는 2명 입니다.
"- and - and - and - 150" : 코딩테스트 점수를 150점 이상 받은 지원자는 4명 입니다.


*/


struct ST_VALUE_INFO
{
	bool	bApply;		//! 0: 지원자, 1:쿼리문
	short	sLanguage;	//! 0 : cpp, 1: java, 2: python, 3: -
	short	sPosition;	//! 0 : backend, 1 : frontend, 3: -
	short	sCareer;	//! 0 : junior, 1 : senior, 3: -
	short	sSoulFood;	//! 0 : chicken, 1: pizza, 3: -
	int		nScore;		//! 1 ~ 100,000

	ST_VALUE_INFO* operator () (const ST_VALUE_INFO& stApply) const
	{
		if (sLanguage != 3)	//! 0 : cpp, 1: java, 2: python, 3: -
		{
			if (sLanguage != stApply.sLanguage)
				return NULL;
		}

		if (sPosition != 3)	//! 0 : backend, 1 : frontend, 3: -
		{
			if (sPosition != stApply.sPosition)
				return NULL;
		}

		if (sCareer != 3)	//! 0 : junior, 1 : senior, 3: -   
		{
			if (sCareer != stApply.sCareer)
				return NULL;
		}

		if (sSoulFood != 3)	//! 0 : chicken, 1: pizza, 3: -	   
		{
			if (sSoulFood != stApply.sSoulFood)
				return NULL;
		}

		//! 1 ~ 100,000				   
		if (nScore > stApply.nScore)
			return NULL;

		return (ST_VALUE_INFO*)this;
	}


};

void ConvertApplyInfo(vector<ST_VALUE_INFO>& vecApplyUsreInfo, vector<string> info)
{
	for (size_t i = 0; i < info.size(); i++)
	{
		string strUnit = info[i] + " ";
		int nStep = 0;
		int nFind = strUnit.find(" ");
		int nIdx = 0;

		ST_VALUE_INFO	stApplyUsreInfo;
		stApplyUsreInfo.bApply = 0;	//! 지원자
		while (nFind >= 0)
		{
			string strValue = strUnit.substr(nStep, nFind - nStep);
			nStep = nFind + 1;
			nFind = strUnit.find(" ", nStep + 1);

			switch (nIdx)
			{
			case 0:
				stApplyUsreInfo.sLanguage = (strValue == "cpp") ? 0 : (strValue == "java") ? 1 : 2;;	//! 0 : cpp, 1: java, 2: python
				break;
			case 1:
				stApplyUsreInfo.sPosition = (strValue == "backend") ? 0 : 1;	//! 0 : backend, 1 : frontend
				break;
			case 2:
				stApplyUsreInfo.sCareer = (strValue == "junior") ? 0 : 1;	//! 0 : junior, 1 : senior
				break;
			case 3:
				stApplyUsreInfo.sSoulFood = (strValue == "chicken") ? 0 : 1;	//! 0 : chicken, 1: pizza
				break;
			case 4:
				stApplyUsreInfo.nScore = stoi(strValue);		//! 1 ~ 100,000
				break;
			default:
				break;
			}

			nIdx += 1;
		}

		vecApplyUsreInfo.push_back(stApplyUsreInfo);
	}
}

void Convertquery(vector<ST_VALUE_INFO>& vecQuery, vector<string> query)
{
	for (size_t i = 0; i < query.size(); i++)
	{
		string strUnit = query[i] + " ";

		int nFindReplace = strUnit.find("and ");
		while (nFindReplace >= 0)
		{
			strUnit.replace(nFindReplace, 4, "");
			nFindReplace = strUnit.find("and ");
		}

		int nStep = 0;
		int nFind = strUnit.find(" ");
		int nIdx = 0;

		ST_VALUE_INFO	stQuery;
		stQuery.bApply = 1;	//! 쿼리문
		while (nFind >= 0)
		{
			string strValue = strUnit.substr(nStep, nFind - nStep);
			nStep = nFind + 1;
			nFind = strUnit.find(" ", nStep + 1);

			switch (nIdx)
			{
			case 0:
				stQuery.sLanguage = (strValue == "cpp") ? 0 : (strValue == "java") ? 1 : (strValue == "python") ? 2 : 3;	//! 0 : cpp, 1: java, 2: python, 3: -
				break;
			case 1:
				stQuery.sPosition = (strValue == "backend") ? 0 : (strValue == "frontend") ? 1 : 3;	//! 0 : backend, 1 : frontend, 3: -
				break;
			case 2:
				stQuery.sCareer = (strValue == "junior") ? 0 : (strValue == "senior") ? 1 : 3;	//! 0 : junior, 1 : senior, 3: -
				break;
			case 3:
				stQuery.sSoulFood = (strValue == "chicken") ? 0 : (strValue == "pizza") ? 1 : 3;	//! 0 : chicken, 1: pizza, 3: -
				break;
			case 4:
				stQuery.nScore = stoi(strValue);		//! 1 ~ 100,000
				break;
			default:
				break;
			}

			nIdx += 1;
		}

		vecQuery.push_back(stQuery);
	}
}

bool IsFindQuery(ST_VALUE_INFO stQuery, ST_VALUE_INFO stApply)
{ 

	if (stQuery.sLanguage != 3)	//! 0 : cpp, 1: java, 2: python, 3: -
	{
		if (stQuery.sLanguage != stApply.sLanguage)
			return false;
	}

	if (stQuery.sPosition != 3)	//! 0 : backend, 1 : frontend, 3: -
	{
		if (stQuery.sPosition != stApply.sPosition)
			return false;
	}

	if (stQuery.sCareer != 3)	//! 0 : junior, 1 : senior, 3: -   
	{
		if (stQuery.sCareer != stApply.sCareer)
			return false;
	}

	if (stQuery.sSoulFood != 3)	//! 0 : chicken, 1: pizza, 3: -	   
	{
		if (stQuery.sSoulFood != stApply.sSoulFood)
			return false;
	}

	//! 1 ~ 100,000				   
	if (stQuery.nScore > stApply.nScore)
			return false;

	return true;
}


int main()
{
	vector<string> info;
	vector<string> query;

	//const int nTmp1 = 6;
	//string strTmp1[nTmp1] = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	//orders.assign(strTmp1, strTmp1 + nTmp1);

	//const int nTmp2 = 10;
	//int naTmp2[nTmp2] = { 2, 3, 4 };
	//course.assign(naTmp2, naTmp2 + nTmp2);


	const int nTmp1 = 6;
	string strTmp1[nTmp1] = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	info.assign(strTmp1, strTmp1 + nTmp1);

	const int nTmp2 = 6;
	string strTmp2[nTmp2] = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	query.assign(strTmp2, strTmp2 + nTmp2);



	vector<ST_VALUE_INFO>	vecApplyUsreInfo;
	ConvertApplyInfo(vecApplyUsreInfo, info);


	vector<ST_VALUE_INFO>	vecQuery;
	Convertquery(vecQuery, query);

	vector<int> answer(vecQuery.size());

	//vector<ST_VALUE_INFO>::iterator it = find_if(vecApplyUsreInfo.begin(), vecApplyUsreInfo.end(), IsFindQuery(vecApplyUsreInfo[0],vecQuery[0]));

	//vector<ST_VALUE_INFO>::iterator it = 
	ST_VALUE_INFO bT = std::find_if(vecQuery.begin(), vecQuery.end(), [&vecApplyUsreInfo](const ST_VALUE_INFO& stT) {
		IsFindQuery(stT, vecApplyUsreInfo[0]);
	});
	//if (it != vecQuery.end())
	//{
	//	int ntest = 0;
	//}

	vector<ST_VALUE_INFO>::iterator itApp;
	vector<ST_VALUE_INFO>::iterator itQry;
	int nIdx = 0;
	for (itQry = vecQuery.begin(); itQry != vecQuery.end(); itQry++)
	{
		//cout << "QU:" << itQry->sLanguage << "\t";
		//cout << itQry->sPosition << "\t";
		//cout << itQry->sCareer << "\t";
		//cout << itQry->sSoulFood << "\t";
		//cout << itQry->nScore << "\n";




		int nCnt = 0;
		for (itApp = vecApplyUsreInfo.begin(); itApp != vecApplyUsreInfo.end(); itApp++)
		{

			//cout << "AP:" << itApp->sLanguage << "\t";
			//cout << itApp->sPosition << "\t";
			//cout << itApp->sCareer << "\t";
			//cout << itApp->sSoulFood << "\t";
			//cout << itApp->nScore << "\t";

			if (IsFindQuery(*itQry, *itApp))
			{
				//cout << "PASS" << "\n";
				nCnt++;

				//break;
			}
			else
			{
				//cout << "FAIL" << "\n";

			}

			//cout << "\n";

		}

		//cout << nIdx<<"-FIN\n\n";

		answer[nIdx] = nCnt;
		nIdx++;
	}
	




	return 0;
}

