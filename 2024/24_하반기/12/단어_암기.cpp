#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int full_bit = (1 << 26) - 1;
int word[10005];
int n, m;
int makeBit(string &str)
{
    int ret = 0;
    for (char &c : str)
    {
        ret |= 1 << (c - 'a');
    }
    return ret;
}
int solve()
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        // full_bit랑 & 연산시 동일하게 남아있는 지를 확인해야함
        if (word[i] == (word[i] & full_bit))
            ret++;
    }
    return ret;
}
int main()
{
    fastio;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        word[i] = makeBit(str);
    }
    for (int i = 0; i < m; i++)
    {
        int command;
        char c;
        cin >> command >> c;
        if (command == 1)
            // NOT 주의(bitwise not VS logically not)
            full_bit &= ~(1 << (c - 'a'));
        else
            full_bit |= (1 << (c - 'a'));
        // 이진 출력
        // cout << bitset<26>(full_bit) << ' ';
        int ret = solve();
        cout << ret << '\n';
    }

    return 0;
}