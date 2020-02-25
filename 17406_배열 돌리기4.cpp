#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define MAX 51
using namespace std;
int n, m, k;
int r, c, s;
int map[MAX][MAX];
int backup[MAX][MAX];
int tmp_backup[MAX][MAX];

vector<pair<pair<int, int>,int>>v;
int calc() { // ���� �յ� �� �ּڰ�
	int res = 987654321;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 1; j <= m; j++) {
			cur += backup[i][j];
		}
		res = min(cur, res);
	}
	return res;
}
void ptr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << backup[i][j] << ' ';
		}
		cout << endl;
	}
}
void rotate(int R,int C,int S) {	
	memcpy(tmp_backup, backup, sizeof(tmp_backup));
	int left_y = R - S; int left_x = C - S;
	int right_y = R + S; int right_x = C + S;
	while (true) {
		// ���������� ����
		for (int j = left_x; j < right_x; j++) {
			backup[left_y][j + 1] = tmp_backup[left_y][j];
		}
		// �Ʒ������� ����
		for (int i = left_y; i < right_y; i++) {
			backup[i + 1][right_x] = tmp_backup[i][right_x];
		}
		// �������� ����
		for (int j = right_x; j > left_x; j--) {
			backup[right_y][j - 1] = tmp_backup[right_y][j];
		}
		// �������� ����
		for (int i = right_y; i > left_y; i--) {
			backup[i - 1][left_x] = tmp_backup[i][left_x];
		}
		// �迭�� ���ʵ� ����
		left_y++; left_x++; right_y--; right_x--;

		// ���簢���̹Ƿ�, ��� ���� �����ϸ� ��
		if ((left_y == right_y) && (left_x == right_x)) {
			break;
		}
	}
	//ptr(); cout << endl;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({{r,c},s});		
	}
	sort(v.begin(), v.end()); // �̰� ��� Ʋ�Ⱦ���
	int result = 987654321;
	do
	{
		//result = 987654321;
		memcpy(backup, map, sizeof(backup));
		for (int i = 0; i <v.size(); i++) {
			//cout << oper[i].r << ' '<< oper[i].c <<' '<< oper[i].s << ' ';			
			rotate(v[i].first.first, v[i].first.second, v[i].second);
			//cout << endl;
		}
		//cout << endl;
		result = min(calc(), result);
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
}