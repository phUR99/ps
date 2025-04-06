#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll s;
/*
n1 + n2 + n3…. nN = N
N = s(s+1)/2 + p 
탐욕적 선택 속성: 제일 작은 숫자부터 선택하는 것이 최적의 해를 보장한다.
제일 작은 숫자를 집어넣지 않았을 때의 해를 가정해보자.
2 + 3 + 4 + 5 …. = N
이 때 각 숫자의 총 길이를 l이라 하고, 각 숫자에서 1씩 빼보자. 
1 + 2 + 3 + 4 + 5. … l = N 
이 때 l이 기존 값이 포함된다면 제일 마지막 값에 l을 더하면 동일한 길이의 수열을 보장하고, l이 기존 값에 포함되지 않을 경우에는 l을 마지막 원소로 포함하면 되므로
더 적은 숫자를 집어넣는 해가 기존 해에 비해 손해가 없음을 증명할 수 있다.
최적 부분 구조:  제일 작은 숫자를 선택하고 문제의 정의에서 탐욕적 선택 속성을 증명하자.
1 + n1 + n2  + n3…… = N일 때의 부분 문제의 정의를 구해보자
가장 긴 길이값을  갖는 N을 구하는 것이므로 문제의 정의와 동일함을 증명할 수 있다.
*/
int main()
{
    fastio;
    cin >> s;
    for (ll i = 1;; i++)
    {
        if(i*(i+1)/2 > s){
            cout << i-1;
            return 0;
        }
    }
    
    return 0;
}