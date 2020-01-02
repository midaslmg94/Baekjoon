#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>map;
vector<int>visit;

bool canGo() {
	// 3개 연속으로 가려는 경우

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





		if (map[i] > map[i + 1]) { // 1칸 이동 : 연속 3칸 이동하는 것 주의
			visit.push_back(i);
			sum += map[i];
		}
		else { // 2칸 이동
			sum += map[i + 1];
			++i;
		}
	}

	cout << sum;
}