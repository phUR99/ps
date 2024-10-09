#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 차이가 최소 && 오름차순의 최대
-> 차이가 최소인 두 원소를 구하는데 집중..
차이에 대해서는 고민해봤지만.. 최대 오름차순에서는 생각 X
-> 두 조건을 같이 생각하려니까 안된다.
-> 하나를결정한 다음에 다음거를 또 결정하자

*/
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int r = -1;
    int d = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] < d)
        {
            d = arr[i] - arr[i - 1];
            r = i;
        }
    }
    cout << arr[r - 1] << ' ';
    for (int i = r + 1; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    for (int i = 0; i < r - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << arr[r] << ' ';
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
