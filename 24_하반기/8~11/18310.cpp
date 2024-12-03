#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
/*
왜 중간값일까?
최적의 해가 중간값이 아닐 때
1) 더 오른쪽일 경우 왼쪽에서 추가되는 값이 중간값보다 큼
2) 더 왼쪽일 경우 오른쪽에서 추가되는 값이 중간값보다 큼
따라서 중간값이 최적해임
더 작은 값을 뽑기 위해서 짝수일 때 (n-1)/2로 더 작은값을 찾음
*/
int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    cout << arr[(n - 1) / 2];

    return 0;
}