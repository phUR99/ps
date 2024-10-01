#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
string str;
int num[3], ord[3], pri[3];
#define ll long long
ll tot;
/*
이분탐색 아이디어 -> 생각 못했음

-> x의 햄버거를 만들기 위해서 재료가 얼마나 필요하는가?
최댓값 x를 결정하는 문제로 바꾸기

*/

int main()
{
    fastio;
    cin >> str;
    for (auto i : str)
    {
        if (i == 'B')
            num[0]++;
        else if (i == 'S')
            num[1]++;
        else
            num[2]++;
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> ord[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> pri[i];
    }
    cin >> tot;

    ll l = 0;
    ll r = 1e15;

    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll cost = 0;
        for (int i = 0; i < 3; i++)
        {
            cost += max(0LL, -(ll)ord[i] + mid * (ll)num[i]) * (ll)pri[i];
        }
        if (cost <= tot)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r;

    return 0;
}
