#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
stack<int> s;
int arr[1000005], freq[1000005];
int n;
/*
n^2 풀이
등장 빈도를 전부 센 다음, 오른쪽을 계속 확인하면서 큰 숫자가 있으면 종료
n이 1e6이므로 이 풀이는 불가능하다
-> 안봐도 괜찮은 지점이 존재하는데 계속 봐야하는 문제
-> 후보들만 집어넣고 확인하는 방법
-> 스택을 사용해서 이전에 사용했거나, 사용한 값들만 보관(모노톤 스택 형태로 보관될거임)
스택의 원소들을 확인하면서 가능한 원소 탐색
스택이 비었을 경우 -1
*/

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    stack<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && freq[s.top()] <= freq[arr[i]])
        {
            s.pop();
        }
        if (s.empty())
            ans.push(-1);
        else
            ans.push(s.top());
        s.push(arr[i]);
    }
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}