//! 출력 사용
#include <iostream>
#include <fstream>

#include "string"
//! 문자열 함수 사용
#include "string.h"

#include "algorithm"
#include "math.h"

//! 백터 사용
#include <vector>

using namespace std;


/*

https://programmers.co.kr/learn/courses/30/lessons/42885

문제 설명
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

제한사항
무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.

입출력 예
people	limit	return
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3


*/

//! 이건 최소한이 아니고 낮은것 부터 쭉 따라가는거네....
//int solution(vector<int> people, int limit) {
//	int answer = 0;
//
//	//! 0은 탑승완료, 1은 탑승 미완료 -> 소팅된 기준으로 한다.
//	vector<bool> bCheck(people.size(), 0);
//	sort(people.begin(), people.end()); //! 오름차순으로 정렬
//
//	
//	
//	while (true)
//	{
//		//! 구명 보트에는 최대 2명, limit무게까지만
//		int nBoatPeople = 0;
//		int nBoatWeight = 0;
//
//		for (size_t i = 0; i < people.size(); i++)
//		{
//			if (bCheck[i]) //! 이미 탑승한 구조자
//				continue;
//
//			if (nBoatWeight + people[i] <= limit)
//			{
//				nBoatWeight += people[i];
//				nBoatPeople++;
//
//				bCheck[i] = 1;
//			}
//
//
//			//! 최대 2명 or 제한 무게가 넘으면 나가기
//			if (nBoatPeople >= 2 || nBoatWeight >= limit)
//				break;
//		}
//
//
//		if (nBoatPeople == 0)
//		{
//			break;
//		}
//
//		answer++;
//	}
//
//
//
//
//	return answer;
//}


int solution(vector<int> people, int limit) {
	int answer = 0;

	//! 0은 탑승완료, 1은 탑승 미완료 -> 소팅된 기준으로 한다.
	vector<bool> bCheck(people.size(), 0);
	sort(people.begin(), people.end()); //! 오름차순으로 정렬


	int nBackIDx = people.size() - 1;
	//! 가벼운 사람부터 출발
	for (size_t i = 0; i < people.size(); i++)
	{
		//! 뒤에서부터 찾다가 해결됬을수 있음
		if (bCheck[i] == 1)
			continue;
		
		//! 구명 보트에는 최대 2명 탈출하면 true변경
		bool bFind = false;

		//! 내 두배보다 크면 뒤쪽은 확인할 필요가 없음
		if (people[i] * 2 <= limit)
		{
			//! 무거운사람부터 -> 가벼운 사람 시작 한 전까지만!!
			for (size_t j = nBackIDx; j >= i + 1; j--)
			{
				if (bCheck[j] == 1)
					continue;


				//! 뒤에부터 찾았기 때문에 뒤에부터 더해오다 제한 값보다 작으면 바로 탈출!!
				if (people[i] + people[j] <= limit)
				{
					bFind = true;
					bCheck[i] = 1;
					bCheck[j] = 1;
					answer++;

					//! 오름차순이니까 한번 찾아지면 더 큰수는 볼 필요가 없음
					nBackIDx = j;
					//! 2명이 맥시멈이니까 바로 탈출해야됌
					break;
				}

			}
		}
		
		//! 못찾으면 혼자 탈출!!
		if (bFind == false)
		{
			bCheck[i] = 1;
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<int> people;
	const int nTmp1 = 4;
	int naTmp1[nTmp1] = { 70, 50, 80, 50 };
	people.assign(naTmp1, naTmp1 + nTmp1);

	solution(people, 100);

	return 0;
}
