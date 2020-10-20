#include <bits/stdc++.h>
using namespace std;
int answer = 1;
int parent[201];
int find_parent(int a){
    if(a!=parent[a])
        return parent[a] = find_parent(parent[a]);
    return a;
}
void union_find(int a, int b){        
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    if(p1!=p2){
        if(p1<p2){
            parent[p2] = p1;
        }
        else{
            parent[p1] = p2;
        }
    }
}
int solution(int n, vector<vector<int>> computers) {    

    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || computers[i][j] == 0)continue;
           // if(find_parent(i) != find_parent(j)){
                union_find(i, j);
           // }
        }
    }
      for(int i=0; i<n; i++){ // 부모를 업데이트 해줌 -> 이걸 해줘야한다!
        parent[i] = find_parent(i);
    }
    sort(parent, parent+n); // 같은 부모를 가진것끼리 비교 하기 위해 정렬
    for(int i=0; i<n-1; i++){
        if(parent[i]!=parent[i+1]) answer++;
        cout<<parent[i]<< ' ';
    }
    return answer;
}
