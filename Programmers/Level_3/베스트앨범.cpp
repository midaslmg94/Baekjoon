#include <bits/stdc++.h>

using namespace std;
struct INFO {
    string gen;
    int idx;
    int cnt;    
};
bool cmp(pair<string, int> a, pair<string, int>b){
    if(a.second == b.second) return a.first<b.first;
    return a.second > b.second;
}

bool cmp2(INFO a, INFO b){
    if(a.cnt == b.cnt){        
        if(a.idx == b.idx){
            return a.gen<b.gen;
        }
        return a.idx < b.idx;
    }
    return a.cnt>b.cnt;
}

map<string, int>genres_play_count; //속한 노래가 많이 재생된 장르를 먼저 수록합니다. 장르 내 속한 노래가 몇번 플레이 되었는지 

// genres[i]는 고유번호가 i인 노래의 장르입니다.
// plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<INFO>music;
    for(int i=0; i<genres.size(); i++){
        genres_play_count[genres[i]]+=plays[i]; // 해당 장르가 몇번 플레이 되었는지        
        music.push_back({genres[i], i, plays[i]}); // 장르, 고유번호, 재생 횟수
    }
    vector<pair<string, int>>v(genres_play_count.begin(), genres_play_count.end()); // value로 정렬하기 위해 벡터에 저장
    sort(v.begin(), v.end(), cmp); // 속한 노래가 많이 재생된 장르로 정렬
    sort(music.begin(), music.end(), cmp2);    // 장르 내에서 많이 재생된 노래, 고유번호가 낮은 순으로 정렬
    
    for(auto m:v){
        string cur = m.first;
        int count = 0;
        for(int i=0; i<music.size(); i++){
            if(cur == music[i].gen){ // 장르가 같다면
                // cout<<music[i].idx<<' '; 
                answer.push_back(music[i].idx); // 장르 내에서 많이 재생된 노래, 고유번호가 낮은 순
                count++;
            }
            if(count>=2)break; // 최대 2개까지만 저장
        }
    }
    return answer;
}