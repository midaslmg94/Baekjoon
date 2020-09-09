#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;

map<string, int>menu_price; // 메뉴, 가격
map<string, string>menu_type; // 메뉴, 메뉴 등급(normal, special, serivice)
map<string, int>order_type; // 등급별 주문 수량
map<string, long long>order_price; // 등급별 주문 가격
int a,b,c;
string menu;
int price; 
int n;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>a>>b>>c;
    int cnt = a+b+c;
    for(int i=0; i<cnt; i++){
        if(a>0){
            cin>>menu>>price;
            menu_price[menu]=price;
            menu_type[menu]="normal";
            a--;
        }else if(b>0){
            cin>>menu>>price;
            menu_price[menu]=price;
            menu_type[menu]="special";
            b--;
        }else{
            cin>>menu;
            menu_type[menu]="service";
            c--;
        }
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>menu;
        string rank = menu_type[menu]; // 이 메뉴가 어떤 등급인지
        order_type[rank]+=1; // 해당 등급 주문 개수 +1
        if(rank!="service"){
            int pric = menu_price[menu]; // 이 메뉴가 얼마인지
            order_price[rank]+=pric;   // 해당 등급 주문 가격 
        }
    }
/*
특별메뉴는 일반메뉴에서 총 20,000원 이상을 주문해야 주문할 수 있다.
서비스메뉴는 일반메뉴와 특별메뉴에서 총 50,000원 이상을 주문해야 주문할 수 있다.
서비스메뉴는 단 하나만 주문할 수 있다.
*/
    if(order_type["special"]){
        if(order_price["normal"]<20000){ // 일반 메뉴 20,000원 미만 주문 -> 특별 주문 X
            cout<<"No";
            return 0;
        }
    }
    if(order_type["service"]){
        if(order_price["normal"]+order_price["special"]<50000){
            cout<<"No";
            return 0;
        }
    }
    if(order_type["service"]>1){
        cout<<"No";
        return 0;
    }
    cout<<"Okay";
    
    // for(auto a:order_type){
    //     cout<<a.first<<' '<<a.second<<endl;
    // }
    // for(auto a:order_price){
    //     cout<<a.first<<' '<<a.second<<endl;
    // }
	return 0;
}