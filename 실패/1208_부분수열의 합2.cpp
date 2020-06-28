#include <bits/stdc++.h>
#define endl "\n"
#define MAX 41
using namespace std;
int n;
int s;
int answer = 0;
vector<int> v[MAX][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> s;
	
    for (int i = 1; i <= n; i++) {
		int tmp;
		cin>>tmp;
		v[1][i].push_back(tmp);
    }
	for(int i=2; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<v[i][j].size(); k++){
				
			}
		cout<<endl;
		}
	}
	

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<v[i][j].size(); k++){				
				if(v[i][j][k]==s){					
					answer++;
				}
			}
		}
	}
	cout<<answer;
    return 0;
}