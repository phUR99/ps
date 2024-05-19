#include <bits/stdc++.h>
using namespace std;
/*
1. 원형의 자료구조 -> 큐를 활용할 수도 있지만, 큐보다는 배열 + 활용해서 작성하는게 간단(배열 + 추가 배열)
2. 전부 확인할 경우 9e9로 시간 초과 -> 전부 확인하지 않고 정보를 저장하다가 갱신하기(슬라이딩 윈도우)
3. C의 처리 -> 개수를 모아두는 kind 배열에 미리 +1을 해둘 경우 c를 경우마다 처리할 필요가 없어진다.
*/

int N, d, k, c;
int arr[3000000 + 3000 + 50];
int kind[3050];
int sum = 1, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> N >> d >> k >> c;
    kind[c]++;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = N; i < N + k; i++)
    {
        arr[i] = arr[i-N];
    }
    for (int i = 0; i < k; i++)
    {
        if (kind[arr[i]] == 0) {
            sum++;
        }
        kind[arr[i]]++;
    }
    ans = max(ans, sum);

    for (int i = k; i < N+k; i++)
    {
        if (kind[arr[i]] == 0) sum++;            
        kind[arr[i]]++;
        int end = i - k;
        kind[arr[end]]--;
        if(kind[arr[end]] == 0) sum--;
        ans = max(ans, sum);
    }
    cout << ans;
    

    


    return 0;
}