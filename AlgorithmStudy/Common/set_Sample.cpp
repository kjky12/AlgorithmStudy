#include <iostream>
#include <set>
using namespace std;
int main() {
	//int �ڷ����� �����ϴ� �������� ����Ʈ�� ����
	set<int> s;
	//����(5) ����
	s.insert(5);
	//6���� ������ ���Ҹ� ã�� �ִٸ� �ش� ������ �ּҰ�,  ���ٸ� s.end()����
	if (s.find(6) != s.end())
		printf("�����մϴ�.\n");
	else
		printf("�����ϴ�.\n");
	//����� ������ ���� ����
	printf("%d\n", s.size());
	//��� ���� ����
	s.clear();
	//�ش� �ּ��� ���� ����
	//2��° ���� ����
	s.erase(++s.begin());
	return 0;
}
