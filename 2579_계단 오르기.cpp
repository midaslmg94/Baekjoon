#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>map;
vector<int>visit;

bool canGo() {
	// 3�� �������� ������ ���

}

int main() {
	int n;
	cin >> n;
	map.resize(n+1);
	for (int i = n-1; i >= 0; i--) {
		cin >> map[i];
	}
	map[n] = -1;
	int sum = map[0];
	visit.push_back(0);
	int next;
	for (int i = 1; i < n; i++) {





		if (map[i] > map[i + 1]) { // 1ĭ �̵� : ���� 3ĭ �̵��ϴ� �� ����
			visit.push_back(i);
			sum += map[i];
		}
		else { // 2ĭ �̵�
			sum += map[i + 1];
			++i;
		}
	}

	cout << sum;
}