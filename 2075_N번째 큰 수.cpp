#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 1500
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	priority_queue<int, vector<int>,greater<int>>pq; // 최소힙으로 구현 

	int tmp;
	for (int i = 0; i < n * n; i++) {
		cin >> tmp;
		if (pq.size() < n) { // 입력 값 중 크기가 큰 N개의 값 저장. 최소힙이므로 N번째 큰 값이 top에 위치함
			pq.push(tmp);
		}
		else {			
			if (pq.top() < tmp) { // pq에 있는 값 중 가장 작은 값 보다 더 큰 수가 들어오면, pop후 push
				pq.pop(); 
				pq.push(tmp);
			}
			else {
				continue;
			}
		}
	}
	cout << pq.top() << endl; // 젤 작은거
	
	return 0;
}