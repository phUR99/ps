#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

int main()
{
    fastio;
    // 전체 집합 구하기
    int full_bit = (1 << n) - 1;
    // 원소 추가
    int add = 0, p;
    add |= (1 << p);
    // 원소의 포함 여부 확인하기
    if (add & (1 << p))
        cout << 1;
    // 원소 삭제
    int del = (1 << n) - 1;
    del &= ~(1 << p);
    // 원소의 토글
    add ^= (1 << p);
    int a, b;
    int added = a | b;             // 합집합
    int intersection = (a & b);    // 교집합
    int removed = (a & ~b);        // 차집합
    int toggled = (a ^ b);         // 하나의 집합에만 포함된 원소들의 집합
    cout << __builtin_popcount(a); // a의 원소의 개수(unsigned int로만 가능함)
    cout << __builtin_ctz(a);      // 최소 원소 찾기, 0이 주어졌을 때의 결과가 정의되어있지 않음
    cout << (a & -a);              // 최하위 원소 비트의 값을 직접 구하기
    a &= (a - 1);                  // 최소 원소 지우기
    // 모든 부분집합 순회하기
    for (int subset = full_bit; subset; subset = ((subset - 1) & full_bit))
    {
    }

    return 0;
}