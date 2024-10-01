#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 8로 나눠지는지의 여부는 마지막 3자리만 보고 파악 가능함
2. 균일하게 3자리씩 관찰을 하기 위해서 str의 앞자리에 "00"을 집어넣은 것을 유의깊게 보자

*/

int main()
{
    fastio;
    string str;
    cin >> str;
    str = "00" + str;
    int n = str.length();
    int now = 0;
    for (int i = 0; i < n - 2; i++)
    {
        now += 100 * (str[i] - '0');
        for (int j = i + 1; j < n - 1; j++)
        {
            now += 10 * (str[j] - '0');
            for (int k = j + 1; k < n; k++)
            {
                now += str[k] - '0';
                if (now % 8 == 0)
                {
                    cout << "YES\n";
                    cout << now;
                    return 0;
                }
                now -= str[k] - '0';
            }
            now -= 10 * (str[j] - '0');
        }
        now -= 100 * (str[i] - '0');
    }
    cout << "NO\n";
    return 0;
}
