#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// 다익스트라 O(ElogV) -> PQ 사용 필요
long long dist[100005];
// long long ? : 최악의 경우 int32 넘어가는 경우가 생김 
// 일렬로 100000개 + 내림차순 700000 * 100000 -> 10^10 넘어가는 경우
const long long inf = 0x7fffffffffffffff;

vector<pair<int, long long>> adj[100005];
struct node
{
    int to;
    long long cost;
    bool operator< (const node &a) const {
        return a.cost < cost;
    }
};
priority_queue<node> pq;
int n;
long long m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from ,to;
        cin >> from >> to;
        adj[from].push_back({to, i+1});
        adj[to].push_back({from, i+1});
    }    
    fill(dist+1, dist+100005, inf);
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.to] < cur.cost) continue;
        for (auto nxt : adj[cur.to])
        {
            long long cost = nxt.second;
            /*
            숫자가 너무 커서 이런식으로 하면 시간초과 발생
            while (cur.cost >= cost)
            {
                cost += m;
            }  
            */
           // 몫 확인 + cost의 나머지가 nxt보다 더 크면 다음 주기로 넘어가야함.
           cost += (cur.cost/m + (cur.cost % m > nxt.second))*m;

            if(dist[nxt.first] > cost){
                dist[nxt.first] = cost;
                pq.push({nxt.first, cost});
            }
        }
        
    }
    cout << dist[n];


    return 0;    
}