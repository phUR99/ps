#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define MAX 1000 + 5
int counter = 0;     // 노드의 발견 순서 체크
int discovered[MAX]; // 노드의 탐색 여부 체크
bool curVertex[MAX]; // 노드의 단절점 여부 체크
vector<vector<int>> adj;

int dfs(int node, bool isRoot)
{
    // 현재 노드 탐색 표시
    discovered[node] = counter++;
    int ret = discovered[node];
    // 루트 노드일 때 자식의 개수를 체크하기 위한 값
    // 루트 노드일 때는 단절점의 조건을 만족해도 단절점이 아닐 수 있음
    int children = 0;

    for (auto child : adj[node])
    {
        children++;
        /*
        탐색하지 않았다면 자식 노드 중에서 최소의 discovered 값을 확인한다.
        무향 그래프에서는 교차 간선이 존재할 수 없으므로(순방향 or 역방향)
        서브트리끼리는 연결되지 않는다.
        */
        if (discovered[child] == -1)
        {
            int subTree = dfs(child, false);
            // 현재 노드보다 크거나 같다면, 현재 노드를 제거했을 때 부모 노드로 갈 수 없다.
            if (!isRoot && subTree >= ret)
                curVertex[node] = true;
            ret = min(ret, subTree);
        }
        // 탐색했다면 값만 체크한다.
        // 루트일 때는 참고하는 값이 없고
        // 서브트리로 들어가야만 의미가 생기는 코드
        else
            ret = min(ret, discovered[child]);
    }
    // 루트노드일 경우 자식 노드가 2개 이상이어야 절단점이 될 수 있다.
    if (isRoot)
        curVertex[node] = (children >= 2);
    return ret;
}

void solve()
{
    int v;
    memset(discovered, -1, sizeof(discovered));
    for (int vertex = 1; vertex <= v; vertex++)
    {
        // 탐색하지 않은 모든 정점에 대해서 DFS를 실행한다.
        if (discovered[vertex] == -1)
            dfs(vertex, true);
    }
}

int main()
{
    fastio;

    return 0;
}