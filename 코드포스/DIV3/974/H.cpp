#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int cnt[1000005];
int K = 500;
/*
보안관이 이길 수 있는 경우가 있는가? 없음
짝수일 경우
a1, a2, a3.... an으로 뽑았다고 할 때
a1 >=a2, a3 >=a4....이므로 항상 홀수번째의 합은 짝수번째의 합보다 큼

홀수일 경우
an+1까지 있으므로 절대로 이길수 없음
따라서 보안관이 지지 않는 유일한 방법은 비기는 거임

비기는 방법?
짝수일 경우
a1 = a2, a3 = a4, a5 = a6...의 조건을 만족하면 됨
구간에서의 수의 등장 빈도를 세고, 짝수가 아닌 수의 등장 빈도가 존재하는지를 세면 됨
-> mo's algorithm 활용하기
k를 500으로 설정

초기화 설정
l =0, r =0 (0번 idx만 선택되어있다고 가정)
*/

bool cmp(vector<int> &a, vector<int> &b)
{
    // 2개의 항을 동시에 비교하는 방법 1(현재는 오름차순)
    return make_pair(a[0] / K, a[1]) < make_pair(b[0] / K, b[1]);
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), ret(q, 0);
    for (auto &i : arr)
    {
        cin >> i;
    }
    vector<vector<int>> query(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), cmp);
    int l = 0, r = 0;
    int odd = 1;
    cnt[arr.front()]++;
    for (auto &c : query)
    {
        c[0]--, c[1]--;
        // 더하는 경우
        while (r < c[1])
        {
            cnt[arr[++r]]++;
            if (cnt[arr[r]] % 2)
                odd++;
            else
                odd--;
        }
        while (l > c[0])
        {
            cnt[arr[--l]]++;
            if (cnt[arr[l]] % 2)
                odd++;
            else
                odd--;
        }
        // 제거하는 경우
        while (l < c[0])
        {
            cnt[arr[l]]--;
            if (cnt[arr[l++]] % 2)
                odd++;
            else
                odd--;
        }
        while (r > c[1])
        {
            cnt[arr[r]]--;
            if (cnt[arr[r--]] % 2)
                odd++;
            else
                odd--;
        }
        ret[c[2]] = odd;
    }
    for (auto &i : ret)
    {
        if (i)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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
