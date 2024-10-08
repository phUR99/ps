#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
최댓값의 최솟값을 어떻게 만들꺼?
0, 2일 경우 -> /2로 나눈 값
1 일 경우 -> 하나는 0, 하나는  1
제일 큰값에다 1 배정하고 작은쪽에서 다 가져가는게 최소
*/
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string A(n, '0'), B(n, '0');
    for (int i = 0; i < n; i++)
    {
        if (str[i] - '0' == 1)
        {
            A[i] = '1';
            B[i] = '0';
            for (int j = i + 1; j < n; j++)
            {
                B[j] = str[j];
            }
            break;
        }
        else
        {
            A[i] = B[i] = (str[i] - '0') / 2 + '0';
        }
    }
    cout << A << '\n'
         << B << '\n';
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
