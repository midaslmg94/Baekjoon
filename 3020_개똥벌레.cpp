#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, h;
vector <int> suck; //석순
vector <int> jong;  //종유석
vector<int>result; // 파괴하는 장애물의 개수 
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (i % 2==0) {//석순
			suck.push_back(tmp);
		}
		else {//종유석
			jong.push_back(tmp);
		}
	}
	sort(suck.begin(), suck.end());
	sort(jong.begin(), jong.end());
	int sector1; // 석순의 구간
	int cnt_suck=0; // 잘리는 석순의 개수
	int sector2; // 종유석의 구간
	int cnt_jong = 0; //잘리는 종유석의 개수
	for (int i = 1; i <= h; i++) {
		sector1 = i; 
		sector2 = h - sector1+1; // 여기서 좀 헤멨다 +1을 안해줘서
		// 이 위치보다 위에 있는 석순, 종유석들이 잘림
		int pos_suck = lower_bound(suck.begin(), suck.end(), sector1)-suck.begin();
		int pos_jong = lower_bound(jong.begin(), jong.end(), sector2)-jong.begin();

		cnt_suck = suck.size() - pos_suck;
		cnt_jong = jong.size() - pos_jong;
 		result.push_back(cnt_suck + cnt_jong);
	}
	// 개똥벌레가 파괴해야 하는 장애물의 최솟값과 그러한 구간의 수를 공백으로 구분하여 출력한다.
	sort(result.begin(), result.end());

	int ans = result[0]; // 장애물의 최솟값
	// 같은 값이 총 몇개가 있는지 찾음
	cnt = upper_bound(result.begin(), result.end(), ans) - lower_bound(result.begin(), result.end(), ans);
	cout << ans << ' ' << cnt;
}