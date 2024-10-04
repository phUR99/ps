#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (str[i - 1] == 'A' && str[i] == 'B' && str[i + 1] == 'C')
            cnt++;
    }

    for (int i = 0; i < q; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        a--;
        if (str[a] == c)
        {
            cout << cnt << '\n';
            continue;
        }
        if (str[a] == 'A')
        {
            if (n - 1 >= a + 2 && str[a + 1] == 'B' && str[a + 2] == 'C')
                cnt--;
        }
        else if (str[a] == 'B')
        {
            if (a != 0 && a != n - 1 && str[a - 1] == 'A' && str[a + 1] == 'C')
                cnt--;
        }
        else if (str[a] == 'C')
        {
            if (a - 2 >= 0 && str[a - 2] == 'A' && str[a - 1] == 'B')
                cnt--;
        }
        str[a] = c;
        if (str[a] == 'A' && a + 2 <= n - 1)
        {
            if (str[a + 1] == 'B' && str[a + 2] == 'C')
                cnt++;
        }
        else if (str[a] == 'B' && a != 0 && a != n - 1)
        {
            if (str[a - 1] == 'A' && str[a + 1] == 'C')
                cnt++;
        }
        else if (str[a] == 'C' && a - 2 >= 0)
        {
            if (str[a - 2] == 'A' && str[a - 1] == 'B')
                cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}
