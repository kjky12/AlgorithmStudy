//! ��� ���
#include <iostream>

//! ���ڿ� ���
#include "string"
//! ���ڿ� �Լ� ���
#include "string.h"

#include "algorithm"
#include "math.h"

//! ���� ���
#include <vector>

using namespace std;


/*

https://programmers.co.kr/skill_checks/195475?challenge_id=849

���� ����
124 ���� �ֽ��ϴ�. 124 ���󿡼��� 10������ �ƴ� ������ ���� �ڽŵ鸸�� ��Ģ���� ���� ǥ���մϴ�.

124 ���󿡴� �ڿ����� �����մϴ�.
124 ���󿡴� ��� ���� ǥ���� �� 1, 2, 4�� ����մϴ�.
���� �� 124 ���󿡼� ����ϴ� ���ڴ� ������ ���� ��ȯ�˴ϴ�.

10����	124 ����	10����	124 ����
1	1	6	14
2	2	7	21
3	4	8	22
4	11	9	24
5	12	10	41
�ڿ��� n�� �Ű������� �־��� ��, n�� 124 ���󿡼� ����ϴ� ���ڷ� �ٲ� ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
n�� 500,000,000������ �ڿ��� �Դϴ�.
����� ��
n	result
1	1
2	2
3	4
4	11


*/
char chT[3] = { '1' , '2' , '4' };

char ConvertNmg(int nNmg)
{
	int nIdx = 0;
	if (nNmg == 0)
		nIdx = 2;
	else
		nIdx = nNmg - 1;
	return chT[nIdx];
}

string solution(int n) 
{
	string answer = "";

	int nDiv = n;

	while (nDiv > 0)
	{
		int nNmg = nDiv % 3;

		answer = ConvertNmg(nNmg ) + answer;

		cout << nDiv << "\t" << nNmg << "\t" << answer  << endl;

		//! 0�� ���ܵǱ⶧���� ��迡���� �ѹ� �� ó�����ش�.
		if (nNmg == 0)
			nDiv = nDiv / 3 - 1;
		else
			nDiv = nDiv / 3;
	}

	return answer;
}


int main()
{
	solution(3);

	return 0;
}
