#include<iostream>
#include<string>
using namespace std;
/*
	�ƽ�Ű �ڵ�� ����. ������ �ƽ�Ű �ڵ� : 32
	��, ������ �� �� �Ǵ� �� �ڿ� ������ ���� ���� count���� ����
	���� 1���� ������ ��� : ������� 0�� ���;���
*/
int main() {
	string str;
	getline(cin, str); // ������ �����Ͽ� ���ڿ��� �Է� ����
	int cnt = 1;	
	for (int i = 0; i < str.size(); i++) {
		if (i == 0 || i==str.size()-1) {
			if (str[i] == 32)
				continue;
		} 
		else {
			if (str[i] == 32) {
				cnt++;
			}
		}
	}
	if (str.size() == 1 && str[0] == ' ') { // ���鸸 �Է¹޴� ��츦 ����
		cnt = 0;
	}
	cout << cnt;
}