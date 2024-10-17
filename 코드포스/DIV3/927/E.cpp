#include <bits/stdc++.h>
#define long long long int
#define DEBUG
using namespace std;
/*
1.
123을 예시로 할 때
1은 23에 영향을, 2는 3에 영향을 준다.
ans 136
누적합을 이용해서 각 자릿수마다 영향을 주는 횟수를 센 후에(136)
이를 뒤집어서 carry가 생기는 지에 대한 여부를 확인

*/
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    a[0] = s[0] - '0';
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + (s[i] - '0');
    }
    reverse(a.begin(), a.end());
    string ret;
    int nn = 0;
    for (int i = 0; i < n; i++)
    {
        nn += a[i];
        ret += (nn % 10) + '0';
        nn /= 10;
    }
    ret += nn + '0';
    while (ret.back() == '0')
    {
        ret.pop_back();
    }
    reverse(ret.begin(), ret.end());
    cout << ret << '\n';
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}