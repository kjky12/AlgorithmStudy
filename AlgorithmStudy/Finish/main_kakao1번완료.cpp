//! ��� ���
#include <iostream>

//! ���ڿ� ���
#include "string"
//! ���ڿ� �Լ� ���
#include "string.h"

#include "algorithm"

//! ���� ���
#include <vector>

using namespace std;

/*

https://www.welcomekakao.com/tryouts/16422/challenges

*/



char TransId(char chT)
{
	if (chT >= 'A' && chT <= 'Z')
		chT = chT - ('A' - 'a');

	return chT;
}

void RemoveChar(string& strInput, string strFilter)
{
	for (size_t i = 0; i < strFilter.size(); i++)
	{
		strInput.erase(remove(strInput.begin(), strInput.end(), strFilter[i]), strInput.end());
	}
}

void DeleteSideChar(string& strInput, string strSide)
{
	if (strInput.size() == 0)
		return;

	int nFind = strInput.find(".");
	if (nFind == 0)
		strInput.erase(0, 1);

	if (strInput.size() == 0)
		return;

	nFind = strInput.rfind(".");
	if (nFind == strInput.size() - 1)
		strInput.erase(nFind, 1);
}

//no	new_id							result
//��1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
//��2	"z-+.^."						"z--"
//��3	"=.="							"aaa"
//��4	"123_.def"						"123_.def"
//��5	"abcdefghijklmn.p"				"abcdefghijklmn"


int main()
{
	vector<string> phone_book;

	string new_id = "123_.def";
	string answer = "";

	//! 1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
	transform(new_id.begin(), new_id.end(), new_id.begin(), TransId);

	//! 2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
	string strFilterT = "";
	for (size_t i = 33; i < 126; i++)
	{
		if (i == '-' || i == '_' || i == '.' 
			|| (i >= 'a' && i <= 'z')
			|| (i >= '0' && i <= '9'))
			continue;
		strFilterT += char(i);
	}

	//strFilter = "-_.~!@#$%^&*()=+[{]}:?,<>";
	string strFilter = "~!@#$%^&*()=+[{]}:?,<> ";
	RemoveChar(new_id, strFilter);
	

	//! 3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
	string strFilter2 = "..";
	int nFind = new_id.find(strFilter2);
	while (nFind >= 0)
	{
		new_id.replace(nFind, strFilter2.size(), ".");
		nFind = new_id.find("..");
	}

	//! 4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
	DeleteSideChar(new_id, ".");

	//! 5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
	if (new_id.size() == 0)
		new_id = "a";
	

	//! 6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
	if (new_id.size() >= 16)
		new_id.erase(new_id.begin() + 15, new_id.end());
	
	//! ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
	DeleteSideChar(new_id, ".");
	


	//! 7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
	while (new_id.size() <= 2)
		new_id += new_id[new_id.size() - 1];
	

	answer = new_id;

	return 0;
}

