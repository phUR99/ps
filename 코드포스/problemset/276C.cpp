#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
int n, q;
ll freq[200005];
/*
L-R 누적합 테크닉 + 그리디
1. 특정 구간이 몇번 등장하는 지에 대한 빈도를 구해야함 -> 주어진 l ~ R 구간에 1씩 더하면 O(n^2) -> TLE
2. 따라서 끝 지점에만 표시하고 넘어가는 방식으로 빈도를 표시한 뒤에 전체 구간을 탐색하면서 빈도를 파악
-> 누적합
3. 많은 빈도 * 큰 숫자 -> 그리디
4. r이 아닌 r+1에 -1

*/

int main()
{
    fastio;
    cin >> n >> q;
    vector<ll> arr(n), rat;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll ans = 0;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += freq[i];
        rat.push_back(cur);
    }
    sort(arr.begin(), arr.end());
    sort(rat.begin(), rat.end());
    for (int i = 0; i < n; i++)
    {
        ans += rat[i] * arr[i];
    }

    cout << ans;

    return 0;
}
