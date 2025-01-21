#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, l;
/*
나누는 값이 홀수일 때 : 나머지가 0이면 무조건 만들 수 있음
나누는 값이 짝수일 때 : 나머지가 반드시 l/2여야 함(반대쪽을 전부 +1하는 개념)

*/
int main()
{
    fastio;
    cin >> n >> l;
    for (int i = l; i <= 100; i++)
    {
        int remain = n % i;
        vector<int> arr(i, n / i);
        if (i % 2 == 0)
        {
            if (remain != (i / 2))
                continue;
            for (int j = 1; j + (i - 1) / 2 < i; j++)
            {
                arr[(i - 1) / 2 + j]++;
            }
            for (int j = 1; j + (i + 1) / 2 < i; j++)
            {
                arr[(i - 1) / 2 - j] -= j;
                arr[(i + 1) / 2 + j] += j;
            }
        }
        else
        {
            if (remain != 0)
                continue;
            for (int j = 1; i / 2 - j >= 0; j++)
            {
                arr[i / 2 - j] -= j;
                arr[i / 2 + j] += j;
            }
        }
        if (arr[0] < 0)
            continue;
        for (auto &i : arr)
        {
            cout << i << ' ';
        }
        return 0;
    }
    cout << -1;
    return 0;
}