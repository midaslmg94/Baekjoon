#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX 8
using namespace std;
int n;
int m;
int arr[MAX][MAX];

int check_left(int y, int x) {
	int res = 0;
	for (int j = x-1; j>=0; j--) {
		if (arr[y][j] == 6) {
			break;
		}
		if (arr[y][j] == 0) {
			res++;
		}
	}
	return res;
}
int check_right(int y, int x) {
	int res = 0;
	for (int j = x + 1; j < m; j++) {
		if (arr[y][j] == 6) {
			break;
		}
		if (arr[y][j] == 0) {
			res++;
		}
	}
	return res;
}
int check_up(int y, int x) {
	int res = 0;
	for (int i = y-1; i >= 0; i--) {
		if (arr[i][x] == 6) {
			break;
		}
		if (arr[i][x] == 0) {
			res++;
		}
	}
	return res;
}
int check_down(int y, int x) {
	int res = 0;
	for (int i = y + 1; i < n; i++) {
		if (arr[i][x] == 6) {
			break;
		}
		if (arr[i][x] == 0) {
			res++;
		}
	}
	return res;
}

// °¨½Ã ¹æÇâÀ¸·Î º½
void left(int y, int x) {
	for (int j = x - 1; j >= 0; j--) {
		if (arr[y][j] == 6) {
			break;
		}
		if (arr[y][j] == 0) {
			arr[y][j] = -1;
		}
	}
}
void right(int y, int x) {
	for (int j = x + 1; j < m; j++) {
		if (arr[y][j] == 6) {
			break;
		}
		if (arr[y][j] == 0) {
			arr[y][j] = -1;
		}
	}
}
void up(int y, int x) {
	for (int i = y - 1; i >= 0; i--) {
		if (arr[i][x] == 6) {
			break;
		}
		if (arr[i][x] == 0) {
			arr[i][x] = -1;
		}
	}
}
void down(int y, int x) {
	for (int i = y + 1; i < n; i++) {
		if (arr[i][x] == 6) {
			break;
		}
		if (arr[i][x] == 0) {
			arr[i][x] = -1;
		}
	}
}

void sol(int y, int x, int cam) {
	if (cam == 5) {
		left(y, x); right(y, x); up(y, x); down(y, x);
	}
	else if (cam == 1) {
		int max_cam1 = 0; 		
		int c1 = check_up(y, x);// »ó
		int c2 = check_down(y, x);//ÇÏ
		int c3 = check_left(y, x);//ÁÂ
		int c4 = check_right(y, x);//¿ì
		max_cam1 = max(c1,max(c2,max(c3, c4)));

		if (max_cam1 == c1) up(y, x);
		else if (max_cam1 == c2)down(y, x);
		else if (max_cam1 == c3)left(y, x);
		else right(y, x);
	}

	else if (cam == 2) {
		int max_cam2 = 0;
		
		int c1 = check_up(y, x) + check_down(y, x);// »óÇÏ
		int c2 = check_left(y, x) + check_right(y, x);// ÁÂ¿ì
		max_cam2 = max(c1, c2);
		if (max_cam2 == c1) {
			up(y, x);
			down(y, x);
		}
		else {
			left(y, x);
			right(y, x);
		}
	}
	else if (cam == 3) {
		int max_cam3 = 0;
		int c1 = check_up(y, x) + check_left(y, x);// »óÁÂ
		int c2 = check_up(y, x) + check_right(y, x);// »ó¿ì
		int c3 = check_down(y, x) + check_left(y, x);// ÇÏÁÂ
		int c4 = check_down(y, x) + check_right(y, x);// ÇÏ¿ì
		max_cam3 = max(c1, max(c2, max(c3, c4)));
		if (max_cam3 == c1) {
			up(y, x); left(y, x);
		}
		else if (max_cam3 == c2) {
			up(y, x); right(y, x);
		}
		else if (max_cam3 == c3) {
			down(y, x); left(y, x);
		}
		else {
			down(y, x); right(y, x);
		}
	}

	else if (cam == 4) {
		int max_cam4 = 0;
		int c1 = check_up(y, x) + check_left(y, x) + check_right(y, x);// »óÁÂ¿ì
		int c2 = check_up(y, x) + check_left(y, x) + check_down(y, x);// »óÁÂÇÏ
		int c3 = check_left(y, x) + check_down(y, x) + check_right(y, x);// ÇÏÁÂ¿ì
		int c4 = check_up(y, x) + check_down(y, x) + check_right(y, x);// »óÇÏ¿ì
		max_cam4 = max(c1, max(c2, max(c3, c4)));

		if (max_cam4 == c1) {
			up(y, x); left(y, x); right(y, x);
		}
		else if (max_cam4 == c2) {
			up(y, x); down(y, x); left(y, x);
		}
		else if (max_cam4 == c3) {
			down(y, x); left(y, x); right(y, x);
		}
		else {
			up(y, x); down(y, x); right(y, x);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				sol(i, j, arr[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}


	// 0ÀÇ °³¼ö¸¦ °è»ê 
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				res++;
		}
	}
	cout << res;
}