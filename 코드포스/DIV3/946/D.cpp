#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string answer(n, 'R');
    unordered_map<char, char> inv = {{'S', 'N'},
                                     {'N', 'S'},
                                     {'W', 'E'},
                                     {'E', 'W'}};

    int r = 0,
        c = 0;
    for (auto &i : str)
    {
        if (i == 'S')
            r--;
        if (i == 'N')
            r++;
        if (i == 'W')
            c--;
        if (i == 'E')
            c++;
    }
    if (r % 2 != 0 || c % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    if (r == 0 && c == 0)
    {
        if (n == 2)
        {
            cout << "NO\n";
            return;
        }
        answer[0] = answer[str.find(inv[str[0]])] = 'H';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'N' && r > 0)
            {
                answer[i] = 'H';
                r -= 2;
            }
            if (str[i] == 'S' && r < 0)
            {
                answer[i] = 'H';
                r += 2;
            }
            if (str[i] == 'W' && c < 0)
            {
                answer[i] = 'H';
                c += 2;
            }
            if (str[i] == 'E' && c > 0)
            {
                answer[i] = 'H';
                c -= 2;
            }
        }
    }
    cout << answer << '\n';
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
