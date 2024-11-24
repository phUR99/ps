#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
vector<vector<pair<int, int>>> adj;
int V;
const int INF = 0x3f3f3f3f;
vector<int> bellmanFord(int src)
{
    // 시작점을 제외한 모든 정점까지의 최단거리 상한을 INF로 설정함
    vector<int> upper(V, INF);
    upper[src] = 0;

    bool updated;
    for (int iter = 0; iter < V; iter++)
    {
        updated = false;
        for (int here = 0; here < V; here++)
        {
            for (auto nxt : adj[here])
            {
                int there = nxt.second;
                int cost = nxt.first;
                // here -> there 간선을 따라서 완화를 시도
                if (upper[here] + cost < upper[there])
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        // 모든 간선에 대해서 완화가 실패했을 경우 실행 종료
        if (!updated)
            break;
    }
    // V번째 순회에서도 순회가 성공했을 경우 음수 사이클이 존재
    if (updated)
        upper.clear();
    return upper;
}
