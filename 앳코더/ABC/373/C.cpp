#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    int A = -1e9 - 1;
    int B = -1e9 - 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        A = max(tmp, A);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        B = max(tmp, B);
    }
    cout << A + B;
    return 0;
}
