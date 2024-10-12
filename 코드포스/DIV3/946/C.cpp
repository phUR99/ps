#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
중복되는 항은 중복되는 항이 동일할 때는 세면 안되지만, 다른 원소가 나올 때는 세줘야함
이걸 어떻게 처리?
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<tuple<int, int, int>, int> triplet_count;
    map<tuple<int, int, int>, map<int, int>> cnt;
    long long answer = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int a1 = arr[i - 1];
        int a2 = arr[i];
        int a3 = arr[i + 1];
        triplet_count[{a1, a2, 0}]++;
        triplet_count[{a1, 0, a3}]++;
        triplet_count[{0, a2, a3}]++;
        cnt[{a1, a2, 0}][a3]++;
        cnt[{a1, 0, a3}][a2]++;
        cnt[{0, a2, a3}][a1]++;

        answer += triplet_count[{a1, a2, 0}] - cnt[{a1, a2, 0}][a3];
        answer += triplet_count[{a1, 0, a3}] - cnt[{a1, 0, a3}][a2];
        answer += triplet_count[{0, a2, a3}] - cnt[{0, a2, a3}][a1];
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
