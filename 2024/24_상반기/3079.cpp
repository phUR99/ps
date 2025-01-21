#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
long long T[100005];

int main(){
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }
    sort(T, T + N);
    //ed이 생각보다 더 커질수 있다는 것을 생각하기
    long long st = 1, ed = T[N-1] * M;
    long long ans;

    while (st <= ed)
    {
        long long mid = (st + ed) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += mid / T[i];
            //오버플로우 주의
            if(sum > M) break;
        }
        if(sum >= M){
            ed = mid - 1;
            ans = mid;
        }
        else{
            st = mid + 1;
        }
    }
    cout << ans;
    

    return 0;
}