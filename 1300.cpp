#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
1. 이분탐색이라고 생각은 했지만 다른 길로 빠져버림..
차라리 좀 큰 사이즈를 집어넣어서 배열을 확인해보자..
2. 체계적으로 찾는 아이디어.. 뭘 해도 반복문 안에서 찾을 수 밖에 없음..
3. 숫자가 클 수록 나머지와 나눗셈을 잘 사용하자.
*/
long long N, K;
long long count(long long x){
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += min(x/i, N);
    }
    return sum;    
}

int main(){
    fastio;
    cin >> N >> K;
    long long low = 1;
    long long high = N * N;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long cnt = count(mid);
        if(cnt >= K) high = mid - 1;
        else low = mid + 1;
    }
    cout << low;    



    return 0;
}