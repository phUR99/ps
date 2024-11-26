#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int inf = 987654321;
const int V;
/*
capacity : u -> v로 보낼수 있는 용량
flow : u -> v로 흘러가는 유량(반대 방향일 경우 음수로 표현)
*/
vector<vector<int>> capacity, flow;

int networkFlow(int src, int sink)
{
    // flow를 0으로 초기화
    fill(flow.begin(), flow.end(), 0);
    int totalFlow = 0;
    while (1)
    {
        // 너비 탐색을 수행
        vector<int> parent(V, -1);
        queue<int> q;
        parent[src] = src;
        q.push(src);
        // src -> sink간의 경로를 찾을 때까지 BFS를 수행
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 0; there < V; there++)
            {
                // 잔여 용량이 남아 있는 간선을 따라서 탐색하기
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        // 경로를 찾을 수 없다면 종료
        if (parent[sink] == -1)
            break;
        int amount = inf;
        // 각 간선을 검사하면서 그 중에서 최소 잔여 용량을 찾기
        for (int p = sink; p != src; p = parent[p])
        {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        // 각 간선의 유량을 갱신하기(최소 잔여 용량만큼 빼기)
        // 반대 방향의 유량은 줄이는 점
        for (int p = sink; p != src; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}