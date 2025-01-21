#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> arr;
int n;
/*
1. LIS 문제인줄 알고 LIS의 길이를 구했지만 동일 길이의 LIS가 2개 이상 등장할 경우 문제가 생김
2. 규칙 찾기
왼쪽으로 정렬되었을 때의 규칙 파악하기
좌측으로 밀려나는 원소는 많이 이동해도 항상 한번임
우측으로 옮겨나는 원소는 규칙을 파악하기 어러움
-> 정렬한 배열의 인덱스의 차

*/

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, arr[i].second - i);
    }
    cout << ret + 1;
    return 0;
}