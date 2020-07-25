
//url : https://www.hackerrank.com/challenges/mini-max-sum/problem


#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;




//###################################
//###################################
//###################################

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */


void MakSubset(vector<vector<int>>& buffmain, vector<int> buffTmp, vector<int> data, int nDepth)
{
	buffmain.push_back(buffTmp);


	int nDepthTmp = nDepth;
	for (size_t i = nDepth + 1; i < data.size(); i++)
	{
		nDepthTmp = i;

		vector<int> buffTemp2 = buffTmp;
		buffTemp2.push_back(data[nDepthTmp]);

		MakSubset(buffmain, buffTemp2, data, nDepthTmp);



	}
	/*if (data.size() > nDepth + 1)
	{
		buffTemp2.push_back(data[nDepth + 1]);

		MakSubset(buffmain, buffTemp2, data, nDepth + 1);
	}*/

}



int nonDivisibleSubset(int k, vector<int> s)
{
	vector<vector<int>> buffmain;
	int nArraySize = s.size();
	for (size_t i = 0; i < nArraySize - 1; i++)
	{
		vector<int> vecTmp;

		vecTmp.push_back(s[i]);
		MakSubset(buffmain, vecTmp, s, i);



	}


	int nReturn = 0;
	int nBuffCnt = buffmain.size();
	for (size_t i = 0; i < nBuffCnt; i++)
	{
		int nBuffDetailCnt = buffmain[i].size();

		int nSum = 0;
		for (size_t j = 0; j < nBuffDetailCnt; j++)
			nSum += buffmain[i][j];

		if (nSum % k == 0 && nSum != 0)
			nReturn = max(nBuffDetailCnt, nReturn);
	}


	return nReturn;
}

int main()
{
	ofstream fout("OUTPUT_PATH");

	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);

	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	int n = stoi(first_multiple_input[0]);

	int k = stoi(first_multiple_input[1]);

	string s_temp_temp;
	getline(cin, s_temp_temp);

	vector<string> s_temp = split(rtrim(s_temp_temp));

	vector<int> s(n);

	for (int i = 0; i < n; i++) {
		int s_item = stoi(s_temp[i]);

		s[i] = s_item;
	}

	int result = nonDivisibleSubset(k, s);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
