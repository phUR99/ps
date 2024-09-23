#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int arr[3005];
int pSum[3005];
int t, s;
int n;
int cache[3005];

int solve(int l, int r)
{
    int m = (l + r + 1) / 2;
    // mid 값 기준으로 편차값의 합의 최솟값 찾기
    return t * ((m - l) * arr[m] - (r - m) * arr[m] + (pSum[l] - pSum[m]) + (pSum[r] - pSum[m]));
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pSum[i] = pSum[i - 1] + arr[i];
    }
    cin >> t >> s;
    /*
    N^2 -> 이전 값을 탐색하면서 헬기를 타는 것이 이득인지를 찾기
    */
    for (int i = 1; i <= n; i++)
    {
        cache[i] = cache[i - 1] + t * arr[i];
        for (int j = 0; j < i; j++)
        {
            cache[i] = min(cache[i], cache[j] + s + solve(j, i));
        }
    }
    cout << cache[n];

    return 0;
}