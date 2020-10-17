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

https://programmers.co.kr/learn/courses/30/lessons/42860

���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵�
���� ��� �Ʒ��� ������� JAZ�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.
����� ��
name	return
JEROEN	56
JAN	23

*/

char chCurrentPos = 'A';

//! �¿� ����Ű������ �������� ���� ���� ī��Ʈ
int GetLeftRightMoveCnt(char chTarget)
{
	int nStep = abs(chCurrentPos - chTarget);
	return nStep;
}


//! ���������� �پ �������� ���� ���� ī��Ʈ
int GetRightAndMoveCnt(char chTarget)
{
	int nStep = 0;
	if (chCurrentPos != 'Z')
		nStep++;

	nStep += abs('Z' - chTarget);

	return nStep;
}

//! �������� �پ �������� ���� ���� ī��Ʈ
int GetLeftAndMoveCnt(char chTarget)
{
	int nStep = 0;
	if (chCurrentPos != 'A')
		nStep++;

	nStep += abs('A' - chTarget);

	return nStep;
}


int solution(string name) {
	
	chCurrentPos = 'A';
	int answer = 0;

	for (size_t i = 0; i < name.length(); i++)
	{
		int nMove1 = GetLeftRightMoveCnt(name[i]);
		int nMove2 = GetRightAndMoveCnt(name[i]);
		//int nMove3 = GetLeftAndMoveCnt(name[i]);

		int Min = min(nMove1, nMove2);
		//Min = min(Min, nMove3);

		answer += Min;
		chCurrentPos = name[i];
	}

	return answer;
}

int main()
{
	
	solution("JAZ");
	solution("JEROEN");
	solution("JAN");

	return 0;
}
