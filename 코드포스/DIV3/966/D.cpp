#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n;
    cin >> n;
    vector<long long> pSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        pSum[i] = tmp + pSum[i - 1];
    }
    queue<int> L;
    stack<int> R;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
            L.push(i + 1);
        else
            R.push(i + 1);
    }
    long long answer = 0;
    while (!L.empty() && !R.empty())
    {
        if (L.front() > R.top())
        {
            R.pop();
            continue;
        }
        int l = L.front();
        L.pop();
        int r = R.top();
        R.pop();
        answer += pSum[r] - pSum[l - 1];
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
