#include<iostream>
#include<string>
using namespace std;
string room[100];
/*2칸이상 . 으로 되어있어야 누울 수 있음*/
int maxRow(int n) { //가로
	int max = 0;
	for (int i = 0; i < n; i++) {
		int space = 0;
		for (int j = 0; j < n; j++) {
			if (room[i].at(j) == '.') {  
				space++;
				if (j == n - 1) {
					if (space >= 2) {
						max++;
					}
				}
			}
			else {
				if (space >= 2) { //누울 공간 존재
					max++;
				}
				space = 0;
			}
		}
	}
	return max;
}
int maxCol(int n) { //세로
	int max = 0;
	for (int i = 0; i < n; i++) {
		int space = 0;
		for (int j = 0; j < n; j++) {
			if (room[j].at(i) == '.') {
				space++;
				if (j == n - 1) {
					if (space >= 2) {
						max++;
					}
				}
			}
			else {
				if (space >= 2) {
					max++;
				}
				space = 0;
			}
		}
	}

	return max;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
	}
	cout << maxRow(n) << " " << maxCol(n);
}