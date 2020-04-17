#include<bits/stdc++.h>
#define endl "\n"
#define MAX 3000+1
using namespace std;
//회전 초밥 벨트에 놓인 접시의 수 n, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
int n, d, k, c;
queue<int>sushi_pos[MAX];
vector<int>sushi;
int dp[3000000];
bool eat[MAX];
int answer = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n>>d>>k>>c;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		sushi.push_back(num);
		sushi_pos[num].push(i); // num번 초밥은 i번째에 위치함
	} 
	
	int cnt = 1; // 현재 먹은 초밥 개수
	dp[0]=1;
	eat[sushi[0]]=true;
	for(int i=1; i<n; i++){
		int cur = sushi[i];
		if(eat[cur]==true){ // 이미 먹은 초밥이면
			cnt = dp[i];
			if(!eat[c] && cnt>=k) cnt++; // 행사 참여가능한 개수만큼 먹고, 쿠폰으로 먹을 수 있는 초밥을 안먹었다면
			answer = max(answer,cnt);			
			dp[i]=i-sushi_pos[cur].front();
			sushi_pos[cur].pop();
		}
		else{
			eat[cur]=true;			
			dp[i]=dp[i-1]+1;
		}
		cnt = max(cnt,dp[i]);
		cout<<"cur:"<<cur<<" cnt:"<<cnt<<" answer: "<<answer<<" i:"<<i<<" dp[i]:"<<dp[i]<<endl;
	}
	if(!eat[c]&& cnt>=k)cnt++; // 맨 마지막까지 갔을 때, 쿠폰 초밥을 안먹은 경우
	answer=max(cnt,answer);
	cout<<answer;
	return 0;
}