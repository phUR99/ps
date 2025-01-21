#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, D;
/*
왜 못풀었을까?
st 기준으로 넣는 것이 아닌 ed 기준으로 넣어야 한다는 것 까지는 알았음...
그러나 PQ에 전부 다 넣고 체크하는 것이 아니라 필요한 만큼만 PQ에 넣고 사이즈를 체크하는 것이 더 유리..
+ 최소 힙 구현할 때 -값으로 넣어서 확인하는 방법

*/
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) 
        return a.first < b.first;
    else 
        return a.second < b.second;
}
 

int main(){
    fastio;
    int l, r;
    cin >> N;
    priority_queue<int> pq;
    vector<pair<int, int> > v;

    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;        
        v.push_back({min(l, r), max(l, r)});
    }
    cin >> D;
    int answer = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        int st = v[i].first;
        int ed = v[i].second;
        if(ed - st <= D) pq.push(-st);
        else continue;
        while (!pq.empty())
        {
            if(-pq.top() < ed - D) pq.pop();
            else {answer = max(answer, (int)pq.size()); break;}            
        }
        
    }
    cout << answer;
    
    return 0;
}