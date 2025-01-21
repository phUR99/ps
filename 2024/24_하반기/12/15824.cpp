#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. (a% mod) *b != a *b % mod (원소를 mod 연산을 했으면 안됐음)
2. 집합의 개수는 2^n-1개임 (공집합은 제외하므로 전체 집합의 크기 2^n 에서 1을 빼야함)
*/
ll prefix[300005];
ll arr[300005];
const ll mod = 1e9 + 7;
int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll temp = 1;
    for (int i = 0; i < n; i++)
    {
        prefix[i] = temp - 1;
        temp *= 2;
        temp %= mod;
    }
    sort(arr, arr + n);
    ll plus = 0, minus = 0;
    for (int i = 0; i < n; i++)
    {
        plus += arr[i] * prefix[i];
        plus %= mod;
        minus += arr[i] * prefix[n - 1 - i];
        minus %= mod;
    }
    cout << (plus - minus + mod) % mod;

    return 0;
}