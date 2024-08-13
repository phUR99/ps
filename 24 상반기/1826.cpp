#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, L, P;
#define dest first
#define fuel second

int main(){
    fastio;
    priority_queue<int> pq;    
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].dest >> v[i].fuel;
    }
    cin >> L >> P;       
    sort(v.begin(), v.end());
    int idx = 0; 
    for (int i = 1; i < L; i++)
    {
        while (idx < v.size() && P >= v[idx].dest)
        {
            pq.push(v[idx].fuel);
            idx++;
        }
        if(i >= P){
            while (!pq.empty())
            {
                P += pq.top(); pq.pop();
                if(P > i) break;
            }            
        }
        if(i >= P) {
            cout << -1;
            return 0;
        }
    }
    /*
    정해: P 전까지의 fuel을 모두 PQ에 넣음.
    이후 하나를 빼서 넣은 후에(가장 큰 원소) 다시 반복...
    PQ가 비었는데도 l > P거나 연료를 넣을 수 없는 경우가 생겼다면 더이상 진행할 수 없는 경우

    while (L > P) {
        while (fuel[idx].first <= P && idx < N)
                pq.push(fuel[idx++].second);
        
        if (!pq.empty()) {
                P += pq.top(), pq.pop();
                cnt++;
        }
        //전부 다 집어넣었는데도 작거나, 다음 인덱스를 집어넣을 수 없다면 -1
        else if (idx == N || fuel[idx].first > P) {
                cnt = -1;
                break;
        }
    }
    */
    cout << N - pq.size();

    return 0;
}