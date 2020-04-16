#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000+1
using namespace std;
int s;
int answer = 987654321;
int arr[MAX][MAX]; // i:화면에 있는 이모티콘의 개수, j:클립보드에 있는 이모티콘의 개수, arr[i][j]:이렇게 되기까지 걸린 시간
bool visit[MAX][MAX];
int bfs() {
	arr[1][0] = 0;
	visit[1][0] = true;
	queue<pair<int, int>>q;
	q.push({ 1,0 });
	while (!q.empty()) {
		int disp = q.front().first;
		int clip = q.front().second;
		int cur = arr[disp][clip];
		q.pop();
		if (disp == s) {
			return cur;
		}
		if (0 < disp && disp < MAX) {
			// 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
			if (!visit[disp][disp]) {
				arr[disp][disp] = cur+1;
				visit[disp][disp] = true;
				q.push({ disp,disp });
			}
			// 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
			if (clip > 0 && disp + clip < MAX) {
				if (!visit[disp + clip][clip]) {
					arr[disp + clip][clip] = cur + 1;
					visit[disp + clip][clip] = true;
					q.push({ disp + clip,clip });
				}
			}
			// 화면에 있는 이모티콘 중 하나를 삭제한다.
			if (!visit[disp - 1][clip]) {
				visit[disp - 1][clip] = true;
				arr[disp - 1][clip] = cur + 1;
				q.push({ disp - 1,clip });
			}
		}		
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> s;
	memset(arr, -1, sizeof(arr));
	
	cout << bfs();
	return 0;
}