#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
가격이 같은 고기는 사야한다
가격의 오름차순, 무게의 내림차순으로 정렬
이후 고기의 무게를 더해보면서 무게가 이전 가격이랑 같다면 가격을 더해주고
이전 가격이랑 같지 않다면 바꿔줌
무게가 m보다 크거나 같아졌을 때 다른 고기를 고르는 것이 더 유리할 경우 이를 선택
*/
vector<pair<int, int>> arr;
int n, m;
int main()
{
    fastio;
    cin >> n >> m;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i.second >> i.first;
        i.second = -i.second;
    }
    sort(arr.begin(), arr.end());
    int weight = 0;
    int sum = 0;
    int before = -1;
    for (int i = 0; i < n; i++)
    {
        if (weight < m)
        {
            if (before == arr[i].first)
                sum += arr[i].first;
            else
                before = sum = arr[i].first;
        }
        else
        {
            if ((before != arr[i].first) && (arr[i].first <= sum))
            {
                before = sum = arr[i].first;
            }
        }
        weight += -arr[i].second;
    }
    if (weight < m)
        cout << -1;
    else
        cout << sum;

    return 0;
}