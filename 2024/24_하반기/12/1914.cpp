#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
big int를 다루는 법
현재 코드에서 스트링 파싱 후 아스키코드 값을 감소시키는 방식이 가능한 이유
-> 2^n -1 = 마지막 자리가 0을 만족하는 경우가 없어서(마지막이 0이 가능하다면 이 방식을 쓸 수가 없음)
*/
void dfs(int num, int from, int by, int to)
{
    if (num == 0)
        return;
    dfs(num - 1, from, to, by);
    cout << from << ' ' << to << '\n';
    dfs(num - 1, by, from, to);
}

int main()
{
    fastio;
    int n;
    cin >> n;
    string a = to_string(pow(2, n));
    a = a.substr(0, a.find('.'));
    a[a.length() - 1] -= 1;
    cout << a << '\n';
    if (n <= 20)
        dfs(n, 1, 2, 3);
    return 0;
}