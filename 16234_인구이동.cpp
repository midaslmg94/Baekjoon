#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int map[50][50];
bool visit[50][50];
int union_map[50][50];  // ������ �����ϱ� ���� �迭
int union_flag = 1; // ���� ������ ���� flag
bool finish; //  �α��̵��� �������� �˸��� flag
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int	N, L, R;
int cnt = 0; // �α��̵� Ƚ��
int union_country; //  ������ �̷�� �ִ� ������ ����
int union_people; // ������ �α��� 

void bfs(int y, int x, int flag) {
	visit[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	union_country = 1; //  ������ �̷�� �ִ� ������ ����
	union_people = map[y][x]; // ������ �α��� 
	union_map[y][x] = flag; // ������ ���� 
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { // ��, ��, ��, �� ������ Ȯ��
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && !visit[ny][nx]) { // ��輱 ����, �湮 X 
				int diff = abs(map[ny][nx] - map[y][x]); // �� ���� ����
				if (L <= diff && diff <= R) { // ���� ������ �� �� ����
					visit[ny][nx] = true;
					finish = false;
					union_people += map[ny][nx];
					union_country++;
					q.push({ ny, nx });
					union_map[ny][nx] = flag;
				}
			}
		}		
	}
	union_flag++;
}

void moving() {
	int new_country_people = union_people / union_country;
	cout << "people" << union_people << endl;
	cout << "contry" << union_country << endl;
	cout << "new" << new_country_people<<endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (union_map[i][j] == union_flag) {// ���� �����̸� �α� �̵�
				map[i][j] = new_country_people;				
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; 
		}
	}
	/*
		1. �� �� �ִ� ������ ���� ���յ��� �����.--> ������ ���� �ִ��� Ȯ�� --> ������ �ϳ��� ���������� ����. �α��̵� �߻�Ƚ�� ���
		2. ������ 2�� �̻� ������ �� �ִ�. --> ������ �����ϱ� ���� ���� �ʿ�
		3. �� ���ճ����� �����̵� ���� --> ������ �α����� ��/������ �̷�� ĭ�� ����
		4. �α��̵� +1
	*/

	while (true) {
		finish = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {					
					bfs(i, j, union_flag); // ������ Ȯ��, ���� �����
					moving(); // �α��̵� ����					
				}
			}
		}
		if (finish) {
			break;
		}
		cnt++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j]=false;
			}
		}
		union_flag = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
	}
	cout << "����:"<<cnt;
}