#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n;
#define MAXP 1000000
/*
약수가 3개?
-> 제곱수 + 수의 제곱근이 소수
-> 소수 판정하기(쿼리 여러번 -> 1e6까지의 에라스토테네스의 체 구현)
*/

bool isPrime[MAXP + 1];
void checkPrime()
{
    memset(isPrime, true, MAXP);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(MAXP) + 1; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * 2; j <= MAXP; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    checkPrime();
    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;
        long long square = sqrt(cur);
        if (cur != square * square)
        {
            cout << "NO\n";
            continue;
        }
        if (isPrime[square])
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
