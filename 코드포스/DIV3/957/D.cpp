#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s = 'L' + s + 'L';
        vector<int> dp(n + 2, -1);
        dp[0] = k; // 남은 이동횟수
        for (int i = 1; i <= n + 1; i++)
        {
            // 악어면 pass
            if (s[i] == 'C')
                continue;
            // m <=10이니까... 충분히 가능
            // 이전 값을 확인하면서 남은 이동횟수 중에서 최대를 가져옴
            for (int t = 1; t <= m; t++)
                if (i - t >= 0 && s[i - t] == 'L')
                    dp[i] = max(dp[i], dp[i - t]);
            // 이전 값이 W면(그 전은 생각할 필요 없음)
            if (s[i - 1] == 'W')
                dp[i] = max(dp[i], dp[i - 1] - 1);
        }
        // 0보다 작으면 k번으로 올수 없음
        if (dp[n + 1] >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}