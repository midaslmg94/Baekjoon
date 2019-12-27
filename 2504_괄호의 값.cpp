#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
string str;
stack<char>st;
stack<char>tmp; //  올바른 괄호인지 확인하기 위한 임시 스택
bool is_correct() {
	tmp.push(str[0]);
	for (int i = 1; i < str.size(); i++) {
		if (tmp.top() == '(') {
			if (str[i] == ')') {
				tmp.pop();
			}
			else {
				tmp.push(str[i]);
			}
		}
		else if (tmp.top() == '[') {
			if (str[i] == ']') {
				tmp.pop();
			}
			else {
				tmp.push(str[i]);
			}
		}
	}
	return tmp.empty();
}
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		st.push(str[i]);
	}
	// 올바른 괄호인지 확인
	if (!is_correct()) {
		cout << "잘못된 괄호";
		return 0;
	}
	else {
		cout << "올바른 괄호";
	}
	// () --> 2, [] --> 3으로 치환
}