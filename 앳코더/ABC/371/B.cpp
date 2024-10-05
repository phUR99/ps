#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, m;

int main()
{
    fastio;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        if (arr[a] != 0 || b == 'F')
        {
            cout << "No\n";
            continue;
        }
        arr[a] = 1;
        cout << "Yes\n";
    }

    return 0;
}
