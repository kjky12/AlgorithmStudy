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

https://programmers.co.kr/learn/courses/30/lessons/68644

���� ����
���� �迭 numbers�� �־����ϴ�. numbers���� ���� �ٸ� �ε����� �ִ� �� ���� ���� �̾� ���ؼ� ���� �� �ִ� ��� ���� �迭�� ������������ ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
numbers�� ���̴� 2 �̻� 100 �����Դϴ�.
numbers�� ��� ���� 0 �̻� 100 �����Դϴ�.
����� ��
numbers	result
[2,1,3,4,1]	[2,3,4,5,6,7]
[5,0,2,7]	[2,5,7,9,12]
����� �� ����
����� �� #1

2 = 1 + 1 �Դϴ�. (1�� numbers�� �� �� �ֽ��ϴ�.)
3 = 2 + 1 �Դϴ�.
4 = 1 + 3 �Դϴ�.
5 = 1 + 4 = 2 + 3 �Դϴ�.
6 = 2 + 4 �Դϴ�.
7 = 3 + 4 �Դϴ�.
���� [2,3,4,5,6,7] �� return �ؾ� �մϴ�.
����� �� #2

2 = 0 + 2 �Դϴ�.
5 = 5 + 0 �Դϴ�.
7 = 0 + 7 = 5 + 2 �Դϴ�.
9 = 2 + 7 �Դϴ�.
12 = 5 + 7 �Դϴ�.
���� [2,5,7,9,12] �� return �ؾ� �մϴ�.

*/
using namespace std;

vector<int> solution(vector<int> numbers) 
{
	sort(numbers.begin(), numbers.end());
	//numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

	vector<int> answer;
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		for (size_t j = i + 1; j < numbers.size(); j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());



	return answer;
}

int main()
{
	int aT[5] = { 2,1,3,4,1 };
	vector<int>	vecT1(aT, aT + 5);

	solution(vecT1);

	return 0;
}
