#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
/*
1. 원래 회전 초밥은 손님이 마음대로 초밥을  고르고, 먹은 초밥만큼 식대를 계산하지만, 
벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다. 

2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다. 
만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공한다.  

*/


/*
첫 번째 줄에는 회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c가 각각 하나의 빈 칸을 사이에 두고 주어진다. 
단, 2 ≤ N ≤ 30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d이다. 
두 번째 줄부터 N개의 줄에는 벨트의 한 위치부터 시작하여 회전 방향을 따라갈 때 초밥의 종류를 나타내는 1 이상 d 이하의 정수가 각 줄마다 하나씩 주어진다. 
*/

int n, d, k, c;
int answer = 0;
int slidingWindow[35000];
vector<int>belt;
map<int, int>eat_sushi; // 규칙에 맞게 먹었을 때
/*
회전 초밥 음식점의 벨트 상태, 메뉴에 있는 초밥의 가짓수, 연속해서 먹는 접시의 개수, 쿠폰 번호가 주어졌을 때, 
손님이 먹을 수 있는 초밥 가짓수의 최댓값을 구하는 프로그램을 작성하시오. 
*/
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n>>d>>k>>c;
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        belt.push_back(inp);   
    }
    for(int i=0; i<k; i++){
        belt.push_back(belt[i]); // 초밥레일이 이어져 있으므로 그냥 뒤에 추가
    }

    // 초기화 
    int res = 0;
    for(int i=0; i<k; i++){
        if(eat_sushi.count(belt[i]) == 0){ // 처음 먹은 종류의 초밥
            res++;
        }
        eat_sushi[belt[i]]+=1;  // 해당 종류의 초밥을 먹은 개수
        slidingWindow[i] = res; // [i-k ~ i] 까지 몇 종류의 초밥을 먹었는지
        cout<<slidingWindow[i]<<' ';
    }

    for(int i=k; i<belt.size(); i++){  // 윈도우 포인터를 하나씩이동  
        if(eat_sushi.count(belt[i-k])==1){ // 가장 먼저 먹었던 초밥 삭제
            res--;
        }
        eat_sushi[belt[i-k]] -= 1; 
        
        if(eat_sushi.count(belt[i]) == 0){  // 새로운 초밥 하나 먹음
            res++;
        }
        eat_sushi[belt[i]] += 1;
        slidingWindow[i] = res;
        
        if(eat_sushi.count(c) == 0){ // 쿠폰 초밥을 안먹었으면 추가                      
            slidingWindow[i] = res+1;
        }
        cout<<slidingWindow[i]<<' ';
    }
    sort(slidingWindow, slidingWindow+35000, greater<int>());
    for(auto a:slidingWindow){
        //cout<<a<<' ';
    }
    cout<<slidingWindow[0];
    //cout<<answer;

	return 0;
}