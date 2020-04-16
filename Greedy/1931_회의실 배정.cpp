#include<iostream>
#include<queue>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	int start, end;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //�켱���� ť�� ������������ ����
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		q.push(make_pair(end, start)); // first : ������ �ð�, second : ���� �ð�
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
			cout << "���۽ð� : " << tmp_start << " ����ð� : " << tmp_end << "\n";
			cnt++;
		}
		q.pop();
	}
	cout << cnt;
}