#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	int e, s, m;
	cin >> e >> s >> m;
	int cur_e = 1;
	int cur_s = 1;
	int cur_m = 1;
	int year = 1;
	int candi = 1;
	while (true)
	{
		cur_e %= 16; if (cur_e == 0) cur_e = 1;
		cur_s %= 29; if (cur_s == 0) cur_s = 1;
		cur_m %= 20; if (cur_m == 0) cur_m = 1;
		if (cur_e == e && cur_s == s && cur_m == m) {
			cout << year;
			return 0;
		}
		++cur_e; ++cur_s; ++cur_m;
		year++;
	}
}