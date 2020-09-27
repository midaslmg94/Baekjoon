#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10000
using namespace std;
int n, m;
int crane_weight, box_weight;
vector<int> cranes;
vector<int> boxes;
int answer = 0;
void prt(){
    for(int i=0; i<boxes.size(); i++){
        cout<<boxes[i]<<' ';
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {  // 최대 50
        cin >> crane_weight;
        cranes.push_back(crane_weight);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {  // 최대 10,000
        cin >> box_weight;
        boxes.push_back(box_weight);
    }
    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());
    if(boxes[0]>cranes[0]){cout<<-1; return 0;}
    while (!boxes.empty()){
        answer++;
        for(int i=0; i<cranes.size(); i++){
            for(int j=0; j<boxes.size(); j++){
                if(cranes[i]>=boxes[j]){ // 크레인이 박스를 들 수 있다면
                    boxes.erase(boxes.begin()+j); // 해당 위치의 박스 제거
                    break;
                }
            }
        }   
    }
    cout<<answer;
    return 0;
}