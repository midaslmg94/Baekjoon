#include <bits/stdc++.h>
#define endl "\n"
#define NANO 10000000
using namespace std;
int x, hole, n;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.txt", "r", stdin);
    while (scanf("%d", &x) == 1) {
        x = x * NANO;
        cin >> n;
        vector<int> lego;
        
        for (int i = 0; i < n; i++) {
            cin >> hole;
            lego.push_back(hole);
        }
        sort(lego.begin(), lego.end());
        int p1 = 0;
        int p2 = n - 1;
        int res = 0;

        while (true) {
       // cout<<" x " << x <<" n "<<n<<" p1 "<<p1<<" p2 "<<p2<<" sum "<<lego[p1] + lego[p2]<<endl;
            if (p1 >= p2 || p1 < 0 || p2 > n - 1) {
                cout << "danger" << endl;
                break;
            }
            if (lego[p1] + lego[p2] > x) {
                p2--;
            } else if (lego[p1] + lego[p2] < x) {
                p1++;
            } else {
                cout << "yes " << lego[p1] << ' ' << lego[p2] << endl;
                break;
            }
        }
    }

    return 0;
}