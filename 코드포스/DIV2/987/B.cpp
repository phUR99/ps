#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
왼쪽이 정렬이 되었고, 오른쪽이 정렬이 된 상태를 가정
1 2 vs 3 4
바꿔야 하는 왼쪽 원소는 1 ~ i까지 최대, 바꿔야 하는 오른쪽 원소는 i+1 ~ N까지 최소를 항상 만족
이 조건에서 둘의 차이가 1보다 크다면 정렬을 더이상 할 수 없음
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
    vector<int> MX(n), MN(n);
    MX[0] = arr[0];
    MN[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        MX[i] = max(MX[i - 1], arr[i]);
        MN[i] = min(MX[i - 1], arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (MX[i - 1] - MN[i] > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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