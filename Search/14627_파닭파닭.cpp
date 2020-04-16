#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int s, c;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> s >> c;
	vector<ll>v;
	ll pa;
	ll total = 0;
	for (int i = 0; i < s; i++) {
		cin >> pa;
		v.push_back(pa);
		total += pa;
	}
	sort(v.begin(), v.end());
	ll left = 1; // 사용할 수 있는 파의 최소 길이 : 1
	ll right = 1000000001; // 모든 파를 안써도 되므로 초기값은 최대로
	ll result = 0;
	ll answer = 0; // 라면에 넣을 파의 양
	while (left <= right) {
		ll mid = (left + right) / 2; // 사용할 파의 길이
		ll chicken = 0;		
		for (int i = 0; i < v.size(); i++) {
			//if (mid == 0) break; // 0으로 나뉘는 것을 방지 --> 주석처리 시 100%에서 런타임에러, 주석해제 시 100%에서 틀렸습니다
			chicken += (v[i] / mid); // 만들 수 있는 치킨의 마리 수	
		}
		if (c <= chicken) { // 치킨이 더 많이 만들어졌음 --> 한마리 당 파를 더 써도 된다			
			result = mid;			
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	answer = total - (result * c); // 사용된 전체 파 = 만든 치킨 수*사용되는 파의 최대 길이	
	cout << answer;
	return 0;
}