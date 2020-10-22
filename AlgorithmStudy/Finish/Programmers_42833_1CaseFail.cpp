//! ��� ���
#include <iostream>
#include <fstream>

#include "string"
//! ���ڿ� �Լ� ���
#include "string.h"

#include "algorithm"
#include "math.h"

//! ���� ���
#include <vector>

using namespace std;


/*

https://programmers.co.kr/learn/courses/30/lessons/42883

���� ����
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��
number	k	return
1924	2	94
1231234	3	3234
4177252841	4	775841

*/
using namespace std;

//[10/21/2020 kjky12] ���� ������ �´µ� �ϳ� �߰��� if���� ���� ȿ������ �ȵǰ� �߰��߰� erase�� ���ִ� ����...
// -> �߰������� �ε����� ���� ���� �����Ͽ��� �ҵ��ϴ�

//[10/22/2020 kjky12] �ִ밪�� ���� ã������ �׽�Ʈ���̽� 1���� Ʋ��(����ó���� �ʿ��ѵ�)
string solution(string number, int k) {
	string answer = "";

	//! ������ ����!
	int nAnswerCnt = number.length() - k;
	
	while (k > 0 && nAnswerCnt > 0 )
	{
		if (number.length() == 0)
			break;

		char chMax = *max_element(number.begin(), number.end() - (nAnswerCnt - 1));

		int nFindIdx = number.find(chMax);

		k -= nFindIdx;
		nAnswerCnt -= 1;

		number.erase(0, nFindIdx + 1);

		answer += chMax;
	}

	answer += number;
	
	return answer;
}


int main()
{
	//solution("1924", 2);
	//solution("1231234", 3);
	solution("1", 1);

	return 0;
}
