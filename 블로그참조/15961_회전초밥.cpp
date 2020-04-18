#include <bits/stdc++.h>
#define endl "\n"
#define MAX 3000 + 1
using namespace std;
//회전 초밥 벨트에 놓인 접시의 수 n, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
int n, d, k, c;
int answer = -1;
vector<int> sushi;
int eat[MAX];	 // i번 초밥을 몇 개 먹었는지
deque<int> mysushi;	 // k개 먹은 초밥
int cnt = 0; // 중복없이 먹은 초밥의 개수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sushi.push_back(num);
	}
	for (int i = 0; i < k; i++)
	{
		mysushi.push_back(sushi[i]);
		if (!eat[sushi[i]])
			cnt++;
		eat[sushi[i]]++;
	}

	for (int i = 0; i < n - 1; i++)
	{
		// 맨 처음 먹은 초밥빼기
		mysushi.pop_front();
		// 뺀 초밥이 먹은 리스트에 남아있지 않을 경우 개수를 뺀다
		eat[sushi[i]]--; // 먼저 빼줘야 한다
		if (!eat[sushi[i]])
			cnt--;
		// 다음 초밥 한개 추가하기
		mysushi.push_back(sushi[(i + k)%n]); // 회전 초밥이므로 인덱스를 이렇게 가져가는게 중요
		if (!eat[sushi[(i + k)%n]]) 
			cnt++;
		eat[sushi[(i + k)%n]]++; // 나중에 더해줘야 한다.

		// 쿠폰 초밥을 안먹었으면 +1
		if (!eat[c])
			answer = max(answer, cnt + 1);
		else
			answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}