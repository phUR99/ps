#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
map<string, int> arr;
int n;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (!arr.count(str))
        {
            arr[str]++;
            cout << "OK\n";
        }
        else
        {
            cout << str + to_string(arr[str]++) << '\n';
        }
    }

    return 0;
}
