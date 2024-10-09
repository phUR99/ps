#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
증가하다 감소하는 구조가 단 한번만 나와야한다는 사실을 파악하지 못했음
-> 예제를 풀어보면서 좀 규칙을 파악해봐야할듯
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int ans = n - 1;
    while (ans > 0 && arr[ans - 1] - arr[ans] >= 0)
        ans--;
    while (ans > 0 && arr[ans - 1] - arr[ans] <= 0)
        ans--;
    cout << ans << '\n';
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
