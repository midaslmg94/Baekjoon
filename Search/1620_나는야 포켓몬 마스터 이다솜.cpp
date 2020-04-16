#include<iostream>
#include<string>
#include<map>
#include <unordered_map>
#define endl "\n"
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	unordered_map<string, int>dic;
	unordered_map<int, string>dic_2;
	string poki;
	for (int i = 0; i < n; i++) {
		cin >> poki;
		dic.insert({ poki,i+1});
		dic_2.insert({ i + 1,poki });
	}
	for (int i = 0; i < m; i++) {
		string quiz;
		cin >> quiz;
		int num = atoi(quiz.c_str()); // 입력된 문자가 숫자인지 확인	
		if (num!=0) { // 숫자라면 n번째 포켓몬의 이름을 찾음
			num = stoi(quiz);
			unordered_map<int, string>::iterator idx = dic_2.find(num);
			cout << idx->second << endl;
		}
		else { // 문자라면 해당 포켓몬이 몇번째인지 찾음
			unordered_map<string, int>::iterator idx = dic.find(quiz);
			cout << idx->second<<endl;			
		}

	}

}