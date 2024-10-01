#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, a, b, c;
int cache[4005];
/*
DP 접근

*/
int main()
{
    fastio;
    cin >> n >> a >> b >> c;
    vector<int> arr = {a, b, c};
    sort(arr.begin(), arr.end());

    for (int i = 0; i <= n; i++)
    {
        for (int piece : arr)
        {
            // 특정 조각으로 전부 나눌 수 있다면
            if (i % piece == 0)
            {
                cache[i] = max(cache[i], i / piece);
            }
            else
            {
                if (cache[i] == 0)
                    continue;
                if (i + piece <= n)
                {
                    cache[i + piece] = max(cache[i + piece], cache[i] + 1);
                }
            }
        }
    }
    cout << cache[n] << '\n';

    return 0;
}
