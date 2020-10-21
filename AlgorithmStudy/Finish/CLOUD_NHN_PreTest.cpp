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


문제 설명
NHN행렬 문제!

행렬의 영역 문제

*/

#include <iostream>
#include <sstream>

using namespace std;

//! 좌, 우, 상, 하
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int nMaxWidth = 0;
int nMaxHeigh = 0;

//! 메트릭스가 접근햇는지 체크!
vector<vector<int>> vecMatrixCheck;


int dfs(int x, int y, int** matrix)
{
	int nCnt = 0;

	//! 영역 내부에 있어야함
	if (x >= 0 && x < nMaxWidth
		&& y >= 0 && y < nMaxHeigh)
	{
		//! 이미 체크한 영역!
		if (vecMatrixCheck[y][x] == 1)
			return nCnt;

		//! 들어왔으면 체크한 영역으로 입력!
		vecMatrixCheck[y][x] = 1;

		if (matrix[y][x] == 1)
		{
			//! 4방향 체크!
			for (size_t i = 0; i < 4; i++)
			{
				nCnt += dfs(x + dx[i], y + dy[i], matrix);
			}

			nCnt += 1;
		}
	}
	return nCnt;
}

void solution(int sizeOfMatrix, int** matrix)
{
	//! 영역의 최대 크기, 최소는 0!!
	nMaxWidth = sizeOfMatrix;
	nMaxHeigh = sizeOfMatrix;

	//! 액세스 체크를 위해 매트릭스와 동일하게 만들어줌
	vecMatrixCheck.resize(nMaxWidth, vector<int>(nMaxHeigh));

	vector<int>	vecResult;
	for (size_t i = 0; i < nMaxWidth; i++)
	{
		for (size_t j = 0; j < nMaxWidth; j++)
		{
			int n = dfs(j, i, matrix);
			if (n > 0)
				vecResult.push_back(n);
			//cout << "i/j/Cnt" << i <<"/"<< j << "/" << n << endl;
		}
	}

	cout << vecResult.size() << endl;
	sort(vecResult.begin(), vecResult.end());
	for (size_t i = 0; i < vecResult.size(); i++)
	{
		cout << vecResult[i] << " ";
	}

	cout << endl;

}

struct input_data {
	int sizeOfMatrix;
	int** matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int* [inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}