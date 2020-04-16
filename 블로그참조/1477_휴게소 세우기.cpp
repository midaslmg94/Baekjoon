#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
using namespace std;
int n, m, l;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> l;
	vector<int>store;
	int pos;
	store.push_back(0); // 거리의 시작지점
	for (int i = 0; i < n; i++) {
		cin >> pos;
		store.push_back(pos);
	}
	store.push_back(l); // 거리의 끝지점
	sort(store.begin(), store.end());	

	int left = 1;
	int right = l - 1;	
	while (left <= right) {
		int mid = (left + right) / 2; // 기존 편의점에서 새롭게 세울 편의점 사이의 거리 
		int new_store = 0;
		for (int i = 1; i < store.size(); i++) {
			int dist = store[i] - store[i - 1]; 
			new_store += (dist / mid); // 두 편의점 사이에 세울 수 있는 편의점의 개수
			if (dist % mid == 0) { // 나누어 떨어지는 경우 : 편의점이 겹쳐서 세워지므로 1을 뺌
				new_store--;
			}
		}
		
		if (new_store > m) { // 세워야할 편의점 보다 더 많이 생김 -> 간격을 늘림
			left = mid + 1;
		}
		else { // 세워야할 편의점 보다 더 적게 생김 -> 간격을 줄임
			right = mid - 1;
		}		
	}
	
	cout << left;
	return 0;
}