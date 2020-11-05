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

11과 011은 같은 숫자로 취급합니다.


*/
#include <iostream>
#include <sstream>

using namespace std;

int dfs(int nCurrentHeigh, int x, bool bLeftRight, vector<int>	&vecBlocks)
{
	int nStadardHeigh = 0;


	if (bLeftRight == false)
		x -= 1;
	else
		x += 1;

	if (x >= 0 && x < vecBlocks.size())
	{


		int nHeight1 = vecBlocks[x];
		int nHeight2 = 0;

		if (nCurrentHeigh < nHeight1)
		{
			nHeight2 = dfs(nCurrentHeigh, x, bLeftRight, vecBlocks);
		}

		if (nHeight2 > nHeight1)
		{

		}

		nStadardHeigh = max(nHeight1, nHeight2);
	}

	return nStadardHeigh;


}


void solution(int day, int width, int** blocks) 
{
	vector<int>	vecBlocks(width);

	int nPlusSimant = 0;
	for (size_t i = 0; i < day; i++)
	{
		for (size_t j = 0; j < width; j++)
			vecBlocks[j] += blocks[i][j];

		for (size_t j = 0; j < width; j++)
		{
			int nLTop = dfs(vecBlocks[j], j, false, vecBlocks);

			int nRRigh = dfs(vecBlocks[j], j,true, vecBlocks);

			if (vecBlocks[j] < nLTop && vecBlocks[j] < nRRigh)
			{
				int nMinHigh = min(nLTop, nRRigh);
				nPlusSimant += nMinHigh - vecBlocks[j];
				
				cout << "day:"<< i << "  x : " << j << "\t" << "PlusSimant : " << nMinHigh - vecBlocks[j] << "\t" << "BlockHi" << vecBlocks[j] << endl;

				vecBlocks[j] = nMinHigh;
			}
		}

		cout << "day:" << i << "\t"<< nPlusSimant << endl;

	}
	cout << nPlusSimant << endl;
}

struct input_data {
	int day;
	int width;
	int** blocks;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.day;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.width;

	inputData.blocks = new int* [inputData.day];
	for (int i = 0; i < inputData.day; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.blocks[i] = new int[inputData.width];
		for (int j = 0; j < inputData.width; j++) {
			iss >> inputData.blocks[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}