#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
1. 트럼프 카드는 조커카드
특이 카드는 제외하고 나머지 카드를 배치하는 방법을 고민하기
전부 배치한 후에 조커 카드를 배치하는 방법을 생각해보자
*/
void solve()
{
    int n;
    cin >> n;
    char t;
    cin >> t;
    string str = "CDHS";

    priority_queue<int, vector<int>, greater<int>> card[4];
    for (int i = 0; i < 2 * n; i++)
    {
        string s;
        cin >> s;
        card[str.find(s[1])].push(s[0] - '0');
    }
    int r = 0, m = card[str.find(t)].size();
    for (int i = 0; i < 4; i++)
    {
        if (str[i] == t)
            continue;
        r += card[i].size() % 2;
    }

    if (r > m || (m - r) % 2)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<string> ans;
    for (int i = 0; i < 4; i++)
    {
        if (str[i] == t)
            continue;
        int size = card[i].size();
        while (!card[i].empty())
        {
            ans.push_back(to_string(card[i].top()) + str[i]);
            card[i].pop();
        }
        if (size % 2 == 1)
        {
            ans.push_back(to_string(card[str.find(t)].top()) + t);
            card[str.find(t)].pop();
        }
    }
    while (!card[str.find(t)].empty())
    {
        ans.push_back(to_string(card[str.find(t)].top()) + t);
        card[str.find(t)].pop();
    }
    for (int i = 0; i < 2 * n; i += 2)
    {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
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
