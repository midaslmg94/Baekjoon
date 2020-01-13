#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int L, C;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> L >> C;
	vector<char>consonant; // 자음
	vector<char>vowel; // 모음
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') {
			consonant.push_back(tmp);
		}
		else { vowel.push_back(tmp); }
	}
	sort(consonant.begin(), consonant.end());
	sort(vowel.begin(), vowel.end());
	
	for (int i = 1; i < L-1; i++) {

	}
}