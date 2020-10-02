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

