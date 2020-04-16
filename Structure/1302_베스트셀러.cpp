#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	map<string, int>booklist;
	map<string, int>::iterator it;
	string book;
	for (int i = 0; i < n; i++) {
		cin >> book;
		if (booklist.count(book)) { // 이게 있으면 추가
			booklist[book] += 1;
		}
		else {
			booklist[book] = 1;
		}
	}

	int max_num = -1;
	string bestseller = "";
	for (it = booklist.begin(); it != booklist.end(); it++) {
		if (max_num < it->second) {
			bestseller = it->first;
			max_num = it->second;
		}		
	}
	cout << bestseller;
}
