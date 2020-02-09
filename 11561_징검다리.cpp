#include<iostream>
using namespace std;
int t;
long long n; // 1번, 2번 ... n번 징검다리
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> t;
	/*
	첫 징검다리는 점프해서 아무 것이나 밟을 수 있다. 이 점프가 첫 점프이다.
	두 번째 점프부터는 이전에 점프한 거리보다 1 이상 더 긴 거리를 뛰어야만 한다.
	N번 징검다리는 반드시 밟아야 한다.
	N번 징검다리를 밟은 후 강 건너로 이동할 땐 점프를 하지 않으므로 위의 규칙이 적용되지 않는다.
	*/

	while (t--) {
		long long jump = 1; // 시작점에서 1로 갔으므로 초기값:1
		cin >> n;
		long long cur = 1; // 1번부터 뛰어야 함
		long long dist = 1;
		while (cur!=n) {
			dist++;
			cur = cur + dist;
			if (cur > n) {
				break;
			}
			jump++;
		}
		cout << jump<<"\n";
	}
}