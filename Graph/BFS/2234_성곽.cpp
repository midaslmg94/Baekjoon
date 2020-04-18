#include <bits/stdc++.h>
#define endl "\n"
#define MAX 50
using namespace std;
int n, m;
int room[MAX][MAX];
int room_num[MAX][MAX]; // 방번호
bool visit[MAX][MAX];
vector<int> v[MAX][MAX]; // i,j에서 갈 수 있는 방향
vector<int> room_size;
int room_cnt = 0
;
int max_room_cnt = 0;
int remove_max_room_cnt = 0;
int dy[4] = {1, 0, -1, 0}; // 남, 동, 북, 서
int dx[4] = {0, 1, 0, -1};
void bfs(int y, int x, int idx)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visit[y][x] = true;
    room_num[y][x] = idx;
    int cnt = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < v[y][x].size(); i++)
        {
            int next = v[y][x][i];
            int ny = y + dy[next];
            int nx = x + dx[next];
            if (0 > ny || ny > n - 1 || 0 > nx || nx > m - 1)
                continue;
            if (visit[ny][nx])
                continue;
            visit[ny][nx] = true;
            q.push(make_pair(ny, nx));
            room_num[ny][nx] = idx;
            cnt++;
        }
    }
    room_size.push_back(cnt);
    max_room_cnt = max(cnt, max_room_cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }
    room_size.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string str = bitset<4>(room[i][j]).to_string(); // 10진수를 2진수로 변환. 단 문자열로 
            for (int k = 0; k < 4; k++)
            {
                if (str[k] == '0')
                {
                    v[i][j].push_back(k);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                bfs(i, j, ++room_cnt);
            }
        }
    }    
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << room_num[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
   

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            if(room_num[i][j]!=room_num[i][j+1]){ // 옆이 다른 방이면, 그 둘의 개수를 합침
                remove_max_room_cnt = max(remove_max_room_cnt, room_size[room_num[i][j]]+room_size[room_num[i][j+1]]);
            }
            if(room_num[i][j]!=room_num[i+1][j]){
                remove_max_room_cnt = max(remove_max_room_cnt, room_size[room_num[i][j]]+room_size[room_num[i+1][j]]);
            }
        }       
    }
    // for (int i = 0; i < room_size.size(); i++)
    // {
    //     cout << room_size[i] << ' ';
    // }
    // cout << endl;

    cout << room_cnt << endl;
    cout << max_room_cnt << endl;
    cout << remove_max_room_cnt<<endl;
    return 0;
}