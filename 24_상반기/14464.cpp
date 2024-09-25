#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int T[20005];
pair<int, int> AB[20005];
int C, N;


int main(){
    fastio;
    cin >> C >> N;
    for (int i = 0; i < C; i++)
    {
        cin >> T[i];
    }
    priority_queue<pair<int, int>> pq;
    sort(T, T+C, greater<>());
    for (int i = 0; i < N; i++)
    {
        cin >> AB[i].first >> AB[i].second;
        pq.push({AB[i].second, AB[i].first});
    }
    int ans = 0;
    for (int i = 0; i < C; i++)
    {
        if(pq.empty()) break;
        if(pq.top().first < T[i]) continue;
        if(pq.top().second <= T[i]) {
            ans++;
            pq.pop();
        }

    }
    sort(T, T+C);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> gpq;
    for (int i = 0; i < N; i++)
    {
        gpq.push({AB[i].second, AB[i].first});
    }
    int cnt = 0;
    for (int i = 0; i < C; i++)
    {
        if(gpq.empty()) break;
        if(gpq.top().first < T[i]) continue;
        if(gpq.top().second <= T[i]) {
            cnt++;
            gpq.pop();
        }

    }
    ans = max(ans, cnt);
    cout << ans;
    
    

    return 0;
}