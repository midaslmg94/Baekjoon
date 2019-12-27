#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
string str;
stack<char>st;
stack<char>tmp; //  �ùٸ� ��ȣ���� Ȯ���ϱ� ���� �ӽ� ����
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
	// �ùٸ� ��ȣ���� Ȯ��
	if (!is_correct()) {
		cout << "�߸��� ��ȣ";
		return 0;
	}
	else {
		cout << "�ùٸ� ��ȣ";
	}
	// () --> 2, [] --> 3���� ġȯ
}