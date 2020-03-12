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
	priority_queue<int, vector<int>,greater<int>>pq;	
	int tmp;
	for (int i = 0; i < n * n; i++) {
		cin >> tmp;
		if (pq.size() < n) {
			pq.push(tmp);
		}
		else {			
			if (pq.top() < tmp) { // 더 큰 수가 들어오면
				pq.pop(); 
				pq.push(tmp);
			}
			else {
				continue;
			}
		}
		cout << pq.top() << endl; // 젤 작은거
	}
	//while (!pq.empty()) {
	//	cout << pq.top()<<endl;
	//	pq.pop();
	//}
	
	return 0;
}