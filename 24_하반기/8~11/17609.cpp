#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
string str;

bool check1(int size)
{
    bool ret = false;
    int l = 0;
    int r = size - 1;
    for (int i = 0; i < size / 2; i++)
    {
        if (str[l] != str[r])
            return ret = false;
        l++;
        r--;
    }
    return true;
}
bool check2(int size)
{
    int i = 0;
    for (; i < size / 2; i++)
    {
        if (str[i] != str[size - 1 - i])
            break;
    }
    int l = i + 1;
    int r = size - 1 - i;
    bool ret = false;
    bool left = true, right = true;
    while (l < r)
    {
        if (str[l] != str[r])
        {
            left = false;
            break;
        }
        l++;
        r--;
    }
    l = i;
    r = size - 1 - i - 1;
    while (l < r)
    {
        if (str[l] != str[r])
        {
            right = false;
            break;
        }
        l++;
        r--;
    }
    return ret = left || right;
}

void solve()
{
    cin >> str;
    int n = str.size();
    if (check1(n))
    {
        cout << 0 << '\n';
        return;
    }
    if (check2(n))
    {
        cout << 1 << '\n';
        return;
    }

    cout << 2 << '\n';
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