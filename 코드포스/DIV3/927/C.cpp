#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
아이디어
1. 숫자가 너무 크다. -> 전부 곱해서 확인할 수 없음
그렇다고 곱할때 마다 모듈러 연산을 하면 나중에 복원할 수가 없음
2. 뒤집자
뒤집어서 하면 매 쿼리마다 모듈러 연산을 해도 결과가 달라지지 않음.
투포인터 or 덱을 이용해서 숫자가 빠지는 순서를 기록한 뒤 역순으로 계산한다.

*/
void solve()
{
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        dq.push_back(tmp);
    }
    string str;
    cin >> str;
    vector<int> ans;
    stack<int> s;
    for (auto &i : str)
    {
        if (i == 'L')
        {
            s.push(dq.front());
            dq.pop_front();
        }
        else
        {
            s.push(dq.back());
            dq.pop_back();
        }
    }
    int p = 1;
    while (!s.empty())
    {
        p *= s.top();
        s.pop();
        p %= m;
        ans.push_back(p);
    }
    reverse(ans.begin(), ans.end());
    for (auto &i : ans)
    {
        cout << i << ' ';
    }

    cout << '\n';
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
