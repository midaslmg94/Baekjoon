#include<iostream>
#include<string>
using namespace std;
/*

숫자 1, 2, 3으로만 이루어지는 수열이 있다.
임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 그 수열을 나쁜 수열이라고 부른다.


그렇지 않은 수열은 좋은 수열이다.

첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서
가장 작은 수를 나타내는 수열만 출력한다.
수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.


*/
/*
substr 함수 사용
	str.substr(pos, pos+count)
	str = "012345"
	cout<<str.substr(2,2);
	출력 : "23"

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
	int start = len - 1; // 맨 뒤부터 시작?
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
	
	backtracking(len, s);
	backtracking(len + 1, s + "1");  
	backtracking(len + 1, s + "2");   
	backtracking(len + 1, s + "3");
}

int main() {
	cin >> n;
	backtracking(1, "1");
}