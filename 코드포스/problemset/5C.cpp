#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    string str;
    cin >> str;
    stack<int> s;
    vector<int> dp(str.size(), 0);
    int maxLength = 0, count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else
        {
            if (!s.empty())
            {
                int openIndex = s.top();
                s.pop();
                dp[i] = i - openIndex + 1;

                if (openIndex > 0)
                {
                    dp[i] += dp[openIndex - 1];
                }
                if (dp[i] > maxLength)
                {
                    maxLength = dp[i];
                    count = 1;
                }
                else if (dp[i] == maxLength)
                {
                    count++;
                }
            }
        }
    }

    if (maxLength == 0)
        cout << 0 << ' ' << 1;
    else
        cout << maxLength << ' ' << count;

    return 0;
}
