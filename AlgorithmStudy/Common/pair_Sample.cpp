#include <iostream>
#include <utility>
using namespace std;
int main() {
	//int, int �ڷ����� �����ϴ� ���� ����
	pair<int, int> p;
	//(4, 5)�� p�� ����
	p = make_pair(4, 5);
	//c++11���� ����
	p = { 4, 5 };
	return 0;
}
