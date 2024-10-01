#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prop(2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= 2;
        prop[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (prop[arr[i]] == 1)
        {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}
