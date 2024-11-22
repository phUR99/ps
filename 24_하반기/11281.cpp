#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> clauses;
vector<vector<int>> adj;
int n, m;
vector<int> discovered, group;

void makeLine(int l, int r)
{
    int l_true = (l < 0) ? (abs(l) - 1) * 2 + 1 : (abs(l) - 1) * 2;
    int l_false = l_true ^ 1;
    int r_true = (r < 0) ? (abs(r) - 1) * 2 + 1 : (abs(r) - 1) * 2;
    int r_false = r_true ^ 1;
    // adj[l_true].push_back(r_false);
    // adj[r_true].push_back(l_false);
    adj[l_false].push_back(r_true);
    adj[r_false].push_back(l_true);
}

void makeGraph(vector<pair<int, int>> &clauses)
{
    adj.resize(2 * n);
    for (auto clause : clauses)
    {
        int left = clause.first;
        int right = clause.second;
        makeLine(left, right);
    }
}
int counter = 0, sccCounter = 0;
stack<int> s;

int dfs(int here)
{
    int ret = discovered[here] = counter++;
    s.push(here);
    for (const int &there : adj[here])
    {
        if (discovered[there] == -1)
            ret = min(ret, dfs(there));
        // 아직 함수가 종료하지 않았다면 there은 here보다 먼저 등장했다
        // 역방향 간선
        else if (group[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if (ret == discovered[here])
    {
        while (1)
        {
            int now = s.top();
            group[now] = sccCounter;
            s.pop();
            if (now == here)
                break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> SCC()
{
    int n = adj.size();
    group.resize(n, -1);
    discovered.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == -1)
            dfs(i);
    }
    return group;
}
int main()
{
    fastio;
    cin >> n >> m;
    clauses.resize(m);

    for (auto &clause : clauses)
    {
        cin >> clause.first >> clause.second;
    }
    makeGraph(clauses);
    vector<int> ret = SCC();

    for (int i = 0; i < adj.size(); i += 2)
    {
        if (ret[i] == ret[i + 1])
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    vector<pair<int, int>> order;
    vector<int> value(adj.size() / 2, -1);
    for (int i = 0; i < ret.size(); i++)
    {
        order.push_back({-ret[i], i});
    }
    sort(order.begin(), order.end());
    // 위상정렬의 순서를 확인할 때 먼저 등장한 논리값이 반드시 참이어야함
    for (auto &i : order)
    {
        int vertex = i.second;
        int var = vertex / 2, isTrue = (vertex % 2 == 0);
        if (value[var] != -1)
            continue;
        value[var] = !isTrue;
    }
    for (auto &i : value)
    {
        cout << i << ' ';
    }

    return 0;
}