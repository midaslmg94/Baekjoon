#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(-tmp);
	}
		
	for (int i = 0; i < n; i++) {
		cout <<-pq.top() << "\n";
		pq.pop();
	}
}