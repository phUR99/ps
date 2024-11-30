#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
/*
경우 3가지일 때 최적해 반환
1. 오른쪽 끝에 벌통이 있을 때
2. 왼쪽 끝에 벌통이 있을 때
3. 중간에 벌통이 있고 벌은 양쪽 끝에서 시작할 때
왜 양쪽 끝에 있을 때만 최적의 해가 보장이 될까?
탐욕적 선택 증명:
벌통이 끝이 아닐 때 최적해가 존재한다고 가정하기
벌통을 끝쪽으로 한칸 더 옮겨도 손해는 보지 않음(벌통이 항상 양수이기 때문에)
벌집이 끝이 아닐 때 최적해가 존재한다고 가정하기
벌집을 끝쪽으로 한칸 더 옮겨도 손해는 보지 않음(벌통이 항상 양수이기 때문에)

*/

int solve(vector<int> &arr)
{
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        prefix[i] = (i == 0) ? arr[i] : prefix[i - 1] + arr[i];
    }
    int ret = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ret = max(ret, prefix[n - 1] - prefix[0] + prefix[n - 1] - prefix[i] - arr[i]);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(arr);
    vector<int> prefix(n), r_prefix(n);
    for (int i = 0; i < n; i++)
    {
        prefix[i] = (i == 0) ? 0 : prefix[i - 1] + arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        r_prefix[i] = (i == n - 1) ? 0 : r_prefix[i + 1] + arr[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        ret = max(ret, prefix[i] + r_prefix[i]);
    }
    reverse(arr.begin(), arr.end());
    ret = max(ret, solve(arr));
    cout << ret;
    return 0;
}