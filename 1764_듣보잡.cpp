#include<iostream>
#include<map>
using namespace std;
//듣보잡의 수와 그 명단을 사전순으로 출력한다.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	map<string,int>no_see_listen;	
	string tmp;
	int num=0;
	int cnt; 
	map<string, int>::iterator it;
	for (int i = 0; i < n+m; i++) {
		cin >> tmp;
		cnt = 1;
		if (no_see_listen.count(tmp)>=1) { // value 값을 1 증가시켜야 함
			num++;
			no_see_listen[tmp]++;
		}
		no_see_listen.insert({tmp,cnt});
	}
	cout << num << "\n";
	for (it = no_see_listen.begin(); it != no_see_listen.end(); it++) {
		if (it->second >= 2) {
			cout << it->first<< "\n";
		}
	}

}