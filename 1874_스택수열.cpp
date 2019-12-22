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
	// ó�� ���ϴ� ���� ó��
	int num = 1;
	for (int i = 0; i < q.front(); i++) {
		s.push(num);
		num++;
		result += '+';
	}
	result += '-';
	q.pop(); s.pop();

	// ������ ó���������� Ȯ��
	bool impossible = false;
	while (true) {
		if (q.empty()) { // �Է¹��� ������ �����
			break;
		}
		int cur = q.front(); 
		// ������ ����� ��� : push
		if (s.empty() || cur > s.top()) {
			s.push(num);
			num++;
			result += '+';
		}
		// ���� ��� pop
		else if (cur == s.top()) {
			result += '-';
			s.pop();
			q.pop();
		}
		// �Ұ����� ���
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