#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
5 4 3 2 1
바꿔도 되지 않는 수를 계산
1

*/
void solve()
{
    vector<int> arr;
    vector<int> cnt;
    int n;
    cin >> n;
    arr.resize(n, 0);
    cnt.resize(n + 1, 0);
    for (auto &i : arr)
    {
        cin >> i;
    }
    for (auto i : arr)
    {
        cnt[i]++;
    }
    cout << n - *max_element(cnt.begin(), cnt.end()) << '\n';
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