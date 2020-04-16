#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct medal {
	int flag;
	int gold;
	int silver;
	int dong;
	int rank;
};

vector<medal> arr(1001);

bool cmp(const medal& a, const medal& b) {
	if (a.gold > b.gold) { return true; }  
	else if (a.gold == b.gold) {
		if (a.silver > b.silver) { return true; }
		else if (a.silver == b.silver) {
			if (a.dong > b.dong) { return true; }
		}
	}
	return false;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].flag >> arr[i].gold >> arr[i].silver >> arr[i].dong;
	}
	int rank = 1;
	int cnt = 0;
	sort(arr.begin() + 1, arr.end(), cmp);
	arr[1].rank = 1;
	for (int i = 2; i <= n; i++) {
		if ((arr[i].gold == arr[i - 1].gold) && (arr[i].silver == arr[i - 1].silver) && (arr[i].dong == arr[i - 1].dong)) { //전부 같은경우 랭크를 똑같이
			arr[i].rank = rank;
			cnt++;
		}
		else {
			rank++;
			rank += cnt;
			arr[i].rank = rank;
			cnt = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i].flag == k) {
			cout << arr[i].rank;
		}
	}
}
