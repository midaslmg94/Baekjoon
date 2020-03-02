#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string str;
int isLucky(string num) {
	int left = 0;
	int right = 0;
	int num_size = num.size() / 2;
	for (int i = 0; i < num_size; i++) {
		left += num[i] - '0';
	}
	for (int j = num_size; j < num.size(); j++) {
		right += num[j] - '0';
	}
	if (left == right) {
		return num.size();
	}
	else {
		return 0;
	}
}
int func(int start) {
	string tmp = "";
	int len = 0;
	for (int i = start; i < str.size(); i++) {
		tmp.push_back(str[i]);
	}
	cout << "tmp = " << tmp << endl;
	// tmp = 74233285 4233285 233285 33285 3285 285 85 5

	string tt="";		
	for (int i = 0; i < tmp.size(); i++) {
		tt +=tmp[i];
		if (i % 2 == 1) {// 끝나는 점의 인덱스가 홀수일때 계산
			cout << "tt = " << tt << endl;
			len = max(len,isLucky(tt));
		}	
	}
	return len;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> str;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		result = max(result,func(i));
	}
	cout << result;
}