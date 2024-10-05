#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int arr[105][105];

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    int m = 1;
    for (int i = 1; i <= n; i++)
    {
        int c = i;
        if (c <= m)
            swap(c, m);
        m = arr[c][m];
    }
    cout << m;

    return 0;
}
