#include<iostream>
#include<string>
#include<vector>
using namespace std;

void switching(vector<string>& ch) {
	int i = 0;
	// kbs1 나올때까지 내리기
	while (ch[i] != "KBS1") {
		i++;
		cout << "1";
	}
	// kbs1을 맨 위로 올리기
	while (ch[0] != "KBS1") {
		ch[i - 1].swap(ch[i]);
		cout << "4";
		i--;
	}
	// kbs2가 두번째이면 종료 
	if (ch[1] == "KBS2") { return; }
	// kbs2 나올때까지 내리기
	while (ch[i] != "KBS2") {
		i++;
		cout << "1";
	}
	// kbs2를 맨 위로 올리기
	while (ch[1] != "KBS2") {
		ch[i - 1].swap(ch[i]);
		cout << "4";
		i--;
	}

}
int main() {
	int n;
	cin >> n;
	vector<string>channel;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		channel.push_back(s);
	}
	switching(channel);
	return 0;
}