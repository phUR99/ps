#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int m;
/*
3진법으로 만드는거 고민해보기
*/

int main()
{
    fastio;
    cin >> m;
    vector<int> n;
    while (m)
    {
        int cnt = 0;
        int now = 1;
        while (m >= 3 * now)
        {
            now *= 3;
            cnt++;
        }
        m -= now;
        n.push_back(cnt);
    }
    cout << n.size() << '\n';
    for (auto i : n)
    {
        cout << i << ' ';
    }

    return 0;
}
