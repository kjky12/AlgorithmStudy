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
https://programmers.co.kr/learn/courses/30/lessons/42842
*
문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

carpet.png

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
입출력 예
brown	yellow	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
출처

※ 공지 - 2020년 2월 3일 테스트케이스가 추가되었습니다.
※ 공지 - 2020년 5월 11일 웹접근성을 고려하여 빨간색을 노란색으로 수정하였습니다.



*/

////////////////////////////////
//! 나머지를 계산할때 반대로 해서 오류를 겪엇다.
////////////////////////////////



int main()
{
	int brown = 10;
	int yellow = 2;
	
	//int brown = 8;
	//int yellow = 1;
	//int brown = 24;
	//int yellow = 24;

	/*
	이 문제는 가로의 길이가 세로보다 크거나 같아야한다.
	BROWON = x*2 + (y-2) *2
	YELLOW = (x - 2)*2 + (y-2) *2
	두 가지가 성립되어야하며

	그렇게 x축, 색상 개수를 입력하고 모든 y값을 추출하는 for문을 만들어야한다.

	*/ 

	vector<int> answer;

	int nMaxWidth = (brown - 2) / 2; //! 최소 한칸은 있다는 가정

	for (int i = nMaxWidth; i >= 0; i--)
	{
		bool bFlag = false;
		int nHeight = 1;
		while (true)
		{
			int nBrownCnt = (i * 2) + (nHeight * 2);

			int nYelloCnt = (i - 2) * (nHeight);


			//! 개수가 맞으면 플래그를 바꾼다
			if (nBrownCnt == brown && nYelloCnt == yellow)
			{
				bFlag = true;
				break;
			}

			if (nBrownCnt > brown || nYelloCnt > yellow)
				break;

			nHeight++;
		}

		if (bFlag == true)
		{
			answer.push_back(i);
			answer.push_back(nHeight + 2);
			break;
		}

	}




	return 0;
}

