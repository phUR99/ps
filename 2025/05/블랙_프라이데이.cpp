#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[5005];
int n, c;
int main()
{
    fastio;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (binary_search(arr, arr + n, c))
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (binary_search(arr + i + 1, arr + n, c - arr[i]))
        {
            cout << 1;
            return 0;
        }
    }
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (binary_search(arr + i + 1, arr + j, c - sum))
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}