#include<iostream>
#include<string>
using namespace std;
/*

���� 1, 2, 3���θ� �̷������ ������ �ִ�.
������ ������ ������ �� ���� �κ� ������ ������ ���� ������, �� ������ ���� �����̶�� �θ���.


�׷��� ���� ������ ���� �����̴�.

ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿���
���� ���� ���� ��Ÿ���� ������ ����Ѵ�.
������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.


*/
/*
substr �Լ� ���
	str.substr(pos, pos+count)
	str = "012345"
	cout<<str.substr(2,2);
	��� : "23"

int a = 1345;
string s = to_string(a);
**  int -> string

string str = "1001";
int b = stoi(str);
** string -> int
*/
bool finish;
int n;
bool ok(string s) {
	int len = s.length();
	int start = len - 1; // �� �ں��� ����?
	for (int i = 1; i <= len / 2; i++) {
		string first = s.substr(start-i, i);
		string second = s.substr(start, i);
		if (first == second) {
			return false;
		}
		--start;
	}
	return true;
}
void backtracking(int len, string s) {
	if (finish) { return; }
	if (!ok(s)) { return; }
	if (len == n) {
		finish = true;
		cout << s;
		return;
	}
	backtracking(len + 1, s + "1");
	backtracking(len + 1, s + "2");
	backtracking(len + 1, s + "3");

}

int main() {
	cin >> n;
	backtracking(1, "1");
}