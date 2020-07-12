#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000
using namespace std;
int n;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n;
    unordered_map<int, int>numbers;
    vector<int>number;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        numbers[num]=i;
        number.push_back(num);
    }
    //cout<<numbers[1];
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=number[i]; j<MAX; j++){
            if(numbers[j]!=0){
                cout<<numbers[j]<<' ';
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<-1<<' ';
        }
    }
	return 0;
}