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


���� ����
NHN��� ����!

����� ���� ����

*/

#include <iostream>
#include <sstream>

using namespace std;

//! ��, ��, ��, ��
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int nMaxWidth = 0;
int nMaxHeigh = 0;

//! ��Ʈ������ �����޴��� üũ!
vector<vector<int>> vecMatrixCheck;


int dfs(int x, int y, int** matrix)
{
	int nCnt = 0;

	//! ���� ���ο� �־����
	if (x >= 0 && x < nMaxWidth
		&& y >= 0 && y < nMaxHeigh)
	{
		//! �̹� üũ�� ����!
		if (vecMatrixCheck[y][x] == 1)
			return nCnt;

		//! �������� üũ�� �������� �Է�!
		vecMatrixCheck[y][x] = 1;

		if (matrix[y][x] == 1)
		{
			//! 4���� üũ!
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
	//! ������ �ִ� ũ��, �ּҴ� 0!!
	nMaxWidth = sizeOfMatrix;
	nMaxHeigh = sizeOfMatrix;

	//! �׼��� üũ�� ���� ��Ʈ������ �����ϰ� �������
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