#include <bits/stdc++.h>
#define endl "\n"
#define MAX 500000 + 1
using namespace std;
int n, a, b;
int day = 1;
int dist = 0;
bool visit[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> a >> b; // a<b
    if (a > b)
        swap(a, b);
    if (a % 2 != b % 2)
    { // 홀짝 여부가 다르면 절대 못만남
        cout << -1;
        return 0;
    }
    // 최소가 음수면 0부터 모든 수 가능
    queue<int> A;
    queue<int> B;
    A.push(a);
    B.push(b);
    while (!A.empty() && !B.empty())
    {
        dist = pow(2, day - 1);
        int a_size = A.size();
        for (int i = 0; i < a_size; i++)
        {
            int up = A.front() + dist;
            int down = A.front() - dist;
            A.pop();
            if (up <= n)
            {
                visit[up] = true;
                A.push(up);
            }
            if (down > 0)
            {
                visit[down] = true;
                A.push(down);
            }
        }
        int b_size = B.size();
        for (int i = 0; i < b_size; i++)
        {
            int up = B.front() + dist;
            int down = B.front() - dist;
            B.pop();
            if (up <= n)
            {
                if (visit[up] == true)
                {
                    cout << day;
                    return 0;
                }
                B.push(up);
            }
            if (down > 0)
            {
                if (visit[down] == true)
                {
                    cout << day;
                    return 0;
                }
                B.push(down);
            }
        }
        day++;
        memset(visit, false, sizeof(visit));
    }
    cout << -1;
}