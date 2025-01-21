#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int arr[305];
int n, m;

bool maxSum(int v)
{
    int ret = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > v)
            return false;
        if (sum + arr[i] <= v)
        {
            sum += arr[i];
        }
        else
        {
            ret++;
            sum = arr[i];
        }
    }
    return ret < m;
}

int main()
{
    fastio;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 1;
    int r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (maxSum(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << l << '\n';
    int cnt = 0;
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= l)
        {
            sum += arr[i];
            cnt++;
        }
        else
        {
            sum = arr[i];
            ans.push_back(cnt);
            cnt = 1;
        }
    }
    ans.push_back(cnt);
    /*
    결국 사이즈를 m보다 작게 하는 반환이니 m이 될때까지 찢어야함
    찢은 수가 원래 수보다는 작은 것은 자명함
    */
    while (ans.size() < m)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] > 1)
            {
                ans.insert(ans.begin() + i + 1, ans[i] / 2);
                ans[i] = ans[i] - ans[i] / 2;
                break;
            }
        }
    }
    for (auto &i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}