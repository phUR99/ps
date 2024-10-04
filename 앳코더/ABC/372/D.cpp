#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int arr[200005];
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        ans.push_back(s.size());
        while (!s.empty() && s.top() < arr[i])
        {
            s.pop();
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}
