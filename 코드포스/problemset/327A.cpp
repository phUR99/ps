#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
Kadane's Algorithm : 최대합을 가지는 부분수열을 구하는 알고리즘 O(N)
if i >= 0 : maxValue = max(arr[i], arr[i]+ pSum[i-1]) else : arr[i];

이 문제에 적용하는 방법:
관찰 : 전체 1의 개수에서 반전시켰을 때 추가되는 1의 개수를 더해주자
-> 전체 1의 개수를 센다
-> 이후 1에는 -1, 0에는 1을 마스킹한 배열을 만든다.
-> 배열의 최대 부분합을 구한다.
answer : 최대 부분합 + 기존 1의 개수
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int total = 0;
    for (auto &i : arr)
    {
        cin >> i;
        total += i;
    }
    if (total == n)
    {
        cout << n - 1;
        return;
    }
    for (auto &i : arr)
    {
        if (i == 1)
            i = -1;
        else
            i = 1;
    }
    int sum = arr[0];
    int M = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(arr[i], sum + arr[i]);
        M = max(sum, M);
    }
    cout << total + M << '\n';
}

int main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
