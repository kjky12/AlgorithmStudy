//! ��� ���
#include <iostream>

//! ���ڿ� ���
#include "string"
//! ���ڿ� �Լ� ���
#include "string.h"

#include "algorithm"

//! ���� ���
#include <vector>

using namespace std;


/*
[�� ������ ��Ȯ���� ȿ���� �׽�Ʈ ���� ������ �ִ� �����Դϴ�.]

īī���� �Ϲݱ� ��� ������ ����ä���� ���� �߿� ������ ���� ������ ������ �ڵ��׽�Ʈ�� ����Ǿ����ϴ�. �̹� ä�뿡�� �����ڴ� ������ �ۼ� �� �Ʒ��� ���� 4���� �׸��� �ݵ�� �����ϵ��� �Ͽ����ϴ�.

�ڵ��׽�Ʈ ���� ���߾�� �׸� cpp, java, python �� �ϳ��� �����ؾ� �մϴ�.
���� ���� �׸� backend�� frontend �� �ϳ��� �����ؾ� �մϴ�.
���� ��±��� �׸� junior�� senior �� �ϳ��� �����ؾ� �մϴ�.
��ȣ�ϴ� �ҿ�Ǫ��� chicken�� pizza �� �ϳ��� �����ؾ� �մϴ�.
���翵������ �ٹ��ϰ� �ִ� �ϴ���� �ڵ��׽�Ʈ ����� �м��Ͽ� ä�뿡 ������ �������鿡 �����ϱ� ���� �����ڵ��� ���� ������ �����ϸ� �ش� ���ǿ� �´� �����ڰ� �� ���� �� ���� �� �� �ִ� ������ ����� �ֽ��ϴ�.
���� ���, ���������� �ñ����ϴ� ���ǻ����� ������ ���� ���°� �� �� �ֽ��ϴ�.
�ڵ��׽�Ʈ�� java�� ����������, backend ������ �����߰�, junior ����̸鼭, �ҿ�Ǫ��� pizza�� ������ ��� �� �ڵ��׽�Ʈ ������ 50�� �̻� ���� �����ڴ� �� ���ΰ�?

���� �� �ܿ��� �� �������� ��Ȳ�� ���� �Ʒ��� ���� �پ��� ������ ���ǰ� ���� �� �ֽ��ϴ�.

�ڵ��׽�Ʈ�� python���� ����������, frontend ������ �����߰�, senior ����̸鼭, �ҿ�Ǫ��� chicken�� ������ ��� �� �ڵ��׽�Ʈ ������ 100�� �̻� ���� ����� ��� �� ���ΰ�?
�ڵ��׽�Ʈ�� cpp�� ����������, senior ����̸鼭, �ҿ�Ǫ��� pizza�� ������ ��� �� �ڵ��׽�Ʈ ������ 100�� �̻� ���� ����� ��� �� ���ΰ�?
backend ������ �����߰�, senior ����̸鼭 �ڵ��׽�Ʈ ������ 200�� �̻� ���� ����� ��� �� ���ΰ�?
�ҿ�Ǫ��� chicken�� ������ ��� �� �ڵ��׽�Ʈ ������ 250�� �̻� ���� ����� ��� �� ���ΰ�?
�ڵ��׽�Ʈ ������ 150�� �̻� ���� ����� ��� �� ���ΰ�?
��, ���������� �ñ����ϴ� ������ ������ ���� ���¸� �����ϴ�.

* [����]�� �����ϴ� ��� �� �ڵ��׽�Ʈ ������ X�� �̻� ���� ����� ��� �� ���ΰ�?
[����]
�����ڰ� �������� �Է��� 4������ ������ ȹ���� �ڵ��׽�Ʈ ������ �ϳ��� ���ڿ��� ������ ���� �迭 info, �������� �ñ����ϴ� ���������� ���ڿ� ���·� ��� �迭 query�� �Ű������� �־��� ��,
�� �������ǿ� �ش��ϴ� ������� ���ڸ� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

[���ѻ���]
info �迭�� ũ��� 1 �̻� 50,000 �����Դϴ�.
info �迭 �� ������ ���� �����ڰ� �������� �Է��� 4���� ���� �ڵ��׽�Ʈ ������ ��ģ ���߾�� ���� ��� �ҿ�Ǫ�� ���� �����Դϴ�.
���߾��� cpp, java, python �� �ϳ��Դϴ�.
������ backend, frontend �� �ϳ��Դϴ�.
����� junior, senior �� �ϳ��Դϴ�.
�ҿ�Ǫ��� chicken, pizza �� �ϳ��Դϴ�.
������ �ڵ��׽�Ʈ ������ �ǹ��ϸ�, 1 �̻� 100,000 ������ �ڿ����Դϴ�.
�� �ܾ�� ���鹮��(�����̽� ��) �ϳ��� ���еǾ� �ֽ��ϴ�.
query �迭�� ũ��� 1 �̻� 100,000 �����Դϴ�.
query�� �� ���ڿ��� [����] X �����Դϴ�.
[����]�� ���߾�� and ���� and ��� and �ҿ�Ǫ�� ������ ���ڿ��Դϴ�.
���� cpp, java, python, - �� �ϳ��Դϴ�.
������ backend, frontend, - �� �ϳ��Դϴ�.
����� junior, senior, - �� �ϳ��Դϴ�.
�ҿ�Ǫ��� chicken, pizza, - �� �ϳ��Դϴ�.
'-' ǥ�ô� �ش� ������ ������� �ʰڴٴ� �ǹ��Դϴ�.
X�� �ڵ��׽�Ʈ ������ �ǹ��ϸ� ������ �����ϴ� ��� �� X�� �̻� ���� ����� ��� �� ���� ���� �ǹ��մϴ�.
�� �ܾ�� ���鹮��(�����̽� ��) �ϳ��� ���еǾ� �ֽ��ϴ�.
���� ���, cpp and - and senior and pizza 500�� cpp�� �ڵ��׽�Ʈ�� ������, ����� senior �̸鼭 �ҿ�Ǫ��� pizza�� ������ ������ �� �ڵ��׽�Ʈ ������ 500�� �̻� ���� ����� ��� �� ���ΰ�?�� �ǹ��մϴ�.
[����� ��]
info	query	result
["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]	["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]	[1,1,1,1,2,4]
����� ���� ���� ����
������ ������ ǥ�� ��Ÿ���� ������ �����ϴ�.

���	����	���	�ҿ� Ǫ��	����
java	backend	junior	pizza	150
python	frontend	senior	chicken	210
python	frontend	senior	chicken	150
cpp	backend	senior	pizza	260
java	backend	junior	chicken	80
python	backend	senior	chicken	50
"java and backend and junior and pizza 100" : java�� �ڵ��׽�Ʈ�� ������, backend ������ �����߰� junior ����̸鼭 �ҿ�Ǫ��� pizza�� ������ ������ �� �ڵ��׽�Ʈ ������ 100�� �̻� ���� �����ڴ� 1�� �Դϴ�.
"python and frontend and senior and chicken 200" : python���� �ڵ��׽�Ʈ�� ������, frontend ������ �����߰�, senior ����̸鼭 �ҿ� Ǫ��� chicken�� ������ ������ �� �ڵ��׽�Ʈ ������ 200�� �̻� ���� �����ڴ� 1�� �Դϴ�.
"cpp and - and senior and pizza 250" : cpp�� �ڵ��׽�Ʈ�� ������, senior ����̸鼭 �ҿ�Ǫ��� pizza�� ������ ������ �� �ڵ��׽�Ʈ ������ 250�� �̻� ���� �����ڴ� 1�� �Դϴ�.
"- and backend and senior and - 150" : backend ������ �����߰�, senior ����� ������ �� �ڵ��׽�Ʈ ������ 150�� �̻� ���� �����ڴ� 1�� �Դϴ�.
"- and - and - and chicken 100" : �ҿ�Ǫ��� chicken�� ������ ������ �� �ڵ��׽�Ʈ ������ 100�� �̻��� ���� �����ڴ� 2�� �Դϴ�.
"- and - and - and - 150" : �ڵ��׽�Ʈ ������ 150�� �̻� ���� �����ڴ� 4�� �Դϴ�.


*/


struct ST_VALUE_INFO
{
	bool	bApply;		//! 0: ������, 1:������
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
		stApplyUsreInfo.bApply = 0;	//! ������
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
		stQuery.bApply = 1;	//! ������
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

