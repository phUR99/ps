#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

/*
1. 특별한 이유 없으면 인덱스는 맞춰서 쓰자
2. 아이디어
-> 고민 1. 가장 긴 수열 만들기...(n / 비용으로 가장 긴 수열 ok)
-> 고민 2. 가장 긴 수열일 때, 가장 큰 수 만들기...(어떻게?)
-> 가장 긴 수열을 만든 다음에, 9부터 내려가면서 바꿀 수 있는지를 체크 -> 그리디하게 풀이
*/
int main()
{
    fastio;
    int n;
    vector<int> arr(10);
    vector<int> ans;
    cin >> n;
    int len = 0;
    for (int i = 1; i <= 9; i++)
    {
        cin >> arr[i];
        if (len < n / arr[i])
        {
            len = max(len, n / arr[i]);
            ans.clear();
            ans.resize(len, i);
        }
    }
    if (!len)
    {
        cout << -1;
        return 0;
    }

    int remain = n - len * arr[ans[0]];
    for (int i = 0; i < len; i++)
    {
        for (int j = 9; j > ans[i]; j--)
        {
            if (remain - arr[j] + arr[ans[i]] < 0)
                continue;
            remain -= arr[j] - arr[ans[i]];
            ans[i] = j;
            break;
        }
    }
    for (auto e : ans)
    {
        cout << e;
    }

    return 0;
}
