#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
탐욕적 선택 속성 증명 :
L-1보다 적게 선택했을 때의 최적해가 존재한다고 가정 -> 이 해의 부분을 L-1로 교체했을 때
손해를 항상 보지 않음
최적 부분 구조
다음 문제 역시 L-1만큼 덮을 것이므로 만족함

*/
int main()
{
    fastio;

    int n, l;
    cin >> n >> l;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < v.size();)
    {
        count++;
        int tape = v[i] + l - 1;
        while (i < v.size() && v[i] <= tape)
        {
            i++;
        }
    }
    cout << count << endl;
}