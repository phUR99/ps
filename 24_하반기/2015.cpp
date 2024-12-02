#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[200005];
int prefix[200005];
/*
정렬이 안되어있기 때문에 투포인터로는 해결할 수 없음
누적합의 차가 K를 만족하는 경우 찾기
누적합으로 가능한 원소의 등장 횟수를 전부 세는 방식으로 할 수 있지만,
인덱스에 관한 정보가 필요함
O(n^2) 풀이에서
계속해서 오른쪽으로 쓸어가면서 만족하는 값을 반복하는 것을 해결하기 위해서
전부 기록해놓고 현재 인덱스까지의 값을 빼는 방식으로 해결하기
*/
int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    map<int, ll> cnt;
    long long ret = 0;
    for (int i = n; i >= 0; i--)
    {
        cnt[prefix[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        cnt[prefix[i]]--;
        ret += cnt[k + prefix[i]];
    }
    cout << ret;

    return 0;
}