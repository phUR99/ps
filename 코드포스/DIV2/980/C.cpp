#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
합의 오름차순으로 배열하는 게 이득임
답을 구했을 때 인접 배열을 생각
왼쪽 원소의 합이 오른쪽 원소의 합보다 큰 경우 위치를 바꿔도 답에는 차이가 없음
계속 바꾸면서 두 합이 오름차순을 이루게 만드는 것이 최적의 답임
*/
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first + a.second < b.first + b.second;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first << " " << arr[i].second << " ";
    }
    cout << '\n';
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
