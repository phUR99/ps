#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. 입출력에 대한 처리 cin >> n >> m 을 while 구문에 적을 경우
잘못된 입력이 들어왔을 경우 false를 반환함


1. 조건 1 : 2-SAT을 만족시키는가 ?
2. 조건 2 : 1이 참이 되는 경우가 있는가?
두 조건을 만족시키기 위해서 그래프 모델링을 생각해보기
1번 식에 &&(1 || 1) 조건을 추가로 달아주는 형태로 그래프를 조작
(1 || 1) 조건 !1 -> 1 간선을 달아줌으로써 해결 가능함

*/

int n, m;
vector<pair<int, int>> clauses;
vector<vector<int>> adj;
void makeLine(int l, int r)
{
    int l_true = (l < 0) ? (abs(l) - 1) * 2 + 1 : (abs(l) - 1) * 2;
    int l_false = l_true ^ 1;
    int r_true = (r < 0) ? (abs(r) - 1) * 2 + 1 : (abs(r) - 1) * 2;
    int r_false = r_true ^ 1;
    adj[l_false].push_back(r_true);
    adj[r_false].push_back(l_true);
}

void makeGraph()
{
    adj.clear();
    adj.resize(2 * n);
    for (const auto &clause : clauses)
    {
        makeLine(clause.first, clause.second);
    }
    makeLine(1, 1);
}
int dfs(int here);
vector<int> group, discovered;
int counter = 0, sccCounter = 0;
stack<int> s;
vector<int> SCC()
{
    int n = adj.size();
    group.clear();
    discovered.clear();
    group.resize(n, -1);
    discovered.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == -1)
            dfs(i);
    }
    return group;
}
int dfs(int here)
{
    int ret = discovered[here] = counter++;
    s.push(here);
    for (auto &there : adj[here])
    {
        if (discovered[there] == -1)
            ret = min(ret, dfs(there));
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
void solve()
{
    clauses.resize(m);
    for (auto &clause : clauses)
    {
        cin >> clause.first >> clause.second;
    }
    makeGraph();
    vector<int> ret = SCC();
    for (int i = 0; i < adj.size(); i += 2)
    {
        if (group[i] == group[i + 1])
        {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main()
{
    fastio;
    while (cin >> n >> m)
    {
        solve();
    }

    return 0;
}