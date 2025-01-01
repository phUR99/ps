#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
배낭 + 소수 판정
특이사항
같은 값은 한번만 세야함 -> 인덱스당 한번만 탐색하는 방식으롸
무게 0이 포함되어있음 -> 0 을 어떻게 적용할까 고민해보자
0이 K개 있을 때 소수인 값에 더하는 과정은
-> 0을 0개.. 1개.. 2개.. K개 총 K+1개
따라서, 0을 제외하고 배열을 구성한 다음에 총 합에 0의 개수만큼을 곱해준다
1. 0을 처리하는 방식
2. 같은 값은 한번만 처리하는 방식

*/
bool isPrime[500005];
int num[10005];
vector<pair<int, int>> arr;
ll cache[500005];

void precalc()
{
    fill(isPrime, isPrime + 500005, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 500000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 500000; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    fastio;
    precalc();
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        num[idx]++;
        sum += idx;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (num[i])
            arr.push_back({i, num[i]});
    }
    int zero = num[0] + 1;
    cache[0] = 1;

    for (auto cur : arr)
    {
        int v = cur.first;
        int c = cur.second;
        for (int i = sum; i >= 0; i--)
        {
            for (int j = 1; j <= c && i - j * v >= 0; j++)
            {
                cache[i] += cache[i - j * v];
            }
        }
    }
    ll ret = 0;
    for (int i = 2; i <= sum; i++)
    {
        if (isPrime[i])
            ret += cache[i];
    }
    cout << ret * (ll)zero;

    return 0;
}