#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
string str;
stack<char>st;
stack<char>tmp; //  �ùٸ� ��ȣ���� Ȯ���ϱ� ���� �ӽ� ����
bool isCorrect() {
	tmp.push(str[0]);
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ')') { // �ݴ� ��ȣ��� ������ ������� �ʰ�, top���� ������ �׿� �´� ���� ��ȣ���� �־�� ��
			if (tmp.empty()) {
				return false;
			}
			if (tmp.top() == '[' ) {// �߸��� ��ȣ�� ����
				return false;
			}
			else if (tmp.top() == '(') {  // ��ȣ �� ��ġ --> pop
				tmp.pop(); 
			}
			else { tmp.push(str[i]); }
		}
		else if (str[i] == ']') {
			if (tmp.empty()) {
				return false;
			}
			if (tmp.top() == '(') {// �߸��� ��ȣ�� ����
				return false;
			}
			else if (tmp.top() == '[') {// ��ȣ �� ��ġ --> pop
				tmp.pop(); 
			} 
			else { tmp.push(str[i]); }
		}
		else if (str[i] == '(' || str[i] == '['){ // ���� ��ȣ�� �׳� ���ÿ� Ǫ��
			tmp.push(str[i]);
		}
	}
	return true;
}





int main() {
	cin >> str;
	// �ùٸ� ��ȣ���� Ȯ��
	if (!isCorrect() || !tmp.empty()) {
		cout << "0";
		return 0;
	}
	// �ùٸ� ��ȣ��� () --> 2, [] --> 3���� ġȯ
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (st.top() == '(') { // ( )�̹Ƿ� 2�� ġȯ
				st.pop();
				st.push('2');
			}
			else {
				st.push(str[i]);
			}
		}
		else if (str[i] == ']') {
			if (st.top() == '[') { // [ ]�̹Ƿ� 3���� ġȯ
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
	
	// ����, ����

}