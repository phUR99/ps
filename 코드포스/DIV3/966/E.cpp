#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, k, m;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    int w;
    cin >> w;
    vector<int> weight(w);
    for (int i = 0; i < w; i++)
    {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end(), greater<>());
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < m - k + 1; j++)
        {
            for (int m = 0; m < k; m++)
            {
                for (int l = 0; l < k; l++)
                {
                    grid[i + m][j + l]++;
                }
            }
        }
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pq.push(grid[i][j]);
        }
    }
    long long answer = 0;
    for (int i = 0; i < w; i++)
    {
        long long cur = pq.top();
        pq.pop();
        long long now = weight[i];
        answer += now * cur;
    }
    cout << answer << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
