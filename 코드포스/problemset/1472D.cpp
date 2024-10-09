#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (arr[i] % 2 == 1)
                arr[i] = 0;
            answer += arr[i];
        }
        else
        {
            if (arr[i] % 2 == 0)
                arr[i] = 0;
            answer -= arr[i];
        }
    }
    if (answer > 0)
    {
        cout << "Alice";
    }
    else if (answer == 0)
    {
        cout << "Tie";
    }
    else
    {
        cout << "Bob";
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
