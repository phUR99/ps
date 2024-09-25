#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int N;
vector<vector<int>> adj;
/*
분할의 아이디어 -> 전체를 생각하기 어렵다면 단순한 경우 하나로
자식으로 이루어진 서브트리의 결과를 모두 알고 있다면 그 결과를 내림차순 정렬한 뒤에
하나씩 체크하면서 최댓값을 줄이는 방식으로
*/

int solve(int cur)
{
    vector<int> tmp;
    for (auto nxt : adj[cur])
    {
        int now = solve(nxt);
        tmp.push_back(now);
    }
    sort(tmp.begin(), tmp.end(), greater<>());
    int ret = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        ret = max(ret, tmp[i] + i);
    }
    return ret + 1;
}

int main()
{
    fastio;
    cin >> N;
    adj.resize(N);
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        if (v == -1)
            continue;
        adj[v].push_back(i);
    }
    int answer = solve(0);
    cout << answer - 1;
    return 0;
}