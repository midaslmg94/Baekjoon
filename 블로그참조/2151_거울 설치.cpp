#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define INF 987654321
#define MAX 50
using namespace std;
struct mirror {
	int y, x, dir;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 }; // ťóÇĎÁÂżě
int n;
char map[MAX][MAX];
int visit[MAX][MAX][4]; // i,jżĄź­ şűŔĚ kŔÇ šćÇâŔ¸ˇÎ ÁřÇŕÇŇ ś§, ÁöąÝąîÁö źłÄĄÇŃ šŽŔÇ °łźö

pair<int, int>startDoor;
pair<int, int>endDoor;
queue<mirror>q;
pair<int, int> changeDir(int cur) { // şűŔĚ ľéžîżŔ´Â šćÇâżĄ ľűśó °ĹżďżĄ şÎľúÇűŔťś§ ˛ŞŔĚ´Â °Ô ´Ů¸Ł´Ů.(2°ĄÁö ÇüĹÂŔÇ °ĹżďżĄ şÎľúČű)
	pair<int, int>res;
	if (cur == 0 || cur == 1) { // şűŔĚ Ŕ§ÂĘŔĚłŞ žĆˇĄÂĘżĄź­ ľéžîżČ --> şűŔş żŢÂĘŔĚłŞ żŔ¸ĽÂĘŔ¸ˇÎ ÁřÇŕ
		res.first = 2; // żŢÂĘŔ¸ˇÎ ÁřÇŕÇŇ źöľľ ŔÖ°í
		res.second = 3; // żŔ¸ĽÂĘŔ¸ˇÎ ÁřÇŕÇŇ źöľľ ŔÖŔ˝
	}
	else if (cur == 2 || cur == 3) { // şűŔĚ żŢÂĘŔĚłŞ žĆˇĄÂĘżĄź­ ľéžîżČ --> şűŔş Ŕ§ÂĘŔĚłŞ žĆˇĄÂĘŔ¸ˇÎ ÁřÇŕ
		res.first = 0; // Ŕ§ˇÎ ÁřÇŕÇŇ źöľľ ŔÖ°í
		res.second = 1;  // žĆˇĄˇÎ ÁřÇŕÇŇ źöľľ ŔÖŔ˝
	}
	return res;
}
void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int, int> ndir = changeDir(dir);

		if (0 > ny || ny >= n || 0 > nx || nx >= n)continue; // šüŔ§ ĂĘ°ú
		if (map[ny][nx] == '*') continue; // şŽ ŔĎ °ćżě : ÁřÇŕşŇ°Ą
		else if (map[ny][nx] == '!') { // °ĹżďŔĎ °ćżě
			if (visit[ny][nx][dir] > visit[y][x][dir]) { // ÇŘ´çŔ§ÄĄżĄ °ĹżďŔť źłÄĄÇĎÁö žĘ°í ÁřÇŕ
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}			
			// žĆˇĄ 2°łŔÇ if¸Ś ŔĚÇŘÇĎ´Â°Ô °ĄŔĺ žîˇÁżü´Ů.
			// else if°Ą žĆ´Ń if¸Ś ťçżëÇŘžßÇÔ --> °ĹżďŔş 2°ĄÁö ťóĹÂ¸Ś °ĄÁú źö ŔÖąâ šŽ
			if (visit[ny][nx][ndir.first] > visit[y][x][dir] + 1) {// ÇŘ´çŔ§ÄĄżĄ °ĹżďŔť źłÄĄÇĎ°í ÁřÇŕ
				visit[ny][nx][ndir.first] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.first });
			}
			if (visit[ny][nx][ndir.second] > visit[y][x][dir] + 1) {
				visit[ny][nx][ndir.second] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.second});
			}			
		}
		else if (map[ny][nx] == '.') { // şó °÷ŔĎ °ćżě : ąâÁ¸ŔÇ °ŞŔĚ ´ő ŔŰŔť°ćżě °ť˝Ĺ
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}
		}
		else if (map[ny][nx] == '#') { // šŽ ŔĎ °ćżě : ľľÂř ÁöÁĄŔĚšÇˇÎ, ÇŘ´ç šćÇâŔ¸ˇÎ ľéžîżŔ´Â °ŞŔť şńąłÇĎżŠ ĂÖźÚ°Ş ŔúŔĺ
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				if (flag) { // ˝ĂŔŰÇĎ´Â šŽ
					startDoor.first = i;
					startDoor.second = j;
					flag = false;
				}
				else {// ľľÂřÇĎ´Â šŽ
					endDoor.first = i;
					endDoor.second = j;
				}					
			}
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}

	for (int i = 0; i < 4; i++) {// ĂłŔ˝ šŽżĄź­şÎĹÍ ˝ĂŔŰ
		q.push({ startDoor.first,startDoor.second,i });
		visit[startDoor.first][startDoor.second][i] = 0;
	}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++) { // ¸śÁö¸ˇ ÁöÁĄżĄź­ 4šćÇâŔ¸ˇÎ ľéžîżÂ °ćżě Áß ĂÖźÚ°Ş ĂâˇÂ
		if (result > visit[endDoor.first][endDoor.second][i]) {
			result = visit[endDoor.first][endDoor.second][i];
		}
	}
	cout << result;
	return 0;
}