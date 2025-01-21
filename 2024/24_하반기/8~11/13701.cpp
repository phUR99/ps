#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
비트셋
*/

bitset<1 << 25> BT;

int main()
{
    fastio;
    int num;
    while (cin >> num)
    {
        if (BT[num])
            continue;
        BT[num] = 1;
        cout << num << ' ';
    }

    return 0;
}