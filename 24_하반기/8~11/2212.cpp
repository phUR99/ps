#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
vector<int> arr;
/*
1. 값의 상한선은 얼마일까?
하나도 선택하지 않은 경우 정렬했을 때의 값의 차이.
2. 구간을 자를 때 구간의 위치가 중요한가?
중요하지 않음, 중요한 것은 차이임(1 ~ 9나 10~ 19나 다루는 방식이 동일함)
3. 구간의 차이만 알고 있을 때 구간을 적절히 잘라서 K개의 구간을 만들었을 때, 어떤 구간을 잘라야 할까?
큰 구간부터 잘라야함
작은 구간을 선택한 경우 - 그 부분을 큰 구간으로 대체했을 때 손해가 없기 때문임
A: 구간의 차이를 내림차순으로 정렬한 뒤에, k-1개만큼 상한값에서 빼준다.
*/

int main()
{
    fastio;
    cin >> n >> k;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int total = arr.back() - arr.front();
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    priority_queue<int> pq;
    for (int i = 1; i < arr.size(); i++)
    {
        pq.push(arr[i] - arr[i - 1]);
    }
    k--;
    while (!pq.empty() && k--)
    {
        total -= pq.top();
        pq.pop();
    }
    cout << total;
    return 0;
}