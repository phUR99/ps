#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int m, s;
    cin >> m >> s;
    vector<int> largest(m, 0), smallest(m, 0);
    int sum = s;
    if (m == 1 && s == 0)
    {
        cout << "0 0";
        return;
    }
    if (sum / 9 + (sum % 9 != 0) > m || sum == 0)
    {
        cout << "-1 -1";
        return;
    }
    int idx = 0;
    while (sum > 0)
    {

        for (int i = 9; i >= 0; i--)
        {
            if (sum < i)
                continue;
            largest[idx++] = i;
            sum -= i;
            break;
        }
    }
    string large, small;
    sort(largest.begin(), largest.end(), greater<>());
    for (auto l : largest)
    {
        large += l + '0';
    }
    sort(largest.begin(), largest.end());
    if (largest[0] == 0)
    {
        for (auto &i : largest)
        {
            if (i == 0)
                continue;
            largest[0]++;
            i--;
            break;
        }
    }
    for (auto l : largest)
    {
        small += l + '0';
    }
    cout << small << ' ' << large;
}

int main()
{
    fastio;
    solve();

    return 0;
}
