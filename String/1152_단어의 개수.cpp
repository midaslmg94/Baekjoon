#include<iostream>
#include<string>
using namespace std;
/*
	아스키 코드로 구분. 공백의 아스키 코드 : 32
	단, 문장의 맨 앞 또는 맨 뒤에 공백이 오는 경우는 count하지 않음
	공백 1개만 들어오는 경우 : 결과값은 0이 나와야함
*/
int main() {
	string str;
	getline(cin, str); // 공백을 포함하여 문자열을 입력 받음
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
	if (str.size() == 1 && str[0] == ' ') { // 공백만 입력받는 경우를 제외
		cnt = 0;
	}
	cout << cnt;
}