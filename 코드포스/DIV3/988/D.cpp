#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
작은 수를 버리는게 아니라
큰 수를 사용하는 식으로(반드시 사용해야 하는 수를 체크 가능)
*/
void solve()
{
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<ll, ll>> hurdle(n);

    queue<pair<int, int>> powerUp;
    for (auto &i : hurdle)
    {
        cin >> i.first >> i.second;
    }
    for (int i = 0; i < m; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        powerUp.push(tmp);
    }

    priority_queue<ll> remain;
    ll ret = 0;
    ll pow = 1;
    for (auto h : hurdle)
    {
        ll l = h.first;
        ll r = h.second;
        while (!powerUp.empty() && powerUp.front().first < l)
        {
            remain.push(powerUp.front().second);
            powerUp.pop();
        }
        while (!remain.empty() && pow < r - l + 2)
        {
            pow += remain.top();
            ret++;
            remain.pop();
        }
        if (pow < r - l + 2)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ret << '\n';
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