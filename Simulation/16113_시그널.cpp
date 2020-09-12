#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n;
string sign;
vector<int>ans;
// 해당 숫자를 위에서 아래로 읽었을 때 나오는 값
string zero = "######...######";
string one = "#####";
string two = "#.####.#.####.#";
string three = "#.#.##.#.######";
string four = "###....#..#####";
string five = "###.##.#.##.###";
string six = "######.#.##.###";
string seven = "#....#....#####";
string eight = "######.#.######";
string nine = "###.##.#.######";
char SIGNAL[5][20000];
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n>>sign;
    int len = n/5; // 몇개씩 끊어 읽을 건지
    int idx = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<len; j++){            
            SIGNAL[i][j] = sign[idx++];
        }
    }
    
    string str="";
    for(int i=0; i<len; i++){        
        if(SIGNAL[0][i]=='.'){  // 맨 윗줄이 공백인 경우 : 띄어쓰기 칸 이거나 숫자 4
            if(str.compare("###..")==0) goto here;                       
            else if(str.compare(zero)==0)cout<<'0';
            else if(str.compare(one)==0)cout<<'1';
            else if(str.compare(two)==0) cout<<'2';
            else if(str.compare(three)==0) cout<<'3';
            else if(str.compare(four)==0)cout<<'4';
            else if(str.compare(five)==0)cout<<'5';
            else if(str.compare(six)==0) cout<<'6';
            else if(str.compare(seven)==0)cout<<'7';
            else if(str.compare(eight)==0)cout<<'8';
            else if(str.compare(nine)==0)cout<<'9';         
            //ans.push_back(res);
            str="";
            continue;
        }
        here:
        for(int j=0; j<5; j++){
            str+=SIGNAL[j][i];
        }        
    } 
    // 마지막에 숫자 붙어있는 경우
    if(str.compare(zero)==0)cout<<'0';
    else if(str.compare(one)==0)cout<< '1';
    else if(str.compare(two)==0) cout<<'2';
    else if(str.compare(three)==0) cout<<'3';
    else if(str.compare(four)==0)cout<<'4';
    else if(str.compare(five)==0)cout<<'5';
    else if(str.compare(six)==0) cout<<'6';
    else if(str.compare(seven)==0)cout<<'7';
    else if(str.compare(eight)==0)cout<<'8';
    else if(str.compare(nine)==0)cout<<'9';         
	return 0;
}