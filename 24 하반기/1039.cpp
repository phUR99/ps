#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
string str;
int k;
/*
1. k번 진행하기
2. 같은 상태는 저장하지 않기
3. set에서 find랑 비슷하게 count 사용가능
*/

int main()
{
    fastio;
    cin >> str >> k;
    queue<string> q;
    q.push(str);
    int ans = -1;
    for (int i = 0; i < k; i++)
    {
        set<string> visited;
        int l = q.size();
        for (int j = 0; j < l; j++)
        {
            auto cur = q.front();
            q.pop();
            if (visited.count(cur))
                continue;
            visited.insert(cur);
            int s = cur.size();
            for (int a = 0; a < s; a++)
            {
                for (int b = a + 1; b < s; b++)
                {
                    if (a == 0 && cur[b] == '0')
                        continue;
                    swap(cur[a], cur[b]);
                    q.push(cur);
                    swap(cur[a], cur[b]);
                }
            }
        }
    }
    while (!q.empty())
    {
        int cur = stoi(q.front());
        q.pop();
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}