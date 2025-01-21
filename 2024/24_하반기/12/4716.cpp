#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
idea : da, db의 값이 비슷할 경우
뭘 선택해도 별 상관이 없음(우선순위가 낮음)
-> 먼저 차이가 큰 값부터 결정하자
1. 탐욕적 선택 증명
가장 차이가 큰 값이 맨 앞이 아니라 뒤에 있는 경우의 최적해
맨 앞의 값이랑 교체를 했을 때 손해를 볼 일이 없음(a, b의 양이 부족해서 비효율적인 선택할 가능성이 낮아짐)
2. 최적 부분 구조
그 다음 문제도 차이가 큰 값을 선택하는 것이 유리함
*/

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return abs(a[1] - a[2]) > abs(b[1] - b[2]);
}

void solve(int n, int a, int b)
{
    vector<array<int, 3>> arr(n);
    for (auto &i : arr)
    {
        cin >> i[0] >> i[1] >> i[2];
    }
    sort(arr.begin(), arr.end(), cmp);
    int ret = 0;
    for (auto &i : arr)
    {
        int amount = i[0];
        int aCost = i[1];
        int bCost = i[2];
        if (aCost < bCost)
        {
            if (amount > a)
            {
                amount -= a;
                ret += a * aCost;
                ret += amount * bCost;
                a = 0;
            }
            else
            {
                a -= amount;
                ret += amount * aCost;
            }
        }
        else
        {
            if (amount > b)
            {
                amount -= b;
                ret += b * bCost;
                ret += amount * aCost;
                b = 0;
            }
            else
            {
                b -= amount;
                ret += amount * bCost;
            }
        }
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    while (1)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0)
            break;
        solve(n, a, b);
    }

    return 0;
}