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
string solution(string number, int k) {
	string answer = "";

	//! ������ ����!
	int nAnswerCnt = number.length() - k;

	while (true)
	{
		int nSize = number.length();
		for (size_t i = 0; i < nSize - 1; i++)
		{

			for (size_t j = i + 1; j < nSize; j++)
			{
				if (number[i] < number[j])
				{
					int nDelCnt = j - i;
					if (number.length() - nDelCnt < nAnswerCnt)
						break;

					number.erase(i, nDelCnt);
					k -= (j - i);
					break;
				}

			}

			if (number.length() != nSize)
			{
				cout << number << endl;

				//nSize = number.length();
				break;
			}

		}

		if (number.length() == nAnswerCnt)
			break;
	}

	answer = number;
	return answer;
}


int main()
{
	//solution("1924", 2);
	//solution("1231234", 3);
	solution("4177252841", 4);

	return 0;
}
