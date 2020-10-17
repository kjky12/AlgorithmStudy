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

https://programmers.co.kr/skill_checks/195469?challenge_id=906

���� ����
���ڿ� s�� ��Ÿ���� ���ڸ� ū�ͺ��� ���� ������ ������ ���ο� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
s�� ���� ��ҹ��ڷθ� �����Ǿ� ������, �빮�ڴ� �ҹ��ں��� ���� ������ �����մϴ�.

���� ����
str�� ���� 1 �̻��� ���ڿ��Դϴ�.
����� ��
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
