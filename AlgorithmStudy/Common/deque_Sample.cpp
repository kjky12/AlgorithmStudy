#include <iostream>
#include <deque>
using namespace std;
int main() {
	//int �ڷ����� �����ϴ� �����迭 ����
	deque<int> dq;
	//�迭 �� �տ� ����(5) �߰�
	dq.push_front(5);
	//�迭 �� �ڿ� ����(5) �߰�
	dq.push_back(5);
	//�迭 �� ���� ���� ����
	dq.pop_front();
	//�迭 �� ���� ���� ����
	dq.pop_back();
	//�������� vector�� �����ϴ�.
	return 0;
}
