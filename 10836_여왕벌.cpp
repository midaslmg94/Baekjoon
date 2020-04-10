#include<bits/stdc++.h>
#define endl "\n"
#define MAX 700
using namespace std;
int n, m;
int zero = 0;
int one = 0;
int two = 0;
long long arr[MAX][MAX];
long long backup[MAX][MAX];
void grow() {
	int y = n - 1;
	int x = 0;
	for (int i = 0; i < zero; i++) {
		if (y > 0) {
			arr[y][x] += 0;
			y--;
		}
		else {
			arr[y][x] += 0;
			x++;
		}
	}
	for (int i = 0; i < one; i++) {
		if (y > 0) {
			arr[y][x] += 1;
			y--;
		}
		else {
			arr[y][x] += 1;
			x++;
		}
	}
	for (int i = 0; i < two; i++) {
		if (y > 0) {
			arr[y][x] += 2;
			y--;
		}
		else {
			arr[y][x] += 2;
			x++;
		}
	}
}
void grow_next() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			long long growth = -1;
			growth = max(growth, max(max(arr[i - 1][j - 1],arr[i-1][j]),arr[i][j-1]));		
			arr[i][j] = growth;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m; // 문제의 입력과 반대로 했다. n:배열의 크기, m:날짜
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 1;
		}
	}
	for (int i = 0; i < m; i++) {  // 최대 100만
		cin >> zero >> one >> two;
		grow(); // 규칙 1 
	}
	grow_next();// 규칙 2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}