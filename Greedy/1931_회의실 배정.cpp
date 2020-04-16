#include<iostream>
#include<queue>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	int start, end;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //우선순위 큐를 오름차순으로 정렬
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		q.push(make_pair(end, start)); // first : 끝나는 시간, second : 시작 시간
	}
	int tmp_start = 0;
	int tmp_end = 0;
	 
	tmp_start = q.top().second;
	tmp_end = q.top().first;
	int cnt = 1;
	q.pop();
	while (!q.empty()) {
		if (q.top().second >= tmp_end) {
			tmp_start = q.top().second;
			tmp_end = q.top().first;
			cout << "시작시간 : " << tmp_start << " 종료시간 : " << tmp_end << "\n";
			cnt++;
		}
		q.pop();
	}
	cout << cnt;
}