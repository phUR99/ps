#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    int l, r;
    cin >> l >> r;
    if (!(l - r))
        cout << "Invalid";
    else if (l - r == -1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
