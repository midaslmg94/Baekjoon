#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, tmp;
vector<int>alkali;
vector<int>acid;
struct INFO{
    int sum_liquid;
    int left;
    int right;
};
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        if(tmp<0) alkali.push_back(tmp);
        else acid.push_back(tmp);
    }
    sort(acid.begin(), acid.end()); // 산성 : 양수
    sort(alkali.begin(), alkali.end(), greater<int>()); // 알칼리 : 음수
    int idx_acid = 0;
    int idx_alkali = 0;
    if(acid.size()==0){ // 알칼리만 있는 경우 : 오름차순 출력
        cout<<alkali[1]<<' '<<alkali[0];
        return 0;
    }
    if(alkali.size()==0){ // 산성만 있는 경우
        cout<<acid[0]<<' '<<acid[1];
        return 0;
    }
    INFO ans;
    if(abs(acid[0]+acid[1])<abs(alkali[0]+alkali[1])){
        ans.left = acid[0];
        ans.right = acid[1];
        ans.sum_liquid = ans.left+ans.right;
    }
    else{
        ans.left = alkali[0];
        ans.right = alkali[1];
        ans.sum_liquid =  ans.left+ans.right;
    }
    
    int len = max(acid.size(), alkali.size());
    for(int i=0; i<len; i++){
        if(acid[idx_acid]+alkali[idx_alkali]>0 && i<alkali.size()){ // 양수인 경우 : 알칼리 값 (절댓값)증가
            if(abs(ans.sum_liquid) > abs(acid[idx_acid]+alkali[idx_alkali])){ 
                idx_alkali++;
                ans.right = acid[idx_acid];
                ans.left = alkali[idx_alkali];
                ans.sum_liquid = acid[idx_acid]+alkali[idx_alkali];
            }
        }
        else if(acid[idx_acid]+alkali[idx_alkali]<0 && i<acid.size()){ // 음수인 경우 : 산성 값 증가
            if(abs(ans.sum_liquid) > abs(acid[idx_acid]+alkali[idx_alkali])){ 
                idx_acid++;
                ans.right = acid[idx_acid];
                ans.left = alkali[idx_alkali];
                ans.sum_liquid = acid[idx_acid]+alkali[idx_alkali];
            }
        }
        else{ // 0인 경우            
            cout<<alkali[idx_alkali]<<' '<<acid[idx_acid];
            return 0;
        }
    }
    cout<<ans.left<<' '<<ans.right;
	return 0;
}