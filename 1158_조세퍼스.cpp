#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	deque<int> dq;
	deque<int>::iterator iter;
	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}
	iter = dq.begin();
	cout << '<';
	while (!dq.empty()) {
		for (int i = 0; i < k - 1; i++) { // k��° ����� �����ϱ� ����. ���� �ε����� 0�̹Ƿ�  i�� ������ k-1�̸�
			if (iter == dq.end() - 1) {// �������� ����
				iter = dq.begin();

				continue;
			}
			else {
				iter++;
			}
		}
		cout << *iter;
		if (iter == dq.end() - 1) { // ���� �� ������ ���ҿ� ��ġ. �� ������ ���Ҹ� �����ϸ� ���� ������ ��ġ�� ��ȯ�ǹǷ� ������ ����.
			iter = dq.begin();
			dq.pop_back(); // ������ ���Ҵ� �̷��� ����
		}
		else {
			iter = dq.erase(iter); // erase�� ���ϰ��� �޾���� �Ѵ�. erase�Լ��� ���ϰ��� ���� ���� ������ �ִ� ������ iterator�̱� �����̴�
		}
		if (dq.size() > 0) { // ���� ��ǥ ����
			cout << ", ";
		}
	}
	cout << '>';
}