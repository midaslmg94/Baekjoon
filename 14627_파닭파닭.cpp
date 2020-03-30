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
	ll left = 1; // ����� �� �ִ� ���� �ּ� ���� : 1
	ll right = 1000000001; // ��� �ĸ� �Ƚᵵ �ǹǷ� �ʱⰪ�� �ִ��
	ll result = 0;
	ll answer = 0; // ��鿡 ���� ���� ��
	while (left <= right) {
		ll mid = (left + right) / 2; // ����� ���� ����
		ll chicken = 0;		
		for (int i = 0; i < v.size(); i++) {
			//if (mid == 0) break; // 0���� ������ ���� ���� --> �ּ�ó�� �� 100%���� ��Ÿ�ӿ���, �ּ����� �� 100%���� Ʋ�Ƚ��ϴ�
			chicken += (v[i] / mid); // ���� �� �ִ� ġŲ�� ���� ��	
		}
		if (c <= chicken) { // ġŲ�� �� ���� ��������� --> �Ѹ��� �� �ĸ� �� �ᵵ �ȴ�			
			result = mid;			
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	answer = total - (result * c); // ���� ��ü �� = ���� ġŲ ��*���Ǵ� ���� �ִ� ����	
	cout << answer;
	return 0;
}