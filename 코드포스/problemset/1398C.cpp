#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve();
/*
조합론의 아이디어
pSum[j] - pSum[i-1] = j - (i-1);
pSum[j] - r = pSum[i-1] - (i-1);
pSum을 구하되 구한 pSum에 i를 빼서 같은 값을 가지는 원소의 조합을 구하기
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> pSum(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        sum += c - '0';
        pSum[i] = sum;
    }
    map<int, long long> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cnt[pSum[i] - (i + 1)]++;
    }
    long long answer = 0;
    for (auto &iter : cnt)
    {
        answer += iter.second * (iter.second - 1) / 2;
    }
    cout << answer << '\n';
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
