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

char TransId(char chT)
{
	if (chT >= 'A' && chT <= 'Z')
		chT = chT - ('A' - 'a');

	return chT;
}

void RemoveChar(string& strInput, string strFilter)
{
	for (size_t i = 0; i < strFilter.size(); i++)
	{
		strInput.erase(remove(strInput.begin(), strInput.end(), strFilter[i]), strInput.end());
	}
}

void DeleteSideChar(string& strInput, string strSide)
{
	if (strInput.size() == 0)
		return;

	int nFind = strInput.find(".");
	if (nFind == 0)
		strInput.erase(0, 1);

	if (strInput.size() == 0)
		return;

	nFind = strInput.rfind(".");
	if (nFind == strInput.size() - 1)
		strInput.erase(nFind, 1);
}

//orders											course				result
//["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]	[2, 3, 4]			["AC", "ACDE", "BCFG", "CDE"]
//["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"] [2, 3, 5]			["ACD", "AD", "ADE", "CD", "XYZ"]
//["XYZ", "XWY", "WXA"]								[2, 3, 4]			["WX", "XY"]

bool MakeAllType(vector<string> &vecCourseTypeAll, string strResult, int nIdx, const string strInput, const int nMaxLength)
{
	if (strResult.size() == nMaxLength)
	{
		vecCourseTypeAll.push_back(strResult);
	}
	else
	{
		for (size_t i = nIdx + 1; i < strInput.size(); i++)
		{
			MakeAllType(vecCourseTypeAll, strResult + strInput[i], i, strInput, nMaxLength);
		}
	}
	
	return true;
}


int main()
{
	vector<string> orders;
	vector<int> course;


	//const int nTmp1 = 6;
	//string strTmp1[nTmp1] = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	//orders.assign(strTmp1, strTmp1 + nTmp1);

	//const int nTmp2 = 10;
	//int naTmp2[nTmp2] = { 2, 3, 4 };
	//course.assign(naTmp2, naTmp2 + nTmp2);


	const int nTmp1 = 7;
	string strTmp1[nTmp1] = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
	orders.assign(strTmp1, strTmp1 + nTmp1);

	const int nTmp2 = 3;
	int naTmp2[nTmp2] = { 2, 3, 5 };
	course.assign(naTmp2, naTmp2 + nTmp2);


	


	vector<string> answer;

	//! 전체 메뉴의 종류를 받아와서 소팅해준다.
	string strAllMenu = "";
	for (size_t i = 0; i < orders.size(); i++)
	{
		//! 혹시 모르니 주문도 소팅해준다.
		sort(orders[i].begin(), orders[i].end());
		strAllMenu += orders[i];
	}
	
	////////////////////////////////////////////////////
	//! 전체 메뉴에대한 모든 정보를 만들어준다.
	sort(strAllMenu.begin(), strAllMenu.end());
	strAllMenu.erase(unique(strAllMenu.begin(), strAllMenu.end()), strAllMenu.end());
	int nAllMenuCnt = strAllMenu.size();

	for (size_t i = 0; i < course.size(); i++)
	{
		int nCourseCnt = course[i];
		
		vector<string> vecCourseTypeAll;
		for (size_t x = 0; x < strAllMenu.size(); x++)
		{
			string strCourseTypeUnit = "";
			strCourseTypeUnit += strAllMenu[x];
			MakeAllType(vecCourseTypeAll, strCourseTypeUnit, x, strAllMenu, nCourseCnt);
		}
		
		vector<int> vecCourseTypeAllCnt(vecCourseTypeAll.size());
		for (size_t y = 0; y < orders.size(); y++)
		{
			string strorderUnit = orders[y];

			for (size_t m = 0; m < vecCourseTypeAll.size(); m++)
			{
				string strAllUnit = vecCourseTypeAll[m];
				if (strAllUnit.size() > 0)
				{
					int n = 0;
					int nFind = strorderUnit.find(strAllUnit[n]);
					while (nFind >= 0)
					{
						n++;
						nFind = strorderUnit.find(strAllUnit[n]);
					}

					if (strAllUnit.size() == n)
					{
						vecCourseTypeAllCnt[m] += 1;
					}
				}
				
			}
		}

		vector<int>::iterator iterCourseTypeAllCnt;
		iterCourseTypeAllCnt = max_element(vecCourseTypeAllCnt.begin(), vecCourseTypeAllCnt.end());

		if (*iterCourseTypeAllCnt >= 2)
		{
			for (size_t k = 0; k < vecCourseTypeAllCnt.size(); k++)
			{

				if (*iterCourseTypeAllCnt == vecCourseTypeAllCnt[k])
					answer.push_back(vecCourseTypeAll[k]);
			}

		}
		
		int k = 0;

	}

	sort(answer.begin(), answer.end());

	return 0;
}

