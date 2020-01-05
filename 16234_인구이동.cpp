#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int map[50][50];
bool visit[50][50];
int union_map[50][50];  // 연합을 구분하기 위한 배열
int union_flag = 1; // 연합 구분을 위한 flag
bool finish; //  인구이동이 끝났음을 알리는 flag
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int	N, L, R;
int cnt = 0; // 인구이동 횟수
int union_country; //  연합을 이루고 있는 나라의 개수
int union_people; // 연합의 인구수 

void bfs(int y, int x, int flag) {
	visit[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	union_country = 1; //  연합을 이루고 있는 나라의 개수
	union_people = map[y][x]; // 연합의 인구수 
	union_map[y][x] = flag; // 연합의 구분 
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { // 상, 하, 우, 좌 순으로 확인
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && !visit[ny][nx]) { // 경계선 내부, 방문 X 
				int diff = abs(map[ny][nx] - map[y][x]); // 두 값의 차이
				if (L <= diff && diff <= R) { // 서로 국경을 열 수 있음
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
			if (union_map[i][j] == union_flag) {// 같은 연합이면 인구 이동
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
		1. 열 수 있는 국경을 열어 연합들을 만든다.--> 국경을 열수 있는지 확인 --> 국경을 하나도 열수없으면 종료. 인구이동 발생횟수 출력
		2. 연합은 2개 이상 존재할 수 있다. --> 연합을 구분하기 위한 설정 필요
		3. 각 연합내에서 국경이동 시작 --> 연합의 인구수의 합/연합을 이루는 칸의 개수
		4. 인구이동 +1
	*/

	while (true) {
		finish = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {					
					bfs(i, j, union_flag); // 국경을 확인, 연합 만들기
					moving(); // 인구이동 시작					
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
	cout << "정답:"<<cnt;
}