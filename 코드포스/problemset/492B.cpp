#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    int len = arr.size();
    double diff = 0;
    for (int i = 1; i < len; i++)
    {
        diff = max(diff, (double)(arr[i] - arr[i - 1]) / 2);
    }
    // 양 끝에 대한 처리는 예외로 빼기
    diff = max(diff, (double)(arr.front() - 0));
    diff = max(diff, (double)l - arr.back());

    cout.precision(10);
    cout << fixed << (double)diff;
}

int main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
