#include <iostream>
#include <map>
using namespace std;
int main() {
	//int �ڷ����� key�� int �ڷ����� �����ͷ� �����ϴ� ��ųʸ� �ڷᱸ�� ����
	map<int, int> m;
	//(4, 5)���� ����
	m.insert(make_pair(4, 5));
	//�Ǵ�
	m[5] = 6;
	//key�� ������ ���Ҹ� pair<Ű �ڷ���, ������ �ڷ���> ���·� ������
	printf("%d\n", m.find(4)->second);
	//key�� ������ ������ ������ ������
	printf("%d\n", m.count(4));
	//����� ������ ���� ������
	printf("%d\n", m.size());
	//�ش� �ּ��� ���� ����
	m.erase(++m.begin());
	//��� ���� ����
	m.clear();
	return 0;
}
