#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
ABC...일 경우
AB를 지웠을 때 C가 남고, 이 C는 지울 방법이 없다.
BC를 지웠을 때 A가 남고, 이 A는 뒤의 문자열을 확인했을 때 지울 수도 있다.
따라서, BC를 지우고, 남은 B로 A를 지우는 것이 손해를 보지 않는다(탐욕적 선택 속성 증명).
그리고, 한 문자열을 지우고 남은 문자열 역시 동일하게 지우는 것이 최적이다.(최적 부분 구조 증명1)
*/
string str;
int main()
{
    fastio;
    cin >> str;
    int n = str.size();
    queue<int> q;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'B')
            q.push(i);
        if (str[i] == 'C' && !q.empty())
        {
            int x = q.front();
            q.pop();
            str[x] = 'C';
            ret++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A')
            cnt++;
        if (str[i] == 'B' && cnt)
        {
            cnt--;
            ret++;
        }
    }
    cout << ret;

    return 0;
}