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




*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct ST_PLAYER
{
	char chName;
	//! 0: 노말, 1: 빠른 플레이어
	bool bQuickPlayer;

	//! 술래 카운트
	int nCnt;

	ST_PLAYER(char chName = 'A', bool bQuick = 0, int nCnt = 0)
	{
		this->chName = chName;
		this->bQuickPlayer = bQuick;
		this->nCnt = nCnt;
	}
};

void SwapPlayer(ST_PLAYER	&st_playerA, ST_PLAYER	&st_playerB)
{
	ST_PLAYER	st_playerTemp;

	st_playerTemp = st_playerA;
	st_playerA = st_playerB;
	st_playerB = st_playerTemp;

 }


int MovePosition(int nCurrentPos, int nPlayerCnt, int nMove)
{
	//! 자리

	nCurrentPos += nMove;

	//! 배열의 영역이면
	if (nCurrentPos >= 0 && nCurrentPos < nPlayerCnt)
		return nCurrentPos;
	else
	{
		if (nCurrentPos < 0)
		{
			nCurrentPos = nPlayerCnt + nCurrentPos;
		}
		else
		{
			nCurrentPos = 0 + (nCurrentPos - nPlayerCnt);
		}
	}

	return nCurrentPos;

}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char* namesOfQuickPlayers, int numOfGames, int* numOfMovesPerGame) 
{
	//! 술래는 따로 관리!
	vector<ST_PLAYER>	vecAllPlayer(numOfAllPlayers - 1);

	for (size_t i = 0; i < numOfAllPlayers - 1; i++)
	{
		char chName = 'A' + (i + 1);
		bool bQuick = false;
		for (size_t j = 0; j < numOfQuickPlayers; j++)
			if (chName == namesOfQuickPlayers[j])
				bQuick = true;

		ST_PLAYER stPlayer(chName, bQuick, 0);
		vecAllPlayer[i] = stPlayer;
	}
	
	//! 마지막 위치에 A 플레이어 생성
	bool bQuick = false;
	for (size_t j = 0; j < numOfQuickPlayers; j++)
		if ('A' == namesOfQuickPlayers[j])
			bQuick = true;

	ST_PLAYER stAttackPlayer('A', bQuick, 1);


	SwapPlayer;

	int nGameIdx = 0;
	for (int nGame = 0; nGame < numOfGames; nGame++)
	{
		int nGameMove = numOfMovesPerGame[nGame];

		nGameIdx = MovePosition(nGameIdx, numOfAllPlayers - 1, nGameMove);


		//! 둘다 빠른 플레이어
		if (vecAllPlayer[nGameIdx].bQuickPlayer == true && stAttackPlayer.bQuickPlayer == true) // 둘다 빠르면 그냥 앉은 얘가 술래로 변경!
		{
			vecAllPlayer[nGameIdx].nCnt++;
			SwapPlayer(vecAllPlayer[nGameIdx], stAttackPlayer);
		}
		else if (vecAllPlayer[nGameIdx].bQuickPlayer == true) //! 앉아 있는 얘가 빠른 플레이어면 술래를 다신한번!!
		{
			stAttackPlayer.nCnt++;
		}
		else //! 그게 아니면 그냥 앉은 얘가 술래로 변경!
		{
			vecAllPlayer[nGameIdx].nCnt++;
			SwapPlayer(vecAllPlayer[nGameIdx], stAttackPlayer);

		}
	}

	for (size_t i = 0; i < numOfAllPlayers - 1; i++)
	{
		cout << vecAllPlayer[i].chName << " " << vecAllPlayer[i].nCnt << endl;
	}

	cout << stAttackPlayer.chName << " " << stAttackPlayer.nCnt << endl;

}

struct input_data {
	int numOfAllPlayers;
	int numOfQuickPlayers;
	char* namesOfQuickPlayers;
	int numOfGames;
	int* numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfAllPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfQuickPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
	for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
		iss >> inputData.namesOfQuickPlayers[i];
	}

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfGames;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.numOfMovesPerGame = new int[inputData.numOfGames];
	for (int i = 0; i < inputData.numOfGames; i++) {
		iss >> inputData.numOfMovesPerGame[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
	return 0;
}