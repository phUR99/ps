#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll arr[100005];

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // accumulate는 입력 자료구조의 자료형에 따라 반환 타입 결정
    ll sum = accumulate(arr, arr + n, -arr[n - 1]);
    int M = arr[n - 1];
    // M이 sum보다 크면 남을 수밖에 없음
    if (M > sum)
        cout << M - sum;
    else if (M == sum)
        cout << 0;
    /*
        전체 합이 홀수일 경우
        2개를 적당히 깎아서 비슷하게 만드는 것을 가정
    */
    else
        cout << ((M + sum) % 2 ? 1 : 0);
    return 0;
}