#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*

O(nlgn)    알고리즘 X
-> 대신 생각을 해보면
a*b <=2n 조건에 따라서 계산해야하는 원소의 개수가 지수적으로 감소하는 것을 알 수 있음
1 -> 2n...
2 -> n...
4 -> n/2...
n * 조화급수 -> O(NlgN) 유도 가능
*/

void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].first * arr[j].first > 2 * n)
                break;
            answer += (arr[i].second + arr[j].second == arr[i].first * arr[j].first);
        }
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
