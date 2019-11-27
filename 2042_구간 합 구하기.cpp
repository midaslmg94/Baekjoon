#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*펜윅트리로 풀기*/
long long sum(vector <long long>&tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<long long>&tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long>a(n + 1);
	vector <long long>tree(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(tree, i, a[i]);
	}
	for (int i = 0; i < m + k; i++) {
		int t1;
		cin >> t1;
		int t2;
		long long t3;
		cin >> t2 >> t3;
		if (t1 == 1) {// a==1, b번째 수를 c로 바꿈			
			long long diff = t3- a[t2];
			a[t2] = t3;
			update(tree, t2, diff);
		}
		else { // 구간합 구하기			
			cout << sum(tree,t3)-sum(tree, t2 - 1)<<"\n";
		}
	}
	return 0;
}