#include <bits/stdc++.h>
#define endl "\n"
#define MAX 100 + 1
using namespace std;
int n, m;
int Map[MAX][MAX];

struct INFO {
    int num;  // ������ȣ
    int cnt;  // �ɺ����� ����
};

bool cmp(INFO a, INFO b) {
    if (a.cnt == b.cnt) {
        return a.num < b.num;
    }
    return a.cnt < b.cnt;
}
vector<INFO> people;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {                // i���� j���� ���µ� k�� ���ļ� ����
                if (Map[i][k] + Map[k][j] < Map[i][j]) {  // k�� ���İ��°� �� ������
                    Map[i][j] = Map[i][k] + Map[k][j];    // �� ����
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int f1, f2;
    for (int i = 0; i < m; i++) {
        cin >> f1 >> f2;
        Map[f1][f2] = 1;
        Map[f2][f1] = 1;
    }
    // ���� ��ó�� �۾�
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (Map[i][j] == 0) {
                Map[i][j] = 99;
            }
        }
    }
    floyd();
    for (int i = 1; i <= n; i++) {
		int num = i;
		int cnt = 0;
        for (int j = 1; j <= n; j++) {
			cnt += Map[i][j];            
        }
        people.push_back({num,cnt});
    }

     sort(people.begin(), people.end(), cmp);
     cout << people[0].num;
    return 0;
}