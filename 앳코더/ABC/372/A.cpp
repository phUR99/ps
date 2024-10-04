#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    string str;
    cin >> str;
    for (auto &i : str)
    {
        if (i == '.')
            continue;
        cout << i;
    }

    return 0;
}
