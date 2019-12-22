#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
using namespace std;

stack<int>s;
queue<int>q;
string result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	}
	// 처음 원하는 숫자 처리
	int num = 1;
	for (int i = 0; i < q.front(); i++) {
		s.push(num);
		num++;
		result += '+';
	}
	result += '-';
	q.pop(); s.pop();

	// 수열을 처리가능한지 확인
	bool impossible = false;
	while (true) {
		if (q.empty()) { // 입력받은 수열이 비었음
			break;
		}
		int cur = q.front(); 
		// 스택이 비었을 경우 : push
		if (s.empty() || cur > s.top()) {
			s.push(num);
			num++;
			result += '+';
		}
		// 같을 경우 pop
		else if (cur == s.top()) {
			result += '-';
			s.pop();
			q.pop();
		}
		// 불가능한 경우
		else if (cur < s.top()) {
			impossible = true;
			break;
		}
	}

	if (impossible) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
}