#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int arr[3];

int main()
{
    fastio;
    char c;
    cin >> c;
    if (c == '<')
    {
        arr[1]++;
    }
    else
        arr[0]++;
    cin >> c;
    if (c == '<')
    {
        arr[2]++;
    }
    else
        arr[0]++;
    cin >> c;
    if (c == '<')
    {
        arr[2]++;
    }
    else
        arr[1]++;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == 1)
        {
            char c = 'A' + i;
            cout << c << '\n';
        }
    }

    return 0;
}
