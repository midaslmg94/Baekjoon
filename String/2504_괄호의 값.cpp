#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
string str;
stack<char>st;
stack<char>tmp; //  올바른 괄호인지 확인하기 위한 임시 스택
bool isCorrect() {
	tmp.push(str[0]);
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ')') { // 닫는 괄호라면 스택은 비어있지 않고, top에는 무조건 그에 맞는 여는 괄호들이 있어야 함
			if (tmp.empty()) {
				return false;
			}
			if (tmp.top() == '[' ) {// 잘못된 괄호의 예시
				return false;
			}
			else if (tmp.top() == '(') {  // 괄호 쌍 일치 --> pop
				tmp.pop(); 
			}
			else { tmp.push(str[i]); }
		}
		else if (str[i] == ']') {
			if (tmp.empty()) {
				return false;
			}
			if (tmp.top() == '(') {// 잘못된 괄호의 예시
				return false;
			}
			else if (tmp.top() == '[') {// 괄호 쌍 일치 --> pop
				tmp.pop(); 
			} 
			else { tmp.push(str[i]); }
		}
		else if (str[i] == '(' || str[i] == '['){ // 여는 괄호는 그냥 스택에 푸시
			tmp.push(str[i]);
		}
	}
	return true;
}





int main() {
	cin >> str;
	// 올바른 괄호인지 확인
	if (!isCorrect() || !tmp.empty()) {
		cout << "0";
		return 0;
	}
	// 올바른 괄호라면 () --> 2, [] --> 3으로 치환
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (st.top() == '(') { // ( )이므로 2로 치환
				st.pop();
				st.push('2');
			}
			else {
				st.push(str[i]);
			}
		}
		else if (str[i] == ']') {
			if (st.top() == '[') { // [ ]이므로 3으로 치환
				st.pop();
				st.push('3');
			}
			else {
				st.push(str[i]);
			}
		}
		else {
			st.push(str[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	
	// 곱셈, 덧셈

}